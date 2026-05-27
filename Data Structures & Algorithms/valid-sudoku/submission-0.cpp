class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), squares(9);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char temp = board[i][j];
                if (temp == '.')
                    continue;
                if (!rows[i].insert(temp).second)
                    return false;
                if (!cols[j].insert(temp).second)
                    return false;
                if (!squares[(i/3)*3 + (j/3)].insert(temp).second)
                    return false;
            }
        }
        return true;
    }
};