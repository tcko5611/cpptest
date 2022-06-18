#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
  int v = 0;
  while(1) {
    std::cin >> v;
    int A = 0, B = 0;
    int i = 0;
    while (v) {
      int m = v % 10;
      A += m;
      v /= 10;
      m = v % 10;
      B += m;
      v /= 10;
    }
    std::cout << std::abs(A-B) << std::endl;
  }
  return 0;
}
