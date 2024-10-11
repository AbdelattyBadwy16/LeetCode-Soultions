class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<vector<int>>v(1e5+5);
        for(int i=0 ; i<times.size() ; i++){
            v[times[i][0]].push_back((i+1));
            v[times[i][1]].push_back(-(i+1));
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0 ; i<=1e4+4 ; i++){
            pq.push(i);
        }
        map<int,int>mp;
        for(int i=1 ; i<=1e5+4 ; i++){
            for(auto it:v[i]){
                if(it<0){
                    pq.push(mp[-it]);
                }
            }
            for(auto it:v[i]){
                if(it>0){
                    mp[it] = pq.top();
                    pq.pop();
                }
            }
        }
        return mp[targetFriend + 1];
    }
};
