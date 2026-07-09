class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        int i = 0; int j = 0;
        
        while(i<n && j<n){
            while(i<n && s[i]==' ') i++;
            while(i<n && s[i]!=' ') s[j++] = s[i++];
            while(i<n && s[i]==' ') i++;
            if(i<n) s[j++] = ' ';
        }

        s.resize(j); 

        reverse(s.begin(),s.end());

        int start = 0;
        for(int i = 0 ; i <= s.length();i++){
            if(i==s.size() || s[i]==' '){
                int end = i;
                reverse(s.begin()+start,s.begin()+end);
                start = end+1;
            }
        }
  
        return s;
    }
};