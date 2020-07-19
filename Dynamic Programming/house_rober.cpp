#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums);
};

int Solution::rob(vector<int> &nums) {
  if (nums.size() < 3) {
    if (nums.size() == 1)
      return nums[0];
    else if (nums.size() == 2)
      return max(nums.at(0), nums.at(1));
    else
      return 0;
  }

  int n = nums.size();
  int money[n + 1];
  money[0] = 0;
  money[1] = nums.at(0);
  money[2] = max(nums.at(1), money[1]);
  for (size_t i = 3; i <= n; i++) {
    money[i] = max(nums.at(i - 1) + money[i - 2], money[i - 1]);
  }
  return money[n];
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cout << Solution().rob(nums);
  return 0;
}
