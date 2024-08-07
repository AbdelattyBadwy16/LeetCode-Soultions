class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp;
        for(auto it:arr)mp[it]++;
        int cnt  = 0;
        string ans ="";
        for(auto it:arr){
            if(mp[it]==1){
                cnt++;
                if(cnt==k)ans = it;
            }
        }
        return ans;
    }
};