class Solution {
public:
    int cnt = 0;
    int dp[25][2000+5];
    int trace(int i,int sum,vector<int>&nums,int target){
        if(i==nums.size()){
            return sum == target;
        }
        int &ret = dp[i][sum + 1000];
        if(~ret)return ret;
        return ret = trace(i+1,sum+nums[i],nums,target) + trace(i+1,sum-nums[i],nums,target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof dp);
        return trace(0,0,nums,target);
    }
};
