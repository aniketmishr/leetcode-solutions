class Solution:
    def numberOfSteps(self, num: int) -> int:
        step =0
        while num: 
            step+=1
            if num%2==0: num/=2
            else: num=num-1
        return step
               
