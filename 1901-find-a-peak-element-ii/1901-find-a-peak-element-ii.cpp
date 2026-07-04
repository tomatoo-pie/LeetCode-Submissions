class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int n = col;
        int m = row-1;
        int low,high,mid;

        if(mat[0][0]>mat[0][1] && mat[0][0]>mat[1][0])return {0,0};
        if(mat[0][n-1]>mat[0][n-2] && mat[0][n-1]>mat[1][n-1])return {0,n-1};
        if(mat[row-1][0]>mat[row-1][1] && mat[row-1][0]>mat[row-2][0])return {row-1,0};
        if(mat[row-1][col-1]>mat[row-1][col-2] && mat[row-1][col-1]>mat[row-2][col-1])return {row-1,col-1};
        
        for(int i = 1 ; i < col-1 ; i++){
            if(mat[0][i]>mat[1][i] && mat[0][i]>mat[0][i-1] && mat[0][i]>mat[0][i+1])return {0,i};
        }

        for(int i = 1 ; i < col-1 ; i++){
            if(mat[m][i]>mat[m-1][i] && mat[m][i]>mat[m][i-1] && mat[m][i]>mat[m][i+1])return {m,i};
        }

        for(int j = 1 ; j < m ; j++){
            if(mat[j][0]>mat[j][1] && mat[j][0]>mat[j-1][0] && mat[j][0]>mat[j+1][0])return {j,0};
            if(mat[j][col-1]>mat[j][col-2] && mat[j][col-1]>mat[j-1][col-1] && mat[j][col-1]>mat[j+1][col-1])return {j,col-1};
            low = 1;
            high = col-2;
            while(low<=high){
                mid = low + (high-low)/2;
                if(mat[j][mid]>mat[j][mid-1]&& mat[j][mid]>mat[j][mid+1] && mat[j][mid]>mat[j+1][mid] && mat[j][mid]>mat[j-1][mid]) return {j,mid};
                else if(mat[j][mid]>mat[j][mid-1])low = mid+1;
                else high = mid-1;
            }
        }
        return {0,mid};

    }
};