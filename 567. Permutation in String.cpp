class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>f1(26,0),f2(26,0);
        if(s1.size()>s2.size())return false;
        for(auto c:s1)f1[c-'a']++;
        int l=0;
        bool ok = 1;
        for(int i=0 ; i<s1.size() ; i++)f2[s2[i]-'a']++;
        for(int i=0 ; i<26 ; i++){
            if(f1[i]!=f2[i])ok = 0;
        }
        if(ok)return true;
        for(int r=s1.size() ; r<s2.size() ; r++){
            f2[s2[r]-'a']++;
            f2[s2[l++]-'a']--;
            ok = 1;
            for(int i=0 ; i<26 ; i++){
                if(f1[i]!=f2[i])ok = 0;
            }
            if(ok)return true;
        }       
        return false; 
    }
};
