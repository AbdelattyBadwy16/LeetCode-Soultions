class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>v;
        for(auto s:timePoints){
            int h = s[0]-'0',m = s[3]-'0';
            h = (h*10) + s[1]-'0';
            m = (m*10) + s[4]-'0';
            m += (h*60);
            v.push_back(m);
        }
        sort(v.begin(),v.end());
        int ans = 9999;
        for(int i=1 ; i<v.size() ; i++){
            ans = min(ans,v[i]-v[i-1]);
            ans = min(ans,(24*60)-v[i] + v[0]);
        }
        return ans;
    }
};