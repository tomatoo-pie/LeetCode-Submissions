class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int j = 0;
        while(mp[0]>0){
            nums[j]=0;
            j++;
            mp[0]--;
        }
        while(mp[1]>0){
            nums[j]=1;
            j++;
            mp[1]--;
        }
        while(mp[2]>0){
            nums[j]=2;
            j++;
            mp[2]--;
        }
        
    }
};