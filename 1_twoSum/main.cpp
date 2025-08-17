#include <unordered_map>
#include <vector>

// Using hash map rather than 2 loops (O(n^2) --> O(n))

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target);
};

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> hash;
  for (int i = 0; i < nums.size(); ++i) {
    int match = target - nums[i];
    if (hash.find(match) != hash.end())
      return {hash[match], i};
    hash[nums[i]] = i;
  }
  return {-1, -1};
}

#include <iostream>
int main() {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  Solution sol;
  auto result = sol.twoSum(nums, target);
  std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
}
