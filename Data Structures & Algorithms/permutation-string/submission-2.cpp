class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        char temp;
        int result;
        int ptr = 0;
        unordered_map<char,int> key, window;
        for (auto c : s1)
            key[c]++;

        for (int i = 0; i < s2.size(); i++) {
            temp = s2[i];
            window[temp]++;
            result = matchMap(key, temp, window[temp]);
            if (result == -1)
                window.clear();
            else if (result == 0){
                do {
                    if (--window[s2[ptr++]] == 0)
                        window.erase(s2[ptr-1]);
                }
                while (matchMap(key, temp, window[temp]) == 0);
            }
            else if (key == window)
                return true;
        }
        return false;
    }

    int matchMap(const unordered_map<char,int>& a, const char& b, const int& count){
        auto it = a.find(b);
        if (it == a.end())
            return -1;
        if (it->second < count)
            return 0;
        return 1;
    }
};
