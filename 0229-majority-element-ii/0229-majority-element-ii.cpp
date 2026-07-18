class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        vector<int> l;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it : mp){
            if(it.second > nums.size()/3)
                l.push_back(it.first);
        }
        return l;
    }
};