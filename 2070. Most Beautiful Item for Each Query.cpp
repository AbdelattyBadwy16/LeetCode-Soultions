class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int>mp;
        vector<int>nums;
        for(auto it:items){
            mp[it[0]] = max(mp[it[0]],it[1]);
            nums.push_back(it[0]);
        }
        int lst = 0;
        for(auto it:mp){
            mp[it.first] = max(mp[it.first],mp[lst]);
            lst = it.first;
        }
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(auto q:queries){
            auto it = upper_bound(nums.begin(),nums.end(),q) - nums.begin();
            it--;
            if(it<0){
                ans.push_back(0);
                continue;
            }
            ans.push_back(mp[nums[it]]);
        }
        return ans;
    }
};
