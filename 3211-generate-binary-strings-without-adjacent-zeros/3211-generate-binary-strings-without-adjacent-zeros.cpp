class Solution {
public:
    void generate(int n,string s,vector<string> &arr){
        if(s.length() == n){
            arr.push_back(s);
            return;
        }
        
        s.push_back('1');
        generate(n, s, arr);
        s.pop_back();

        if (s.empty() || s.back() != '0') {
            s.push_back('0');
            generate(n, s, arr);
            s.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        vector<string> arr;
        string s = "";
        generate(n,s,arr);
        
        return arr;
    }
};