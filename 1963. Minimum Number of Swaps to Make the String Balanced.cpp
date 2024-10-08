class Solution {
public:
    int minSwaps(string s) {
        int n = s.size() , cnt =  0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='[')cnt++;
            else if(cnt>0)cnt--;
        }
        return (cnt+1)>>1;
    }
};
