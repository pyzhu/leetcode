/*
 * =====================================================================================
 *
 *       Filename:  reverse_nodes_in_k_group.cpp
 *
 *    Description:  25. Reverse Nodes in k-Group. Given a linked list, reverse the nodes
 *                  of a linked list k at a time and return its modified list.
 *
 *        Version:  1.0
 *        Created:  04/16/19 12:50:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}

  void printList() {
    ListNode* ptr = this;
    while (ptr != nullptr) {
      printf("%d%s", ptr->val, (ptr->next != nullptr ? " -> " : "\n"));
      ptr = ptr->next;
    }
  }

  static ListNode* convert(const std::vector<int>& nums) {
    ListNode dummy(0);
    ListNode* ptr = &dummy;
    for (const int val : nums) {
      ptr->next = new ListNode(val);
      ptr = ptr->next;
    }
    return dummy.next;
  }
};

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    ListNode* first = &dummy;
    ListNode* last = &dummy;
    ListNode* ptr = head;
    ListNode* tmp = nullptr;
    int count = 0;
    while (ptr != nullptr) {
      tmp = ptr->next;
      ptr->next = first->next;
      first->next = ptr;
      if (last->next != nullptr) {
        last = last->next;
      }

      count++;
      if ((count % k) == 0) {
        first = last;
      }
      ptr = tmp;
    }

    // Reverse count < k
    count %= k;
    if (count > 0) {
      ptr = first->next;
      first->next = nullptr;
      while (ptr != nullptr) {
        tmp = ptr->next;
        ptr->next = first->next;
        first->next = ptr;
        ptr = tmp;
      }
    }

    return dummy.next;
  }
};

int main(int argc, char* argv[]) {
  const std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ListNode* head = ListNode::convert(nums);
  head = Solution().reverseKGroup(head, 3);
  head->printList();
  return 0;
}
