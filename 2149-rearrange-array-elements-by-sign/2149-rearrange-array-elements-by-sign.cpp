class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0 ; int j = 1;int k = 0;
        vector<int> arr = nums;
        for(int k = 0 ; k < nums.size();k++){
            if(arr[k]>0) {nums[i]=arr[k];i+=2;}
            else {nums[j]=arr[k];j+=2;}
        }

        return nums;
    }
};