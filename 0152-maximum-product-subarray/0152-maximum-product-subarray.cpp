class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        if(mini>0){
            int product = 1;
            for(int i = 0 ; i < nums.size() ; i++){
                product = product * nums[i];
            }
            return product;
        }
        int product = 1;
        int maxproduct = INT_MIN;

            for(int i = 0 ; i < nums.size() ; i++){
                product = 1;
                for(int j = i ; j<nums.size();j++){
                    product *= nums[j];
                    maxproduct = max(product,maxproduct);
                }
            }

        return maxproduct;
    }
};