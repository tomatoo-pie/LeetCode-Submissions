class Solution {
public:
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

        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            if (sign == 1 && ans > INT_MAX)
                return INT_MAX;

            if (sign == -1 && -ans < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};