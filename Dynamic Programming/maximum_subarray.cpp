#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums);

private:
  int maxSum(vector<int> &nums, int low, int high) {
    if (low >= high) {
      return nums[low];
    }
    int m = low + (high - low) / 2;

    int left = maxSum(nums, low, m);
    int right = maxSum(nums, m + 1, high);
    int sum_left = 0, sum_right = 0;
    int left_max = numeric_limits<int>::min(),
        right_max = numeric_limits<int>::min();
    for (int i = m; i >= low; i--) {
      sum_left += nums.at(i);
      left_max = max(left_max, sum_left);
    }
    for (int i = m + 1; i <= high; i++) {
      sum_right += nums.at(i);
      right_max = max(right_max, sum_right);
    }

    return max(left_max + right_max, max(left, right));
  }
};

int Solution::maxSubArray(vector<int> &nums) {
  return maxSum(nums, 0, nums.size() - 1);
}

int main(int argc, char const *argv[]) {
  int n, num;
  cin >> n;
  vector<int> vec(n);
  for (size_t i = 0; i < n; i++) {
    cin >> vec[i];
  }
  cout << Solution().maxSubArray(vec);
  return 0;
}
