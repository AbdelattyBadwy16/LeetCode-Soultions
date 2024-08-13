class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int,int> mp;
    void help(vector<int> &cur, int target, int prev) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        for(int i=prev;i<=target;i++) {
            if(mp[i] > 0) {
                mp[i]--;
                cur.push_back(i);
                help(cur,target-i,i);
                mp[i]++;
                cur.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        mp.clear();
        vector<int> cur;
        for(auto &it : candidates) mp[it]++;
        help(cur,target,1);
        return ans;
    }
};