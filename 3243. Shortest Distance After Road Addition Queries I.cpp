class Solution {
public:
    vector<vector<int>>adj;
    vector<int>dist;
    void dfs(int u,vector<vector<int>>& adj , int c = 0){
        for(auto v:adj[u]){
            if(dist[v]<=c)continue;
            dist[v] = c;
            dfs(v,adj,c+1);
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        adj = vector<vector<int>>(n);
        for(int i=0 ; i<n-1 ; i++){
            adj[i].push_back(i+1);
        }
        vector<int>ans;
        for(auto it:queries){
            adj[it[0]].push_back(it[1]);
            dist = vector<int>(n,1e5);
            dfs(0,adj);
            ans.push_back(dist[n-1]+1);
        }
        return ans;
    }
};
