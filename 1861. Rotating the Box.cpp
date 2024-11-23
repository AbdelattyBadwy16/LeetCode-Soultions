class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size() , m = box[0].size();
        vector<vector<char>>ans(m,vector<char>(n));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                ans[j][n-i-1] = box[i][j];
            }
        }
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=0 ; j<n ; j++){
                if(ans[i][j]=='#'){
                    int ii = i;
                    ans[i][j] = '.';
                    while( ii<m && ans[ii][j]=='.'){
                        ii++;
                    }
                    if(ii)
                    ans[ii-1][j] = '#';
                }
            }
        }
        return ans;
    }
};
