class Solution {
public:
    vector<bool>prime;
    void sieve(){
        prime[0] = prime[1] = 0;
        for(int i=2 ; i*i<1e3+5 ; i++){
            if(prime[i]){
                for(int j = i+i ; j<1e3+5 ; j+=i){
                    prime[j] = 0;
                }
            }
        }   
    }

    bool primeSubOperation(vector<int>& nums) {
        prime = vector<bool>(1e3+5,1);
        sieve();
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=nums[i]-1 ; j>=1 ; j--){
                if(prime[j] && (( i == 0 || nums[i] - j > nums[i-1]))){
                    nums[i] -= j;
                    break;
                }
            }
        }
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i]<=nums[i-1])return 0;
        }
        return 1;
    }
};
