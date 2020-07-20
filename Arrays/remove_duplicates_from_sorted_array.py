class Solution:
    def removeDuplicates(self, nums) -> int:
        for i in range(len(nums) - 1, 0, -1):
            if nums[i] == nums[i - 1]:
                nums.pop(i)


if __name__ == "__main__":
    nums = [int(x) for x in input().split()]
    Solution().removeDuplicates(nums)
    print(nums)
