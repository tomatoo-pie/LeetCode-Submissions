class Solution {
public:
    int solve(string &s, int idx , int sign , long long num){
        if(idx>=s.size() || !isdigit(s[idx])){
            return num * sign;
        }

        num = num * 10 + (s[idx]-'0');

        if(sign == 1 && num>=INT_MAX)
            return INT_MAX;

        if (sign == -1 && -num <= INT_MIN)
            return INT_MIN;

        return solve(s,idx+1,sign,num);

    }
    int myAtoi(string s) {
        s.erase(0, s.find_first_not_of(' '));

        if (s.empty()) return 0;

        int sign = 1;
        int i = 0;

        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        long long ans = 0;

        return solve(s,i,sign,ans);
    }
};