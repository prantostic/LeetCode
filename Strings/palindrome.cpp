#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		s.erase(remove_if(s.begin(), s.end(), [](char c) { return isspace(c) or ispunct(c); }), s.end());
		for (size_t i = 0; i < s.size() / 2; i++) {
			if (s.at(i) != s.at(s.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char const *argv[]) {
	string a;
	getline(cin, a);
	cout << Solution().isPalindrome(a) << endl;
	return 0;
}
