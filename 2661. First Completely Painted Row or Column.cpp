class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<int>row(mat.size(),0),col(mat[0].size(),0);
        map<int,pair<int,int>>id;
        for(int i=0 ; i<mat.size() ; i++){
            for(int j=0 ; j<mat[0].size(); j++)id[mat[i][j]] = {i,j};
        }
        int ans = 0;
        for(int i=0 ; i<arr.size() ; i++){
            pair<int,int>temp = id[arr[i]];
            row[temp.first]++;
            col[temp.second]++;
            cout<<row[temp.first]<<" "<<col[temp.second]<<endl;
            if(row[temp.first] == mat[0].size() || col[temp.second]==mat.size()){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
