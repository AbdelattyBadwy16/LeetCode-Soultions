class MyCalendarTwo {
    vector<pair<int,int>>v;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        bool ok = 1;
        vector<pair<int,int>>temp;
        for(auto it:v){
            if(!(start>=it.second || it.first>=end))temp.push_back(it);
        }

        for(int i=0 ; i<temp.size() ; i++){
            for(int j=i+1 ; j<temp.size() ; j++){
                if(!(temp[i].first>=temp[j].second || temp[j].first>=temp[i].second)){
                    ok = 0;
                    break;
                }
            }
            if(!ok)break;
        }
       
        if(ok){
            v.push_back({start,end});
        }
        return ok;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
