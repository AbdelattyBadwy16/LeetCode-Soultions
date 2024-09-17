class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mp;
        string t = "";
        for(auto it:s1){
            if(it==32){
                mp[t]++;
                t = "";
            }else t+=it;
        }
        mp[t]++;
        t = "";
        for(auto it:s2){
            if(it==32){
                mp[t]++;
                t = "";
            }else t+=it;
        }
        mp[t]++;
        vector<string> ans;
        for(auto it:mp){
            if(it.second==1)ans.push_back(it.first);
        }
        return ans;
    }
};
