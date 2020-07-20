class Solution:
    def rotate(self, nums, k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for _ in range(k):
            num = nums.pop(-1)
            nums.insert(0, num)


if __name__ == "__main__":
    k = int(input())
    nums = [int(x) for x in input().split()]
    Solution().rotate(nums, k)
    print(nums)
