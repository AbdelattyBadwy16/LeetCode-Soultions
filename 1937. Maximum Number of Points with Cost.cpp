class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for(int i=0 ; i<m ; i++){
            dp[0][i] = points[0][i];
        }
        for(int i=1 ; i<n ; i++){
            vector<long long> l(m, 0), r(m, 0);
            r[m-1]=dp[i-1][m-1];
             for (int j=m-2; j >= 0; j--)
                r[j] = max(r[j+1]-1, dp[i-1][j]);
            l[0]=dp[i-1][0];
            dp[i][0]=max(l[0], r[0])+points[i][0];
            for(int j=1 ; j<m ; j++){
                l[j]=max(l[j-1]-1, dp[i-1][j]);
                dp[i][j] = max(l[j], r[j])+points[i][j];
            }
        }
        return *max_element(dp[n-1].begin() , dp[n-1].end());
    }
};