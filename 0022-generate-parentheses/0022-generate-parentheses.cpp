class Solution {
public:
    void generate(int left,int right,string s,vector<string>& paranthesis,int n){
        if(s.length() == 2*n){
            paranthesis.push_back(s);
            return;
        }

        if(left<n){
            s.push_back('(');
            generate(left+1,right,s,paranthesis,n);
            s.pop_back();
        }

        if(right < left){
            s.push_back(')');
            generate(left,right+1,s,paranthesis,n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> paranthesis;
        generate(0,0,"",paranthesis,n);
        return paranthesis;
    }
};