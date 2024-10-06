class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string>v1,v2;
        string t = "";
        for(int i=0 ; i<s1.size() ; i++)
        {
            if(s1[i]==32)v1.push_back(t),t="";
            else
                t += s1[i];
        }
        v1.push_back(t);
        t = "";
        for(int i=0 ; i<s2.size() ; i++)
        {
            if(s2[i]==32)v2.push_back(t),t="";
            else
                t += s2[i];
        }
        v2.push_back(t);
        if(v1.size()<v2.size()){
            swap(v1,v2);
        }
        int j = 0;
        for(int i=0 ; i<v1.size() && j<v2.size() ; i++){
            if(v1[i]==v2[j]){
                j++;
            }else break;
        }
        int jj = v2.size()-1;
        for(int i=v1.size()-1 ; i>=0 && jj>=0 ; i--){
            if(v1[i]==v2[jj]){
                jj--;
            }else break;
        }
        return (jj==-1 || j==v2.size() || (j + (v2.size() - jj - 1)>=v2.size()));
    }
};
