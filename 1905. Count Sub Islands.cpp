class Solution {
public:
    int n,m;
    bool vaild(int i,int j){
        if(i>=0 && j>=0 && i<n && j<m)return 1;
        else return 0;
    }
    bool vis[504][504];
    int cnt=0;
    bool dfs(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2)
    {
        vis[i][j]=1;
        int ans1=0,ans2=0,ans3=0,ans4=0;
        if(vaild(i+1,j) && !vis[i+1][j] && grid1[i+1][j]==grid2[i+1][j] && grid2[i+1][j]){
            cnt++;
            ans1=dfs(i+1,j,grid1,grid2);
        }else if(vaild(i+1,j) && grid1[i+1][j]!=grid2[i+1][j] && grid2[i+1][j]) ans1=1;
        if(vaild(i-1,j) && !vis[i-1][j] && grid1[i-1][j]==grid2[i-1][j] && grid2[i-1][j]){
            cnt++;
            ans2=dfs(i-1,j,grid1,grid2);
        }else if(vaild(i-1,j)&& grid1[i-1][j]!=grid2[i-1][j] && grid2[i-1][j]) ans2= 1;
        if(vaild(i,j+1) && !vis[i][j+1] && grid1[i][j+1]==grid2[i][j+1] && grid2[i][j+1]){
            cnt++;
            ans3=dfs(i,j+1,grid1,grid2);
        }else if(vaild(i,j+1)&&grid1[i][j+1]!=grid2[i][j+1] && grid2[i][j+1]) ans3= 1;
        if(vaild(i,j-1) && !vis[i][j-1] && grid1[i][j-1]==grid2[i][j-1] && grid2[i][j-1]){
            cnt++;
            ans4=dfs(i,j-1,grid1,grid2);
        }else if(vaild(i,j-1)&&grid1[i][j-1]!=grid2[i][j-1] && grid2[i][j-1]) ans4= 1;

        return ans1+ans2+ans3+ans4;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid1[i][j]==grid2[i][j] && grid2[i][j] && !vis[i][j]){
                    if(!dfs(i,j,grid1,grid2))ans++;
                }
            }
        }
        return ans;
    }
};