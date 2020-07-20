class Solution:
    def containsDuplicate(self, nums) -> bool:
        return len(set(nums)) != len(nums)


if __name__ == "__main__":
    nums = [int(x) for x in input().split()]
    print(Solution().containsDuplicate(nums))
