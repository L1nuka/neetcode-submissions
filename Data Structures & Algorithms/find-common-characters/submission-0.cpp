class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> key, temp;
        string t = words[0];
        for (auto& x : t){
            key[x]++;
        }

        int len = words.size();
        for (int i = 0; i < len; i++){
            t = words[i];
            for (auto& c : t){
                temp[c]++;
            }
            for (auto& [x,y] : key){
                y = min(y,temp[x]);
            }
            temp.clear();
        }
        vector<string> ans;
        for (auto& [x,y] : key){
            for (int i = 0; i < y; i++)
                ans.push_back(string(1,x));
        }
        return ans;
    }
};