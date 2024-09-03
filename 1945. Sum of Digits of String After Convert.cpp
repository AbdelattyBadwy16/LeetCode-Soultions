class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        queue<int>q;
        for(int i=0 ;i <s.size() ; i++){
            q.push(s[i]-'a'+1);
        }
        for(int i=0 ; i<k ; i++){
            num = 0;
            while(!q.empty()){
                int x = q.front();
                while(x){
                    num += x%10;
                    x/=10;
                }
                q.pop();
            }
            q.push(num);
        }
        return q.front();
    }
};