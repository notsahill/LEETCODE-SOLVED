class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int,int>>> adj(n);//adj[src]={{dest1,cost1},{dest2,cost2}};
        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        queue<pair<int,int>> q;//{node,costToReachThisNode}
        q.push({src,0});
        int mn;
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(q.size() and k>=0){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int node=q.front().first;
                int costUptoNode=q.front().second;
                q.pop();
                for(auto dst:adj[node]){
                    int cost=dst.second;
                    int nbr=dst.first;
                    if(cost+costUptoNode<dist[nbr]){
                        dist[nbr]=costUptoNode+cost;
                        q.push({nbr,costUptoNode+cost});
                    }
                }
            }
            k--;
        }
        mn=dist[dest];
        return mn==1e9?-1:mn;
    }
};