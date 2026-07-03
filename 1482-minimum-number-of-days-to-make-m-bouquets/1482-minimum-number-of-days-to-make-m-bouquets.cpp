class Solution {
public:
    int minDays(vector<int>& bloomDay, long long m, long long k) {
        int n = bloomDay.size();
        long long mk = m*k;
        if(mk>n)return -1;
        vector<int> usable(n,0);

        int count;
        int ans;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int mid;

        while(low<=high){
            mid = low + (high-low)/2;
            for(int j = 0 ; j<n ; j++){
                if(mid>=bloomDay[j])usable[j]=1;
                else usable[j]=0;
            }
            count=0;
            ans=0;
            for(int l = 0 ; l < n ; l++){
                if(usable[l]>0){
                    count++;
                }
                else{
                    ans += count/k;
                    count = 0;
                }
            }
            ans += count/k;
            if(ans >= m)
                high = mid - 1;
            else 
                low = mid+1;
        }

        return low;
    }
};