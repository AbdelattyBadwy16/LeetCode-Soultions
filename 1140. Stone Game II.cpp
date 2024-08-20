class Solution {
public:
    int dp[150][250][2];
    int n;
    int solve(int i,int m ,int turn ,vector<int>&p){\
        if(i>=n)return 0;
        int &ret = dp[i][m][turn];
        if(~ret)return ret;
        int ans = (turn==0?INT_MAX : 0),sum=0;
        int cnt  =0;
        for(int j=i ; j<min(i+2*m,n) ; j++){
            sum += p[j];
            cnt++;
            // cout<<i<<" "<<j<<endl;
            if(turn){
                ans = max(ans,solve(j+1,max(m,cnt),turn^1,p)+sum);
            }else ans = min(ans,solve(j+1,max(m,cnt),turn^1,p));
        }
        return ret = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof dp);
        return solve(0,1,1,piles);
    }
};