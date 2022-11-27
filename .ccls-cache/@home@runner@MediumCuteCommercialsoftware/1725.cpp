#include <iostream>
#include <stack>
using namespace std;

int N;
long long h[100003];
stack<int> s;
long long ans = 0;

void solve() {
  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> h[i];

  s.push(0);
  for (int i = 1; i <= N + 1; i++) {
    while (!s.empty() && h[s.top()] > h[i]) {
      int tmp = s.top();
      s.pop();
      ans = max(ans, h[tmp] * (i - s.top() - 1));
    }
    s.push(i);
  }
  cout << ans;
}

int main() {
  solve();
  return 0;
}