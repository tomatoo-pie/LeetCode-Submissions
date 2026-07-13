class Solution {
public:
    void generate(int right,int left,int n,string s,vector<string> &arr){
        
        if(s.size()==2*n){
            arr.push_back(s);
            return;
        }

        if(right < n){
            s.push_back('(');
            generate(right+1,left,n,s,arr);
            s.pop_back();
        }

        if(left < right){
            s.push_back(')');
            generate(right,left+1,n,s,arr);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        generate(0, 0, n, "", arr);
        return arr;
    }
};