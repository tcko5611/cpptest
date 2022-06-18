#include <vector>
#include <string>
#include <iostream>

using namespace std;

void printRecurr(vector<int> &a, vector<int> ans, int r, int n)
{
  if (r == n) {
    for (auto & e: a) {
      cout << e;
    }
    cout << endl;
  }
  for (int i = r; i < n; ++i) {
    // ans.push_back(a[i]);
    swap(a[r], a[i]);
    printRecurr(a, ans, r+1, n);
    // ans.pop_back();
    swap(a[r], a[i]);
  }
}

int main(int argc, char *argv[])
{
  int n;
  cin >> n;
  vector<int> a(n, 0);
  vector<int> ans;
  for (int i = 0; i < a.size(); ++i) {
    a[i] = i+1;
  }
  printRecurr(a, ans, 0, n);
  return 0;
}
