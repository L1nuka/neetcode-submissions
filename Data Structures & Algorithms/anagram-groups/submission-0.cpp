class Solution {
public:

    string strToKey(const string& str){
        map<char,int> temp;
        string result ="";
        for (auto& c : str)
            temp[c]++;
        for (auto& x : temp){
            for (int i = 0; i < x.second; i++)
                result+=x.first;
        }
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagrams;
        for (int i = 0; i < strs.size(); i++){
            auto temp = strToKey(strs[i]);
            anagrams[temp].push_back(strs[i]);
        }
        vector<vector<string>> results;
        for (auto& x : anagrams){
            results.push_back(x.second);
        }
        return results;
    }
};
