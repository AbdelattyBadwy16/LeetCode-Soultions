class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n,m;

    bool Check(int i,int j){
        if(i>=0 && j>=0 && i<n && j<m)return 1;
        return 0;
    }
    vector<vector<int>>temp;
    void dfs(int i,int j,int cnt){
        temp[i][j]=cnt;
        for(int w=0 ; w<4 ; w++){
            int x = i + dx[w];
            int y = j + dy[w];
            if(Check(x,y) && temp[x][y]==1)dfs(x,y,cnt);
        }
    }

    bool IsConnected(){
        int cnt = 1;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(temp[i][j]==1){
                    dfs(i,j,++cnt);
                }
            }
        }
        cnt--;
        return cnt<=1;
    }

    int minDays(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        n = grid.size();
        m = grid[0].size();
        temp = grid;
        int ones = 0;
        if(IsConnected()!=1){
            return 0;
        };
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]){
                    ones++;
                    for(int w=1 ; w<(1<<4) ; w++){
                        bitset<32>s(w);
                        temp = grid;
                        int cnt = 0;
                        for(int k=0 ; k<4 ; k++){
                            if(s[k]){
                                int x = i + dx[k];
                                int y = j + dy[k];
                                if(Check(x,y) && temp[x][y]){
                                    cnt++;
                                    temp[x][y]=0;
                                }
                            }
                        }
                        if(!IsConnected()){
                            ans = min(ans,cnt);
                        }
                    }
                }
            }
        }
        ans = min(ans,ones);
        return ans;
    }
};