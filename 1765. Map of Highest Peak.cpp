class Solution {
public:
    bool check(int i,int j ,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m)return 1;
        return 0;
    }
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    vector<vector<int>> assignHeight(vector<vector<int>>& isWater){
        int n = isWater.size() , m = isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ;j++){
                if(!isWater[i][j])continue;
                pq.push({0,{i,j}});
            }
        }
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int h = pq.top().first + 1;
            pq.pop();
            for(int i=0 ; i<4 ; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(check(newX,newY,n,m) && !isWater[newX][newY] && (ans[newX][newY]>h || ans[newX][newY] == 0)){
                    ans[newX][newY] = h;
                    pq.push({h,{newX,newY}});
                }
            }
        }

        return ans;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        return assignHeight(isWater);
    }
};
