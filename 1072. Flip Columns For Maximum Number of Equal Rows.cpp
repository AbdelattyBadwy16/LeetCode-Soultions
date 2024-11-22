class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        map<vector<int>,int>mp;
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            vector<int>a,b;
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j]==0)a.push_back(j);
                else b.push_back(j);
            }
            mp[a]++;
            mp[b]++;
            ans = max({ans,mp[a],mp[b]});
        }
        return ans;
    }
};
