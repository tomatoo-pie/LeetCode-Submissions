class Solution {
public:
    void check(int idx,string digits,vector<string> &stringtable,string ans,vector<string> &output){
        if(ans.size()==digits.size()){
            output.push_back(ans);
            return;
        }

        int digit = digits[idx] - '0';

        for(int i = 0 ; i < stringtable[digit].length() ; i++){
            ans.push_back(stringtable[digit][i]);
            check(idx+1,digits,stringtable,ans,output);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        vector<string> stringtable = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> output;
        check(0,digits,stringtable,"",output);
        return output;
    }
};