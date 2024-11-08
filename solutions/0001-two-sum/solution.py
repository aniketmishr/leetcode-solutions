class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            x=target - nums[i]
            nums1=nums[i+1:]
            if x in nums1:
                return [i,(nums1.index(x))+i+1]
