class Solution {
public:
    map<string,int>mp;
    int n;
    vector<vector<int>>dp;
    int getMin(int l,int r,string t,string& s){
        if(r==n)return t.size();
        int &ret = dp[l][r];
        if(~ret)return ret;
        int ans = getMin(r+1,r+1,"",s) + (r-l+1);
        t+=s[r];
        ans = min(ans,getMin(l,r+1,t,s));
        if(mp[t]) ans = min(ans,getMin(r+1,r+1,"",s));
        return ret = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        for(auto it:dictionary)mp[it]=1;
        return getMin(0,0,"",s);
    }
};
