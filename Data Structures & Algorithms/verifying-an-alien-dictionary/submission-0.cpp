class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> dict;

        for (int i = 0; i < order.size(); i++) {
            dict[order[i]] = i;
        }
        bool flag = false;
        for (int i = 0; i < words.size()-1; i++){
            flag=false;
            string a = words[i];
            string b = words[i+1];
            int t = min(a.size(), b.size());
            for (int j = 0; j < t; j++){
                if (dict[a[j]] < dict[b[j]]) {
                    flag=true;
                    break;
                }

                if (dict[a[j]] > dict[b[j]])
                    return false;
            }
            if (!flag){
                if (a.size()<=b.size())
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
};