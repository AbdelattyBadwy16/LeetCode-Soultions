class Solution {
public:
    int MaxXor(int n,int mxBit){
        int ret = 0;
        for(int i=0 ; i<mxBit ; i++){
            if(n & (1<<i))continue;
            ret |= (1<<i);
        }
        return ret;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int Xor = 0;
        for(auto n:nums)Xor ^= n;
        vector<int>ans;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            ans.push_back(MaxXor(Xor,maximumBit));
            Xor ^= nums[i];
        }
        return ans;
    }
};
