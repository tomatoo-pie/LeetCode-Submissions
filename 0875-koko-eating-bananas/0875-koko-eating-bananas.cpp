class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(),piles.end());  
        int low = 1;
        int high = mx;
        int mid;

        long long totalHours = 0 ;
        while(low<=high){
            mid = low+(high-low)/2;
            totalHours = 0;
            for(int i = 0 ; i< piles.size(); i++){
                totalHours += ceil(double(piles[i])/mid);
            }
            if(totalHours>h)low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};