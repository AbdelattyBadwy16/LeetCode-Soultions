class Solution {
public:
    vector<vector<int>>dp;
    int nn;
    int DP(int i,int rem ){
        if(rem==0)return 0;
        int &ret = dp[i][rem];
        if(~ret)return ret;
        int ans = 20000;
        if(rem - i >=0)ans = DP(i,rem-i) + 1;
        if(rem  - (nn -rem)>=0)ans = min(ans,DP(nn-rem,rem - (nn-rem))+ 2);
        return ret = ans;
    }
    int minSteps(int n) {
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        nn = n;
        return DP(1,n-1) + (nn-1!=0 ? 1 : 0) ;
    }
};