class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        s.erase(0,s.find_first_not_of(' '));
        if(s.empty())return 0;
        if(s[0]=='-' || s[0]=='+'){
            int i = 1;
            while(i<s.size() && isdigit(s[i])){
                if(ans > (INT_MAX - (s[i]-'0')) / 10){if(s[0]=='-')return INT_MIN;else return INT_MAX;}
                ans = ans*10 + (s[i]-'0');
                i++;
            }
            if(s[0]=='-')return -ans;
            return ans;
        }
        else if(isdigit(s[0])) {
            int i = 0;
            while(i<s.size() && isdigit(s[i])){
                if(ans > (INT_MAX - (s[i]-'0')) / 10)return INT_MAX;
                ans = ans*10 + (s[i]-'0');
                i++;
            }
            return ans;;
        }
        return 0;
    }
};