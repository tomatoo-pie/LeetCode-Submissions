class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int,int>> q;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i =0;i<n;i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]=='1'){
                    count++;
                    q.push({i,j});
                    grid[i][j] = '0';
                }

                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();

                    for(int k = 0 ; k < 4 ; k++){
                        int nrow = row + drow[k];
                        int ncol = col + dcol[k];
                        if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && grid[nrow][ncol]!='0'){
                            q.push({nrow,ncol});
                            grid[nrow][ncol] = '0';
                        }
                    }
                }
            }
        }
        return count;
    }
};