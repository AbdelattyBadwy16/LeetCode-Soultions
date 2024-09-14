class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0,len = 0;
        bool lst = 0;
        int ans = 0;
        for(auto it:nums){
            if(it>mx)mx = it,len = 1,lst = 1;
            else if(it==mx && lst)len++;
            else if(it==mx)ans = max(ans,len),len = 1,lst = 1;
            else lst = 0;
        }
        ans = max(ans,len);
        cout<<mx<<endl;
        return ans;
    }
};