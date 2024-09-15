class Solution {
public:
    int findTheLongestSubstring(string s) {
        int msk = 0, ans = 0;
        int n = s.size();
        unordered_map<int,int>mp;
        mp[0] = -1;
        for(int i=0 ; i<n ; i++){
            switch (s[i]) {
                case 'a':
                    msk ^= 1;
                    break;
                case 'e':
                    msk ^= 2;
                    break;
                case 'i':
                    msk ^= 4;
                    break;
                case 'o':
                    msk ^= 8;
                    break;
                case 'u':
                    msk ^= 16;
                    break;
            }
            if(mp.count(msk)){
                ans = max(ans,i - mp[msk]);
            }else mp[msk] = i;
        }

        return ans;
    }
};
