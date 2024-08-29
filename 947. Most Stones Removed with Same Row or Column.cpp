class Solution {
public:
    int n;
    vector<int>par,size;
    void init(){
        for(int i=1 ; i<n ; i++){
            par[i] = i;
            size[i] = 1;
        }
    }
    int getPar(int u){
        if(par[u]==u)return u;
        return par[u] = getPar(par[u]);
    }

    void compine(int a,int b){
        cout<<a<<" gg "<<b<<endl;
        a = getPar(a);
        b = getPar(b);
        cout<<a<<" "<<b<<endl;
        if(a==b)return;
        if(size[a]>size[b]){
            size[a]+=size[b];
            par[b] = a;
        }else{
            size[b]+=size[a];
            par[a] = b;
        }
    }
    int removeStones(vector<vector<int>>& s) {
        n = 1000+5;
        par = vector<int>(n);
        size = vector<int>(n);
        init();
        vector<bool>take(n,0);
        for(int i=0 ; i<s.size() ; i++){
            for(int j=i+1 ; j<s.size() ; j++){
                if(s[i][0]==s[j][0] || s[i][1]==s[j][1])compine(i+1,j+1),take[i]=take[j]=1;
            }
        }
        int ans = 0;
        set<int>ss;
        for(int i=1 ; i<=s.size() ; i++)ss.insert(getPar(i));
        for(auto it:ss)ans += size[it] - 1;
        return ans ;
    }
};