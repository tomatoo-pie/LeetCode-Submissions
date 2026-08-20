class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];
        if(color == original) return image;

        vector<vector<int>> vis(n,vector<int> (m,-1));

        queue<pair<int,int>> q;
        
        q.push({sr,sc});
        image[sr][sc] = color;
        vis[sr][sc] = color;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                bool condition = (nrow>=0 && ncol>=0 && ncol<m && nrow<n && vis[nrow][ncol]!=color && image[nrow][ncol] == original);
                if(condition){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = color;
                    image[nrow][ncol] = color;
                }
            }
        }

        return image;
    }
};