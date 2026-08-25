from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])

        q = deque()

        drow = [-1,0,1,0]
        dcol = [0,1,0,-1]

        count = 0

        for i in range (n):
            for j in range (m):
                if grid[i][j] == '1':
                    q.append((i,j))
                    grid[i][j] == '0'
                    count = count + 1

                    while q:
                        row = q[0][0]
                        col = q[0][1]
                        q.popleft()

                        for k in range (4):
                            nrow = row + drow[k]
                            ncol = col + dcol[k]
                            if(nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and grid[nrow][ncol] != '0'):
                                q.append((nrow,ncol))
                                grid[nrow][ncol] = '0'
        
        return count
