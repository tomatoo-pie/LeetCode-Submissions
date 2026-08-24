class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> dist;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string prev : parent[word]) {
            path.push_back(prev);
            dfs(prev, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        dist[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int currentDist = dist[word];

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;

                    if (!st.count(word))
                        continue;

                    // First time reaching this word
                    if (!dist.count(word)) {
                        dist[word] = currentDist + 1;
                        q.push(word);
                        parent[word].push_back(
                            word.substr(0, i) + original + word.substr(i + 1)
                        );
                    }
                    // Another shortest way to reach this word
                    else if (dist[word] == currentDist + 1) {
                        parent[word].push_back(
                            word.substr(0, i) + original + word.substr(i + 1)
                        );
                    }
                }

                word[i] = original;
            }
        }

        if (!dist.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};