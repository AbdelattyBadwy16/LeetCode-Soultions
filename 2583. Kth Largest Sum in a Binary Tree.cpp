class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string,int>mp;
        for(int i=0 ; i<arr1.size() ; i++){
            string s = "";
            while(arr1[i]){
                s = (char)((arr1[i]%10) + '0') + s;
                arr1[i]/=10;
            }
            string t = "";
            for(int j=0 ; j<s.size() ; j++){
                t += s[j];
                mp[t] = 1;
            }
        }

        int ans = 0;

        for(int i=0 ; i<arr2.size() ; i++){
            string s = "";
            while(arr2[i]){
                s = (char)((arr2[i]%10) + '0') + s;
                arr2[i]/=10;
            }
            string t = "";
            for(int j=0 ; j<s.size() ; j++){
                t += s[j];
                if(mp.count(t))ans = max(ans,(int)t.size());
            }
        }
        return ans;
    }   
};
