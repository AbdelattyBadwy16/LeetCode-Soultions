class KthLargest {
    int k;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto n : nums){
            add(n);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>k)minHeap.pop();
        return minHeap.top();
    }
};

