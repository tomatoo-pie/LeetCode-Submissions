class Solution {
public:
    string s;
    int pos = 0;

    set<string> expression() {
        set<string> ans = term();

        while (pos < s.size() && s[pos] == ',') {
            pos++;

            set<string> temp = term();

            ans.insert(temp.begin(), temp.end());
        }

        return ans;
    }

    set<string> term() {
        set<string> ans = {""};

        while (pos < s.size() &&
               s[pos] != ',' &&
               s[pos] != '}') {

            set<string> cur;

            if (s[pos] == '{') {
                pos++;

                cur = expression();

                pos++;
            }
            else {
                cur.insert(string(1, s[pos]));
                pos++;
            }

            // Concatenation
            set<string> temp;

            for (const string &a : ans) {
                for (const string &b : cur) {
                    temp.insert(a + b);
                }
            }

            ans = temp;
        }

        return ans;
    }

    vector<string> braceExpansionII(string input) {
        s = input;
        pos = 0;

        set<string> ans = expression();

        return vector<string>(ans.begin(), ans.end());
    }
};