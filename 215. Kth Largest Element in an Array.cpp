class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>v(2e4+10,0);
        for(auto it:nums){
            v[it+1e4]++;
        }
        for(int i=2e4 ; i>=0 ; i--){
            if(k-v[i]>0)k-=v[i];
            else{
                return i - 1e4;
            }
        }

        return 0;
    }
};
