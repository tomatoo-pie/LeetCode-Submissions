class Solution {
public:
    int firstStableIndex(vector<int>& nums, int t) {
        int maxi = INT_MIN;
        for(int i = 0; i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            priority_queue<int> heapq;
            int j = i;
            while(j<nums.size()){
                heapq.push(-nums[j]);
                j++;
            }

            if(maxi + heapq.top() <= t) return i;
        }
        return -1;
    }
};