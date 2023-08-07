# Example 1:

# Input: nums = [1,2,3,1]
# Output: true

# Input: nums = [1,2,3,4]
# Output: false

# Input: nums = [1,1,1,3,3,4,3,2,4,2]
# Output: true

class Solution:
    def containsDuplicate(self, nums) -> bool:
        i = 0
        j = 0
        while i < len(nums):
          j = i + 1
          while j < len(nums):
            if [nums[j]] == nums[i]:
              return True
              
             
          


nums = [1,2,3,1]
s = Solution()
s.containsDuplicate(nums)