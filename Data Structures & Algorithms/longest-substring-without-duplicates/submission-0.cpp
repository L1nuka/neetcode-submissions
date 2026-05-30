class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> sub;
        int len=0;
        int tail=0;
        for (int i = 0; i < s.size(); i++){
            if (!sub[s[i]]){
                len=max(len,i-tail+1);
                sub[s[i]] = true;
            }
            else{
                while(sub[s[i]])
                    sub[s[tail++]] = false;
                sub[s[i]] = true;
            }
        }
        return len;
    }
};
