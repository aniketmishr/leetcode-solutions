class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        out_arr = []
        #fill prefixes in out_arr
        prefix=1
        for n in nums:
            out_arr.append(prefix)
            prefix*=n
        
        # multiply postfix 
        postfix=1
        for i in range(len(out_arr)-1,-1,-1):
            out_arr[i] = out_arr[i]*postfix
            postfix = postfix*nums[i]
            
        return out_arr
