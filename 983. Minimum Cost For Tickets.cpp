class Solution {
public:
    int dp[400][400];
    int solve(int i,int lst,vector<int>& days,vector<int>& costs){
        if(i>=days.size())return 0;
        int &ret = lst!=-1 ? dp[i][lst] : dp[i][399];
        if(~ret)return ret;
        if(days[i]<lst)return solve(i+1,lst,days,costs);
        int ans = solve(i+1,days[i]+1,days,costs) + costs[0];
        ans = min(ans,solve(i+1,days[i]+7,days,costs) + costs[1]);
        ans = min(ans,solve(i+1,days[i]+30,days,costs) + costs[2]);
        return ret = ans;
    }   
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof dp);
        return solve(0,-1,days,costs);
    }
};
