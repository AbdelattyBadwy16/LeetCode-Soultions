class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        pq.push(1);
        set<long long>s;
        long long in=1,val=1;
        while(true){
            if(n==in)return pq.top();
            val=pq.top();
            if(s.count(2*val)==0)pq.push(2*val);
            if(s.count(3*val)==0)pq.push(3*val);
            if(s.count(5*val)==0)pq.push(5*val);
            pq.pop();in++;
            s.insert(2*val);
            s.insert(3*val);
            s.insert(5*val);
        }
    }
};