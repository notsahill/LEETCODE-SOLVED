class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int total=tasks.size();
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        int ans=0;
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push(freq[i]);
        }
        while(pq.size()){
            int c=n+1;
            vector<int> temp;
            for(int i=0;i<c;i++){
                if(pq.size()){
                    int val=pq.top();
                    pq.pop();
                    temp.push_back(val-1);
                }
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]>0) pq.push(temp[i]);
            }
            if(!pq.size()) ans+=temp.size();
            else{
                ans+=c;
            }
            
        }
        return ans;
    }
};