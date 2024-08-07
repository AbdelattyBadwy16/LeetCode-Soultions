class Solution {
public:
    int countSeniors(vector<string>& details) {
        string d = "60";
        int cnt = 0;
        for(auto it:details){
            string s ="";
            s += it[11];
            s += it[12];
            if(s > d){
                cnt++;
            }
        }
        return cnt;
    }
};