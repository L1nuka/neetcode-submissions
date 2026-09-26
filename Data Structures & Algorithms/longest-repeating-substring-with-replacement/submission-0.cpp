class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int tail = 0;
        int maxC = 0;
        int len = s.size();
        int maxWin = 0;
        for (int i = 0; i < len; i++){
            freq[s[i]-'A']++;
            maxC = max(maxC, freq[s[i]-'A']);
            int winSize = i - tail + 1;

            while (winSize - maxC > k) {
                freq[s[tail]-'A']--;
                tail++;
                winSize = i - tail + 1;
            }
            maxWin = max(maxWin, winSize);
        }
        return maxWin;
    }
};
