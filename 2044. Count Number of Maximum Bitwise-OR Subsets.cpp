class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mxOr = 0;
        for(auto it:nums)mxOr |= it;
        int n = nums.size() , ans = 0;
        for(int i=1 ; i<(1<<n) ; i++){
            int orRes = 0;
            for(int j=0 ; j<n ; j++){
                if(i & (1<<j)){
                    orRes |= nums[j];
                }
            }
            if(orRes == mxOr)ans++;
        }
        return ans;
    }
};
