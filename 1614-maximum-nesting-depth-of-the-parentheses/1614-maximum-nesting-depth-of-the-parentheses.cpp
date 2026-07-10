class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxdepth = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='(')depth++;
            else if(s[i]==')')depth--;
            maxdepth = max(depth,maxdepth);
        }
        return maxdepth;
    }
};