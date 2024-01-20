class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int MOD=1e9+7;
        vector<int> left(n),right(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(s.size() and arr[s.top()]>=arr[i]) s.pop();
            if(s.size()) left[i]=s.top();
            else left[i]=-1;
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(s.size() and arr[s.top()]>arr[i]) s.pop();
            if(s.size()) right[i]=s.top();
            else right[i]=n;
            
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            long long l=(i-left[i]),r=(right[i]-i),t=l*r;
            long long s=t*arr[i];
            ans= (ans+s)%MOD;
        }
        return ans;
    }
};