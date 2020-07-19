#include <iostream>

using namespace std;
class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }
    int array[n + 1];
    for (size_t i = 0; i <= n; i++) {
      array[i] = -1;
    }
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;
    for (size_t i = 3; i <= n; i++) {
      array[i] = array[i - 2] + array[i - 1];
    }
    return array[n];
  }
};

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  cout << Solution().climbStairs(n);
  return 0;
}
