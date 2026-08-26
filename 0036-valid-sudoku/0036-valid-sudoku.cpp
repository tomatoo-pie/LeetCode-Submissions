class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {

            // Check row
            map<char, int> mapp;
            for (int j = 0; j < 9; j++) {
                mapp[board[i][j]]++;

                if (mapp[board[i][j]] > 1 && board[i][j] != '.') {
                    return false;
                }
            }

            // Check column
            mapp.clear();
            for (int j = 0; j < 9; j++) {
                mapp[board[j][i]]++;

                if (mapp[board[j][i]] > 1 && board[j][i] != '.') {
                    return false;
                }
            }

            // Check 3x3 box
            mapp.clear();

            for (int m = i - i % 3; m < i - i % 3 + 3; m++) {
                for (int n = i % 3 * 3; n < i % 3 * 3 + 3; n++) {

                    mapp[board[m][n]]++;

                    if (mapp[board[m][n]] > 1 && board[m][n] != '.') {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};