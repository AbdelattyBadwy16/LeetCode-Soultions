class Solution {
public:
    string makeFancyString(string s) {
        string t = "";
        int cnt  = 0;
        for(int i=0 ; i<s.size() ; i++){
            if(!i){
                cnt = 1;
                t+=s[i];
                continue;
            }
            if(s[i]==s[i-1])cnt++;
            else cnt = 1;
            if(cnt<3)t+=s[i];
        }
        return t;
    }
};
