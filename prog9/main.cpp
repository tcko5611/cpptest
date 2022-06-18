#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int> nums)
{
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;
  for (int i = 0; i < nums.size() - 2; ++i) {
    if ( i == 0 || (i > 0 && nums[i] != nums[i-1])) {
      int j = i + 1, k = nums.size() - 1, target = 0 - nums[i];
      while (j < k) {
        if (nums[j] + nums[k] == target) {
          vector<int> v {nums[i], nums[j], nums[k]};
          res.push_back(v);
          while (j < k && nums[j] == nums[j+1]) j++;
          while (j < k && nums[k] == nums[k-1]) k--;
          j++;
          k--;
        }
        else if (nums[j] + nums[k] < target) j++;
        else k--;
      }
    }
  }
  return res;
}

int main(int argc, char *argv[])
{
  vector<int> v{-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = threeSum(v);
  for (auto vv : res) {
    for (auto vvv : vv) {
      cout << vvv << ", ";
    }
    cout << endl;
  }
}
