#include <iostream>
#include <regex>
#include <string>
using namespace std;

class Solution {
private:
	int convertToInt(string s) {
		if (s.length() == 0)
			return -1;
		bool isNegative = false;
		int i = 0;
		if (s.at(0) == '-') {
			isNegative = true;
			i++;
		} else if (s.at(0) == '+') {
			i++;
		}
		int n = 0;
		int maxInt = numeric_limits<int>::max();

		while (i < s.length()) {
			if ((maxInt - (s.at(i) - '0')) / 10 >= n) {
				n = n * 10 + (s.at(i) - '0');
			} else {
				if (isNegative) {
					return numeric_limits<int>::min();
				} else {
					return numeric_limits<int>::max();
				}
			}
			i++;
		}
		if (isNegative) n = -n;
		return n;
	}

public:
	int myAtoi(string str) {
		regex pattern(R"(^\s*([+-]?\d+).*)");
		smatch m;
		regex_search(str, m, pattern);
		if (m.size() == 2) {
			return convertToInt(m.str(1));
		}
		return 0;
	}
};

int main(int argc, char const *argv[]) {
	string s;
	getline(cin, s);
	cout << Solution().myAtoi(s);
	return 0;
}
