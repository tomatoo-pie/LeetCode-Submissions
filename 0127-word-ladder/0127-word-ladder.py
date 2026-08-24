from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        st = set() 
        for i in range(len(wordList)):
            st.add(wordList[i])
        
        q = deque()
        q.append((beginWord,1))

        while q:
            word, level = q.popleft()

            if(word==endWord):
                return level

            for i in range(len(word)):
                for j in range(26):
                    new_word = word[:i] + chr(ord('a') + j) + word[i+1:]
                    if new_word in st:
                        q.append((new_word,level+1))
                        st.remove(new_word)
        
        return 0

