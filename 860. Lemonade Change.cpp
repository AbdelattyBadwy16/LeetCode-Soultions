class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        bool ok = 1;
        for(auto it:bills){
            if(it==5)five++;
            if(it==10){
                if(five)five--,ten++;
                else ok = 0;
            }
            if(it==20){
                if(five && ten){
                    five--;
                    ten--;
                }else if(five>=3)five-=3;
                else ok =0;
            }
        }
        return ok;
    }
};