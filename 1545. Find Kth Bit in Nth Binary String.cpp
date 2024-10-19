class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=0 ; i<n-1 ; i++){
            string temp = s;
            reverse(temp.begin(),temp.end());
            for(int j=0 ; j<temp.size(); j++){
                if(temp[j]=='1')temp[j]='0';
                else temp[j]='1';
            }
            s = s + '1' + temp;
        }
        return s[k-1];
    }
};
