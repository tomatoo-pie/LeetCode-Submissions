class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            mapp = {'1':0,'2':0,'3':0,'4':0,'5':0,'6':0,'7':0,'8':0,'9':0,'.':0}
            for j in range(9):
                mapp[board[i][j]] += 1
                if(mapp[board[i][j]] > 1 and board[i][j] != '.'):
                    return False
                
            mapp = {'1':0,'2':0,'3':0,'4':0,'5':0,'6':0,'7':0,'8':0,'9':0,'.':0}
            for j in range(9):
                mapp[board[j][i]] += 1
                if(mapp[board[j][i]] > 1 and board[j][i] != '.'):
                    return False

            mapp = {'1':0,'2':0,'3':0,'4':0,'5':0,'6':0,'7':0,'8':0,'9':0,'.':0}
            for m in range (i - i%3,i - i%3 + 3):
                for n in range (i%3 * 3,i%3 * 3 + 3):
                    mapp[board[m][n]] += 1
                    if(mapp[board[m][n]] > 1 and board[m][n] != '.'):
                        return False

        return True