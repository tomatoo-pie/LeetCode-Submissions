class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size()) return false;
        sort(s.begin(),s.end());
        sort(goal.begin(),goal.end());
        for(int i =0 ; i < goal.size() ; i++){
            if(s[i]!=goal[i])return false;
        }
        return true;
    }
};