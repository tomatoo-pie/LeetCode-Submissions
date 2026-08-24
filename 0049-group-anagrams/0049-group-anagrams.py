class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        napp = {}

        for i in range (len(strs)):
            key = ''.join(sorted(strs[i]))

            if key not in napp:
                napp[key] = []

            napp[key].append(strs[i])
            
        return list(napp.values())