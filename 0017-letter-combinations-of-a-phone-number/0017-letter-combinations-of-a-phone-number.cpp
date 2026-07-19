class Solution {
public:
    void check(int idx,string digits,vector<string> &stringtable,string ans,vector<string> &output){
        if(ans.size()==digits.size()){
            output.push_back(ans);
            return;
        }

        for(int i = 0 ; i < stringtable[digits[idx]-'0'].length() ; i++){
            ans.push_back(stringtable[digits[idx]-'0'][i]);
            check(idx+1,digits,stringtable,ans,output);
            ans.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> stringtable = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> output;
        check(0,digits,stringtable,"",output);
        return output;
    }
};