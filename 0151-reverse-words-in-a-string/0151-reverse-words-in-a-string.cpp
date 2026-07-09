class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n-1;
        while(i>=0){
            if(s[i]==' '){
                while(i>=0 && s[i]==' '){
                    i--;
                }
            }
            else{
                while(i>=0 && s[i]!=' '){
                    s += s[i];
                    i--;
                }
                s+=' ';
            }
        }
        s.erase(0,n);
        int start = 0;
        for(int i = 0 ; i < s.length();i++){
            if(s[i]==' '){
                int end = i;
                reverse(s.begin()+start,s.begin()+end);
                start = i+1;
            }
        }

        s.erase(s.length()-1,s.length());
            
        return s;
    }
};