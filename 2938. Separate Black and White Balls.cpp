class Solution {
public:
    long long minimumSteps(string s) {
        vector<int>v;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='0')v.push_back(i);
        }
        long long ans = 0;
        for(int i=0 ; i<v.size() ; i++){
            ans += abs(v[i] - i);
        }
        return ans;
    }
};
