class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits = 0;
        for(int i=0 ; i<32 ; i++){
            if(num2 & (1<<i))bits++;
        }
        int x = 0;
        for(int i=31 ; i>=0 && bits ; i--){
            if(num1 & (1<<i)) x |= (1<<i),bits--;
        }
        for(int i=0 ; i<32 && bits; i++){
            if(x & (1<<i))continue;
            x |= (1<<i);
            bits--;
        }
        return x;
    }
};
