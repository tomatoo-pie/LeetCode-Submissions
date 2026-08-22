class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O' && (i == n-1 || i == 0 || j==m-1 || j == 0 )) {
                    board[i][j] = 'R';
                    q.push({i,j});
                }
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && ncol>=0 && ncol<m && nrow<n && board[nrow][ncol]=='O'){
                    board[nrow][ncol] = 'R';
                    q.push({nrow,ncol});
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                if(board[i][j] != 'R') board[i][j] = 'X';
                else board[i][j] = 'O';
            }
        }
    }
};