/*
 * =====================================================================================
 *
 *       Filename:  single_non_duplicate.cpp
 *
 *    Description:  540. Single Element in a Sorted Array.
 *                  https://leetcode.com/problems/single-element-in-a-sorted-array
 *
 *        Version:  1.0
 *        Created:  10/12/2021 22:24:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <vector>

class Solution {
 public:
  int singleNonDuplicate(std::vector<int>& nums) {
    int once = 0;
    for (const int val : nums) {
      once ^= val;
    }
    return once;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  const int once = Solution().singleNonDuplicate(nums);
  printf("single element is %d\n", once);
  return 0;
}
