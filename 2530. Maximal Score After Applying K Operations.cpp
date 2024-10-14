class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0 ; i<nums.size() ; i++){
            pq.push(nums[i]);
        }
        long long ans = 0;
        for(int i=0 ; i<k ; i++){
            ans += pq.top();
            int t = ceil(pq.top() / 3.0);
            pq.pop();
            pq.push(t);
        }
        return ans;
    }
};
