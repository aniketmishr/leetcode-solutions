class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if len(nums)==0: 
           return -1
        pivot = 0
        while pivot<len(nums):
            left_array_sum = sum(nums[:pivot])
            right_array_sum = sum(nums[pivot:]) - nums[pivot]
            if left_array_sum==right_array_sum:
                return pivot
            pivot+=1
        return -1
