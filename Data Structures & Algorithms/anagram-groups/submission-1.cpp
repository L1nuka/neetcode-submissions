class Solution {
public:

    string strToKey(const string& str){
        int arr[26] = {};
        for (int i = 0; i < str.size(); i++)
            arr[str[i]-'a']++;
        string temp = "";
        for (auto x : arr){
            temp+=x;
        }
        return temp;
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
