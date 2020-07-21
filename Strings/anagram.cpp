#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> chars;
		for (auto &&i : s) {
			auto th = chars.find(i);
			if (th == chars.end()) {
				chars.insert(make_pair(i, 1));
			} else {
				th->second++;
			}
		}
		for (auto &&i : chars) {
			cout << i.first << ": " << i.second << endl;
		}

		for (auto &&i : t) {
			auto th = chars.find(i);
			if (th == chars.end()) {
				return false;
			} else {
				th->second--;
				if (th->second == 0) {
					chars.erase(th);
				}
			}
		}
		return chars.size() == 0;
	}
};

int main(int argc, char const *argv[]) {
	string a, b;
	cin >> a >> b;
	cout << Solution().isAnagram(a, b) << endl;
	return 0;
}
