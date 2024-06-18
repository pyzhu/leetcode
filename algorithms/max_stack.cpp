/*
 * =====================================================================================
 *
 *       Filename:  max_stack.cpp
 *
 *    Description:  716. Max Stack. https://leetcode.com/problems/max-stack/
 *
 *        Version:  1.0
 *        Created:  06/15/2024 21:48:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <iterator>
#include <list>
#include <set>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Ordered set
class MaxStack1 {
 public:
  MaxStack1() {}

  void push(int x) {
    int index = 0;
    if (stack_.size() > 0) {
      index = stack_.rbegin()->first + 1;
    }
    stack_.emplace(std::make_pair(index, x));
    queue_.emplace(std::make_pair(x, index));
  }

  int pop() {
    auto back = std::prev(stack_.end());
    const int val = back->second;
    queue_.erase(std::make_pair(back->second, back->first));
    stack_.erase(back);
    return val;
  }

  int top() { return stack_.rbegin()->second; }

  int peekMax() { return queue_.rbegin()->first; }

  int popMax() {
    auto back = std::prev(queue_.end());
    const int val = back->first;
    stack_.erase(std::make_pair(back->second, back->first));
    queue_.erase(back);
    return val;
  }

 private:
  std::set<std::pair<int, int>> stack_;  // index, value
  std::set<std::pair<int, int>> queue_;  // value, index
};

// Priority queue
class MaxStack2 {
 public:
  MaxStack2() {}

  void push(int x) {
    int index = 0;
    if (!stack_.empty()) {
      index = stack_.back().first + 1;
    }
    stack_.emplace_back(std::make_pair(index, x));
    queue_.emplace_back(std::make_pair(x, index));
    std::push_heap(queue_.begin(), queue_.end());
  }

  int pop() {
    auto back = stack_.back();
    const int val = back.second;
    auto iter = std::find(queue_.begin(), queue_.end(), std::make_pair(back.second, back.first));
    if (iter != queue_.end()) {
      queue_.erase(iter);
    }
    if (!queue_.empty()) {
      std::make_heap(queue_.begin(), queue_.end());
    }
    stack_.pop_back();
    return val;
  }

  int top() { return stack_.back().second; }

  int peekMax() { return queue_.front().first; }

  int popMax() {
    auto& front = queue_.front();
    const int val = front.first;
    auto iter = std::find(stack_.begin(), stack_.end(), std::make_pair(front.second, front.first));
    if (iter != stack_.end()) {
      stack_.erase(iter);
    }
    std::pop_heap(queue_.begin(), queue_.end());
    queue_.erase(std::prev(queue_.end()));
    return val;
  }

 private:
  std::list<std::pair<int, int>> stack_;    // index, value
  std::vector<std::pair<int, int>> queue_;  // value, index
};

using MaxStack = MaxStack2;

TEST(MaxStack, push) {
  MaxStack* obj = new MaxStack();
  obj->push(5);
  obj->push(1);
  obj->push(5);
  EXPECT_EQ(obj->pop(), 5);
  EXPECT_EQ(obj->top(), 1);
  EXPECT_EQ(obj->peekMax(), 5);
  EXPECT_EQ(obj->popMax(), 5);
  EXPECT_EQ(obj->top(), 1);
}
