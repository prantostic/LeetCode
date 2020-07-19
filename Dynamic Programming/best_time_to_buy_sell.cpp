#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices);
};

int Solution::maxProfit(vector<int> &prices) {
  if (prices.size() == 0) {
    return 0;
  }
  int recorded_min = numeric_limits<int>::max();
  int current_min = prices.at(0);
  int current_profit = 0, recorded_profit = 0;
  int max_val = 0;
  for (size_t i = 0; i < prices.size(); i++) {
    if (prices.at(i) > current_min) {
      current_profit = prices.at(i) - current_min;
    } else if (prices.at(i) < current_min) {
      current_min = prices.at(i);
    }
    recorded_profit = max(recorded_profit, current_profit);
  }
  return recorded_profit;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (size_t i = 0; i < n; i++) {
    cin >> vec[i];
  }
  cout << Solution().maxProfit(vec);
  return 0;
}
