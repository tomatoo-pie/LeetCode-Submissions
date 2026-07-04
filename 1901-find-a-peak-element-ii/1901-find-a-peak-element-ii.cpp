class Solution {
public:
    int MaxIndex(vector<vector<int>> &mat,int column){
        int maxi = mat[0][column];
        int rowindex = 0;
        for(int i = 0 ; i < mat.size();i++){
            if(mat[i][column]>maxi){
                maxi = mat[i][column];
                rowindex = i;
            }
        }
        return rowindex;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int rowmax;
        int id;
        int low = 0; 
        int high = col - 1;
        int mid;
        while(low<=high){
            mid = low+(high-low)/2;
            id = MaxIndex(mat,mid);
            rowmax = mat[id][mid];
            int left = mid-1>=0? mat[id][mid-1]:-1;
            int right = mid+1<col? mat[id][mid+1]:-1;
            if(rowmax>left && rowmax>right)return {id,mid};
            else if(rowmax < left)high = mid-1;
            else low = mid+1 ;
        }

        return {-1,-1};
    }
};