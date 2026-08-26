class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int i = 0; i <nums.size();i++){
            st.insert(nums[i]);
        }

        int maxlen = 0;

        for(auto it:st){
            if(st.find(it-1) != st.end()) continue;

            int current = it;
            int length = 1;
            while(st.find(current+1) != st.end()){
                current += 1;
                length += 1;
            }

            maxlen = max(maxlen,length);
        }

        return maxlen;
    }
};