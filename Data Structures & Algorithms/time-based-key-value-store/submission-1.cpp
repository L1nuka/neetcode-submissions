class TimeMap {
public:

    unordered_map<string, map<int,string>> keys;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keys[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (!keys.contains(key))
            return "";
        auto temp = keys[key];
        auto it = temp.upper_bound(timestamp);
        if (it != temp.begin()) {
            --it;
            return it->second;
            }
        return "";
    }
};
