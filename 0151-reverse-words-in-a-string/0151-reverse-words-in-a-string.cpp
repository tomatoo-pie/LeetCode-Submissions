class Solution {
public:
    string reverseWords(string s) {
        vector<string> n;
        string c = "";
        for(int i = 0 ; i < s.size(); i++){
            if(s[i]==' ')continue;
            c="";
            while(i < s.size() && s[i]!=' '){
                c+=s[i];
                i++;
            }
            n.push_back(c);
        }

        string reversed = "";
        for(int i = n.size()-1; i >= 0 ; i--){
            reversed += n[i];
            reversed += ' ';
        }

        string newreversed = reversed.substr(0,reversed.size()-1);
        return newreversed;
    }
};