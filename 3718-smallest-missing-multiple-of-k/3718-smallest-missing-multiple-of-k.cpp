class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size();i++){
            st.insert(nums[i]);
        }

        int j = 1;

        while(true){
            if(st.find(k*j) != st.end())
                j++;
            else
                return j*k;
        }

        return 0;
    }
};