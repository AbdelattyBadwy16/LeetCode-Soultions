class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        int cnt = 1;
        vector<vector<int>>ans;
        auto check = [&] (int i,int j)
        {
            if(i>=0 && j>=0 && i<rows && j<cols)return 1;
            return 0;
        };
        vector<int>temp;
        temp.push_back(r);
        temp.push_back(c);
        ans.push_back(temp);
        while(cnt<=rows+cols+100){
            for(int i=r,j=c+1 ; j<=cnt+c ;j++ ){
                if(check(i,j)){
                    temp.clear();
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
            c+=cnt;
            for(int i=r+1,j=c ; i<=cnt+r ;i++ ){
                if(check(i,j)){
                    temp.clear();
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
            r+=cnt;
            cnt++;
            for(int i=r,j=c-1 ; j>=c-cnt ;j-- ){
                if(check(i,j)){
                    temp.clear();
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
            c-=cnt;
            for(int i=r-1,j=c ; i>=r-cnt ;i-- ){
                if(check(i,j)){
                    temp.clear();
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
            r-=cnt;
            cnt++;
        }
        return ans;
    }
};