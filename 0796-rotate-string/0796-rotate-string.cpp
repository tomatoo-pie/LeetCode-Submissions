class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        s+=s;
        int i = 0;
        int j = goal.size()-1;
        while(j<s.size()){
            if(s.substr(i,goal.size())==goal.substr(0,goal.size())) return true;
            i++;
            j++;
        }
        return false;
    }
};