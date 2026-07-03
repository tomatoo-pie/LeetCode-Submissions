class Solution {
public:
    int minDays(vector<int>& bloomDay, long long m, long long k) {
        int n = bloomDay.size();
        long long mk = m*k;
        if(mk>n)return -1;
        vector<int> usable(n,0);

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int mid;

        int Boquet;
        int flower;

        while(low<=high){
            mid = low + (high-low)/2;
            Boquet = 0;
            flower = 0;
            for(int l = 0 ; l < n ; l++){
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