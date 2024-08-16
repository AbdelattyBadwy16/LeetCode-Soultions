class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mn = INT_MAX;
        int mx = INT_MIN;
        int mnIdx = -1;
        int mxIdx = -1;
        for(int i=0 ;i<arrays.size() ; i++){
            if(mn>arrays[i][0]){
                mn = arrays[i][0];
                mnIdx = i;
            }
            if(mx<arrays[i][arrays[i].size()-1]){
                mx = arrays[i][arrays[i].size()-1];
                mxIdx = i;
            }
        }
        for(int i=0 ;i<arrays.size() ; i++){
            if(i!=mnIdx){
                ans = max(ans,arrays[i][arrays[i].size()-1] - mn);
            }
            if(i!=mxIdx){
                ans = max(ans,mx - arrays[i][0]);
            }
        }
        return ans;
    }
};