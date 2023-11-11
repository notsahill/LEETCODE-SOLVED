class Graph {
public:
    vector<pair<int,int>> adj[101];
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        for(auto edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int curr_node, int target_node) {
        vector<int> dp (N,INT_MAX);
        dp[curr_node]=0;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,curr_node});

        while(!pq.empty()){
            int curr = pq.top().second;
            int cost_till_curr = pq.top().first;
            pq.pop();
            
            if(curr==target_node){
                return cost_till_curr;
            }

            for(auto item: adj[curr]){
                int next = item.first;
                int cost_to_next = item.second;
                if(cost_till_curr+cost_to_next<dp[next]){
                    dp[next] = cost_till_curr+cost_to_next;
                    pq.push({dp[next],next});
                }
            }

        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */