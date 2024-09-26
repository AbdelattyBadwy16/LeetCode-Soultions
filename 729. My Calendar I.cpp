class MyCalendar {
    vector<pair<int,int>>v;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        bool ok = 1;
        for(auto it:v){
            if(!(start>=it.second || it.first>=end))ok = 0;
        }
        if(ok){
            v.push_back({start,end});
        }
        return ok;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
