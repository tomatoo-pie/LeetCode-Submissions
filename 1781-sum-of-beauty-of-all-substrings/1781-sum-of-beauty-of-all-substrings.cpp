class Solution {
public:
    int beauty(string& s,int left,int right){
        vector<int> freq(26,0);
        for(int i = left ; i <= right ; i++){
            freq[s[i]-'a']++;
        }

        int maxfreq = 0;
        int minfreq = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxfreq = max(maxfreq, freq[i]);
                minfreq = min(minfreq, freq[i]);
            }
        }

        return maxfreq - minfreq ;
    }

    int beautySum(string s) {
        int count =0;
        for(int i = 0; i < s.size() ; i++){
            for(int j = i ; j < s.size() ; j++){
                count += beauty(s,i,j);
            }
        }
        return count;
    }
};