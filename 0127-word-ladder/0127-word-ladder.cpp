class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(int i = 0 ; i < wordList.size();i++){
            mp[wordList[i]] = 0;
        }

        char a = 'a';
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if(word == endWord) return level;

            for(int i = 0; i < word.length() ; i++){
                for(int j = 0; j < 26;j++){
                    char og =word[i];
                    word[i] = char(a + j);
                    if(mp.find(word) != mp.end() && mp[word] < 1){
                        q.push({word,level+1});
                        mp[word]++;
                    }
                    word[i] = og;
                }
            }
        }

        return 0;
    }
};