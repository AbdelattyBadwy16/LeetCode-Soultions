class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int>zPref(n,0),oSuf(n,0);
        for(int i=0; i<n ; i++){
            if(s[i]=='0')zPref[i] = 1;
            else oSuf[i] = 1;
        }
        for(int i=1 ; i<n ; i++){
            zPref[i] += zPref[i-1]; 
        }
        for(int i=n-2 ; i>=0 ; i--){
            oSuf[i] += oSuf[i+1];
        }
        int ans = 0;
        for(int i=0 ; i<n-1 ; i++){
            ans = max(ans,zPref[i] + oSuf[i+1]);
        }
        return ans;
    }
};
