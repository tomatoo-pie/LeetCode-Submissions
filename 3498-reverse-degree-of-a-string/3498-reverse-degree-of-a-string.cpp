class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.length();i++){
            sum += (((s[i]-'a') - 26) * (i+1));
        }
        return abs(sum);
    }
};