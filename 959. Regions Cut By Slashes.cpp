class Solution {
public:
    void fill(vector<vector<int>>& v,vector<vector<int>> x,int index){
        for(int k=0;k<3;k++){
            v[index].push_back(x[0][k]);
            v[index+1].push_back(x[1][k]);
            v[index+2].push_back(x[2][k]);
        }
    }
    void dfs(vector<vector<int>>&v , int i,int j){
        vector<int> x={1,0,-1,0};
        vector<int> y={0,1,0,-1};
        v[i][j]=1;
        for(int k=0;k<4;k++){
            int i1=i+x[k];
            int j1=j+y[k];
            if(i1>=0 && j1>=0 && i1<v.size() && j1<v[0].size() && v[i1][j1]==0){
                dfs(v,i1,j1);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        for(auto it:grid){
            cout<<it<<endl;
        }
        int n=grid.size();
        vector<vector<int>> v(3*n);
        vector<vector<int>> e={{0,0,0},{0,0,0},{0,0,0}};
        vector<vector<int>> a={{1,0,0},{0,1,0},{0,0,1}};
        vector<vector<int>> b={{0,0,1},{0,1,0},{1,0,0}};
        int index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[i].size();j++){
                // cout<<grid[i][j];
                if(grid[i][j]==' ') fill(v,e,index);
                else if(grid[i][j]=='/') fill(v,b,index);
                else{
                    fill(v,a,index);
                }
            }
            index+=3;
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==0){
                    ans++;
                    dfs(v,i,j);
                }
            }
        }
        return ans;
    }
};