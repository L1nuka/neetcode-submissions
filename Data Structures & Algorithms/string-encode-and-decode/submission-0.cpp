class Solution {
public:

    string encode(vector<string>& strs) {
        int size = strs.size();
        string code = to_string(size) + ",";
        for (int i = 0; i < strs.size(); i++){
            int s = strs[i].size();
            if (s>99)
                code += to_string(s) + ",";
            else if (s>9)
                code += "0" + to_string(s) + ",";
            else
                code += "00" + to_string(s) + ",";
        }
        for (auto& x : strs)
            code += x;
        return code;
    }

    vector<string> decode(string s) {
        int ptr = s.find(',');
        int size = stoi(s.substr(0,ptr));
        ptr++;
        vector<int> lengths;
        for (int i = 0; i < size; i++){
            lengths.push_back(stoi(s.substr(ptr,3)));
            ptr+=4;
        }
        vector<string> ans;
        for (int i = 0; i < size; i++){
            int tSize = lengths[i];
            ans.push_back(s.substr(ptr,tSize));
            ptr+=tSize;
        }
        return ans;
    }
};
