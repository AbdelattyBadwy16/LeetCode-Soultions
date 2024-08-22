class Solution {
public:
    int findComplement(int num) {
        bitset<32>s(num);
        int mx = 0;
        for(int i=0 ; i<32 ; i++){
            if(s[i])mx=i;
        }
        for(int i=0; i<=mx ; i++){
            s[i]=(s[i]^1);
        }
        return s.to_ullong();
    }
};