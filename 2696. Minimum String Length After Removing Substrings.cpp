class Solution {
public:
    int minLength(string s) {
        while(true){
            string t = "";
            for(int i=0 ; i<s.size() ; i++){
                if(i+1<s.size() && s[i]=='A' && s[i+1]=='B')i++;
                else if(i+1<s.size() && s[i]=='C' && s[i+1]=='D')i++;
                else t+=s[i];
            }
            if(s.size()==t.size())break;
            s = t;
        }
        return s.size();
    }
};
