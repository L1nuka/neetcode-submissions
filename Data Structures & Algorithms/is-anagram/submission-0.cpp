#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mapA;
        unordered_map<char,int> mapB;
        for (auto c : s)
            mapA[c]++;
        for (auto c : t)
            mapB[c]++;

        if (mapA.size() != mapB.size())
            return false;
        for (auto x : mapA){
            if (mapB.find(x.first) != mapB.end() && mapB.find(x.first)->second == x.second)
                continue;
            else
                return false;
        }
        return true;
    }
};
