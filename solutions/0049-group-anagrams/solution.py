class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        res = {} # mapping charCount to list of anagrams
        for s in strs:
            charCount = [0]*26
            for c in s:
                charCount[ord(c)-ord('a')] +=1
                
            res[tuple(charCount)] = res.get(tuple(charCount), []) + [s]
            
        return list(res.values())
