class LRUCache {
public:
unordered_map<int,pair<int,int>> amp;
int c;
deque<int> dq;

    LRUCache(int capacity) {
        c=capacity;
    }
    
    int get(int key) {
        if(amp.count(key))
        {
            dq.push_back(key);
            amp[dq.back()].second++;

            while(amp.size()>c)
            {
                amp[dq.front()].second--;
                if(amp[dq.front()].second==0)
                {
                    amp.erase(dq.front());
                }
                dq.pop_front();
            }
            return amp[key].first;
        }
        return -1;


    }
    
    void put(int key, int value) {
        dq.push_back(key);
        amp[key].first=value;
        amp[key].second++;

        while(amp.size()>c)
        {
            amp[dq.front()].second--;
            if(amp[dq.front()].second==0)
            {
                amp.erase(dq.front());
            }
            dq.pop_front();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */