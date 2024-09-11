class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for(int i=0 ; i<32 ; i++){
            if(((start>>i)&1) != ((goal>>i)&1))cnt++;
        }
        return cnt;
    }
};