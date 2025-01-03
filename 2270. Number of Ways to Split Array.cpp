class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long pref[n],suf[n];
        for(int i=0 ; i<n ; i++){
            pref[i] = nums[i];
            if(i)pref[i] += pref[i-1];
        }
        for(int i=n-1 ; i>=0 ;i--){
            suf[i] = nums[i];
            if(i!=n-1)suf[i] += suf[i+1];
        }
        int ans = 0;
        for(int i=0 ; i<n-1 ; i++){
            if(pref[i]>=suf[i+1])ans++;
        }
        return ans;
    }
};
