class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0 ; i<n ; i++){
            mp[nums[i]] = i;
        }
        vector<int>dp(n,0);
        for(int i=0 ;i<n ; i++){
            long long nxt = 1LL * nums[i] * nums[i],lst = i;
            dp[i] = max(dp[i],1);
            while(true){
                if(nxt > 1e6 || !mp.count(nxt))break;
                dp[mp[nxt]] = max(dp[lst] + 1,dp[mp[nxt]]);
                lst = mp[nxt];
                nxt *= nxt;
            }
        }
        int mx = *max_element(dp.begin(),dp.end());
        return mx == 1?-1 : mx;
    }
};
