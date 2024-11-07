class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>bits(32,0);
        int ans = 0;
        for(auto c:candidates){
            for(int i=0 ; i<32 ; i++){
                if(c & (1<<i))bits[i]++,ans = max(ans,bits[i]);
            }
        }
        return ans;
    }
};
