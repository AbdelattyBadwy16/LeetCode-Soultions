class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>team(n,0);
        for(auto it: edges){
            team[it[1]]++;
        }
        int ans = -1;
        for(int i=0 ; i<n ; i++){
            if(!team[i] && ~ans)return -1;
            if(!team[i])ans = i;
        }
        return ans;
    }
};
