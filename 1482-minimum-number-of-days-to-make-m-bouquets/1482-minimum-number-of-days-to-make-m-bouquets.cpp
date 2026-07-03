class Solution {
public:
    int minDays(vector<int>& bloomDay, long long m, long long k) {
        if((m*k)>bloomDay.size())return -1;

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high){
            int mid = low + (high-low)/2;
            int Boquet = 0;
            int flower = 0;
            for(int l = 0 ; l < bloomDay.size() ; l++){
                if(mid>=bloomDay[l]){
                    flower++;
                }
                else{
                    Boquet += flower/k;
                    flower = 0;
                }
            }
            Boquet += flower/k;
            if(Boquet >= m)
                high = mid - 1;
            else 
                low = mid+1;
        }
        return low;
    }
};