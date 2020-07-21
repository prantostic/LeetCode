#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int maxInt = numeric_limits<int>::max();
		bool isNegative = false;
		if (x != abs(x)) {
			isNegative = true;
			x = -x;
		}

		int n = 0;
		while (x > 0) {
			if ((maxInt - x % 10) / 10 >= n) {
				n = n * 10 + x % 10;
			} else {
				return 0;
			}
			x /= 10;
		}
		if (isNegative) {
			n = -n;
		}
		return n;
	}
};

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	cout << Solution().reverse(n);
	return 0;
}
