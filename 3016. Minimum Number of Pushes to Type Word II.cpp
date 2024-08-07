class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>freq;
        for(auto it:word){
            freq[it]++;
        }
        vector<pair<int,char>>v;
        for(auto it:freq)v.push_back({it.second,it.first});
        // for sort the arry decreasing by the freq of char
        auto cmp = [&] (pair<int,char>a,pair<int,char>b)
        {
            return a.first>b.first;
        };
        sort(v.begin(),v.end() , cmp);
        int cnt = 1;
        int ans = 0;
        int len = 0;
        for(auto it:v){
            ans += (cnt * it.first);
            len++;
            if(len==8)cnt++,len=0;
        }
        return ans;
    }
};