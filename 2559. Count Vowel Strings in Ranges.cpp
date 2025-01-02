class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>v(n);
        for(int i = 0 ; i<n ; i++){
            if(words[i][0] =='a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u')
            {
                if(words[i][words[i].size()-1] =='a' || words[i][words[i].size()-1] == 'e' || 
                    words[i][words[i].size()-1] == 'i' || words[i][words[i].size()-1] == 'o' || 
                    words[i][words[i].size()-1] == 'u') v[i] = 1;
                    else v[i] = 0;
            }else v[i]=0;
            if(i!=0)v[i]+=v[i-1];
        }
        vector<int>ans;
        for(auto x:queries){
            if(x[0]==0)ans.push_back(v[x[1]]);
            else ans.push_back(v[x[1]]-v[x[0]-1]);
        }
        return ans;
    }
};
