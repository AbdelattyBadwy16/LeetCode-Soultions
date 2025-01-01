class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int n = values.size();
        values[n-1] = values[n-1] - (n-1);
        for(int i=n-2 ; i>=0 ; i--){
            ans = max(ans,values[i] + i + values[i+1]);
            values[i] = max(values[i+1],values[i] - i);
        }
        return ans;
    }
};
