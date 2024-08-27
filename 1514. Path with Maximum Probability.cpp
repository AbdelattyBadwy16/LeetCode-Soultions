class Solution {
public:
    vector<vector<pair<int,double>>>adj;
    vector<double>cost;
    double dijkstra(int src,int dist)
    {
        priority_queue<pair<double,int>,vector<pair<double,int>>>pq;
        for(auto it:adj[src])
        {
            pq.push({it.second,it.first});
            cost[it.first]=it.second;
        }
        while(!pq.empty())
        {
            double p=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(cost[u]>p)continue;
            cost[u]=p;
            for(auto it:adj[u])
            {
                if(cost[it.first]<p*it.second)
                    pq.push({p*it.second,it.first});
            }
        }
        return cost[dist];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int i=0;
        adj=vector<vector<pair<int,double>>>(10000+5);
        cost=vector<double>(10000+5,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],succProb[i]});
            adj[it[1]].push_back({it[0],succProb[i++]});
        }

        return dijkstra(start,end);
    }
};