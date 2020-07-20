#include <algorithm>
#include <exception>
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
	int recorded_min = 0;
	int current_min = 0;
	int current_profit = 0, recorded_profit = 0;

	for (size_t i = 1; i < prices.size(); i++) {
		if (prices.at(i) > prices.at(i - 1)) {
			current_profit = prices.at(i) - prices.at(current_min);
			if (prices.at(i) - prices.at(recorded_min) <= current_profit) {
				recorded_min = current_min;
			}
		} else if (prices.at(i) < prices.at(i - 1)) {
			recorded_profit += current_profit;
			current_min = i;
			current_profit = 0;
		}
	}
	return recorded_profit + current_profit;
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
