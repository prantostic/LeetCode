#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, bool> nonUnique;
		for (auto &&i : s) {
			auto th = nonUnique.find(i);
			if (th == nonUnique.end()) {
				nonUnique.insert(make_pair(i, false));
			} else {
				if (not th->second) {
					th->second = true;
				}
			}
		}
		for (size_t i = 0; i < s.size(); i++) {
			auto th = nonUnique.find(s.at(i));
			if (th != nonUnique.end()) {
				if (not th->second) {
					return i;
				}
			}
		}
		return -1;
	}
};

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;
	cout << Solution().firstUniqChar(s) << endl;
	return 0;
}
