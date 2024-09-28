class MyCircularDeque {
    vector<int>v;
    int f,r,sz,mx;
public:
    MyCircularDeque(int k) {
        sz = 0;
        r = -1;
        f = 0;
        mx = k;
        v = vector<int>(k);
    }
    
    bool insertFront(int value) {
        if(sz==mx)return false;
        if(sz)
        {
            f--;
            if(f<0)f = mx - 1;
        }else r = 0;
        v[f] = value;
        sz++;
        return true;
    }
    
    bool insertLast(int value) {
        if(sz==mx)return false;
        if(r+1<mx)v[++r] = value;
        else {
            r = 0;
            v[r] = value;
        }
        sz++;
        return true;
    }
    
    bool deleteFront() {
        if(!sz)return false;
        f++;
        if(f==mx)f = 0;
        sz--;
        if(sz==0)f = 0,r = -1;
        return true;
    }
    
    bool deleteLast() {
        if(!sz)return false;
        r--;
        if(r<0)r = mx-1;
        sz--;
        if(sz==0)f = 0,r = -1;
        return true;
    }
    
    int getFront() {
        if(!sz)return -1;
        return v[f];
    }
    
    int getRear() {
        if(!sz)return -1;
        return v[r];
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==mx;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
