class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> map;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = map.find(key);
        if (it == map.end()) {
            return "";
        }

        const auto& vec = it->second;

        auto bound = upper_bound(
            vec.begin(), 
            vec.end(), 
            make_pair(timestamp, string("")), 
            [](const pair<int, string>& target, const pair<int, string>& elem) {
                return target.first < elem.first;
            }
        );

        if (bound == vec.begin()) {
            return "";
        }

        return (bound - 1)->second;
    }
};