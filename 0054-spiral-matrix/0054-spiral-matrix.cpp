class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> sporder;
        int starti = 0;
        int startj = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0 , j = 0 , k = 0;
        while(starti<n && startj < m){

            if (starti == n - 1) {
                for (int j = startj; j < m; j++)
                    sporder.push_back(matrix[starti][j]);
                break;
            }

            // Only one column left
            if (startj == m - 1) {
                for (int i = starti; i < n; i++)
                    sporder.push_back(matrix[i][startj]);
                break;
            }

            j = startj;
            i = starti;
            while(j<m-1){
                sporder.push_back(matrix[i][j]);
                k++;
                j++;
            }
            
            while(i<n-1){
                sporder.push_back(matrix[i][j]);
                k++;
                i++;
            }
            
            while(j>startj){
                sporder.push_back(matrix[i][j]);
                k++;
                j--;
            }

            while(i>starti){
                sporder.push_back(matrix[i][j]);
                k++;
                i--;
            }
            
            starti++;
            startj++;
            m--;
            n--;
        }
        return sporder;
    }
};