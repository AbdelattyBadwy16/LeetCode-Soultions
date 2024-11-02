class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string>words;
        string s = "";
        for(auto c:sentence){
            if(c==' ')words.push_back(s),s="";
            else s += c;
        }
        words.push_back(s);
        bool ok = 1;
        for(int i=1 ; i<words.size() ; i++){
            if(words[i][0] != words[i-1][words[i-1].size()-1])ok = 0;
        }
        string lst = words[words.size()-1];
        return ok && words[0][0] == lst[lst.size()-1];
    }
};
