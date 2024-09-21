class Solution {
public:
    void solve(int num , int& n , vector<int>&v){
        int temp = num;
        for(int i=0 ; i<=9 ; i++){
            temp = num;
            temp = (temp * 10) + i;
            if(temp<=n){
                v.push_back(temp);
                solve(temp,n,v);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1 ; i<=min(9,n) ; i++)
            ans.push_back(i),solve(i,n,ans);
        return ans;
    }
};
