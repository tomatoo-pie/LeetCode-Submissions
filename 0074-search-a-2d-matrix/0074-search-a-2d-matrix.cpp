class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0; i < row ; i++){
            int low = 0;
            int high = col - 1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(matrix[i][mid]==target)return true;
                else if(matrix[i][mid]>target)high = mid-1;
                else low = mid+1;
            }
        }
        return false;
    }
};