class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal = []

        for i in range(numRows):
            ind = []
            for j in range(i+1):
                if(j==0 or j==i):
                    ind.append(1)
                else :
                    ind.append((pascal[i-1][j-1] + pascal[i-1][j]))
            pascal.append(ind)
        
        return pascal


        