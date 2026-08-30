class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 1;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int minid = -1;
        int maxid = -1;

        for(int i = 0;i<n;i++){
            if(mini > nums[i]){
                mini  = nums[i];
                minid = i;
            }
            if(maxi < nums[i]){
                maxi = nums[i];
                maxid = i;
            }
        }

        if (minid > maxid)
            swap(minid, maxid);


        int bothleft = maxid+1;
        int bothright = n-minid;
        int oneeach = minid+1+n-maxid;

        return min(min(bothright,bothleft),oneeach);

    }
};