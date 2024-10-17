class Solution {
public:
    int maximumSwap(int num) {
        vector<int>digits;
        while(num){
            digits.push_back(num%10);
            num /= 10;
        }
        // 6 3 7 2
        for(int i=digits.size()-1 ; i>=0 ; i--){
            int mx = digits[i],idx = i ;
            for(int j=0 ; j<i ; j++){
                if(digits[j]>mx){
                    mx = digits[j];
                    idx = j;
                }
            }
            if(mx!=digits[i]){
                swap(digits[i],digits[idx]);
                break;
            }
        }
        int res = 0;
        for(int i=digits.size()-1 ; i>=0 ; i--){
            res = (res*10) + digits[i];
        }
        return res;
    }
};
