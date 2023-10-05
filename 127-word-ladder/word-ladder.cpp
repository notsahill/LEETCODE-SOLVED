class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(q.size())
        {
            string curr=q.front().first;
            int move=q.front().second;
            // if(curr==endWord) return move;
            q.pop();
            for(int i=0;i<curr.size();i++)
            {
                string temp=curr;
                for(int j=0;j<26;j++)
                {
                    if(curr[i]=='a'+j) continue;
                    temp[i]='a'+j;
                    if(words.count(temp))
                    {
                        if(temp==endWord) return move+1;
                        q.push({temp,move+1});
                        words.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};