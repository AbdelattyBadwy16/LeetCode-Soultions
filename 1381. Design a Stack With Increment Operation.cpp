class CustomStack {
    vector<int>v;
    int sz , top , len;
public:
    CustomStack(int maxSize) {
        sz = maxSize;
        top = -1;
        len = 0;
        v = vector<int>(sz);
    }
    
    void push(int x) {
        if(len==sz)return;
        len++;
        v[++top] = x;
    }
    
    int pop() {
        if(!len)return -1;
        len--;
        return v[top--];
    }
    
    void increment(int k, int val) {
        for(int i=0 ; i<min(k,len) ; i++){
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
