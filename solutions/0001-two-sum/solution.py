class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        prevMap = {} # value : index 
        for i, n in enumerate(nums): 
            diff = target - n
            if diff in prevMap:  # O(1) -> constant 
                return [prevMap.get(diff), i]
            prevMap[n] = i
        return 

        
