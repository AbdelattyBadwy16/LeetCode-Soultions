class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int freq1[26] = {0};
        for(int i=0 ; i<allowed.size() ; i++)freq1[allowed[i]-'a']++;
        int ans = 0;
        for(auto t:words){
            int freq2[26] = {0};
            for(auto c:t)freq2[c-'a']++;
            bool ok = 1;
            for(int i=0 ; i<26 ; i++){
                if(!freq1[i] && freq2[i]){
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};