class Solution {
public:
    static bool cmp(string a,string b){
        string temp = a+b;
        string temp2 = b+a;
        return temp<temp2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto it:nums){
            string s = "";
            if(!it){
                v.push_back("0");
                continue;
            }
            while(it){
                s += (char)(it%10+'0');
                it/=10;
            }
            reverse(s.begin(),s.end());
            v.push_back(s);
        }        
        sort(v.begin(),v.end(),cmp);
        string s = "";
        for(int i=v.size()-1 ; i>=0 ; i--){
            s += v[i];
        }
        if(s[0]=='0')return "0";
        return s;
    }
};