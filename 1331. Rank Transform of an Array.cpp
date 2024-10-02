class Solution {
public:
    vector<int> Compress(vector<int> v){
        int n = v.size();
        vector<int>temp = v;
        sort(temp.begin(),temp.end());
        int st = 1;
        map<int,int>mp;
        for(int i=0 ; i<n ; i++){
            if(mp.count(temp[i]))continue;
            if(i && temp[i-1]!=temp[i])st++;
            mp[temp[i]]=st;
        }
        for(int i=0 ; i<n ; i++){
            v[i] = mp[v[i]];
        }
        return v;
    }
    vector<int> arrayRankTransform(vector<int>& arr) {
         arr = Compress(arr);
         return arr;
    }
};
