from collections import Counter


class Solution:
    def singleNumber(self, nums) -> int:
        occurences = Counter(nums)
        for key, val in occurences.items():
            if val == 1:
                return key


if __name__ == "__main__":
    nums = [int(x) for x in input().split()]
    print(Solution().singleNumber(nums))
