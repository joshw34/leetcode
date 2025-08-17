#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

 private:
  int processNode(ListNode** l);
  void addResultNode(ListNode** result, ListNode** temp, int value);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* result = nullptr;
  ListNode* temp = nullptr;
  int sum = 0;
  int carry = 0;
  while (l1 || l2 || carry) {
    sum = carry + (l1 ? processNode(&l1) : 0) + (l2 ? processNode(&l2) : 0);
    carry = sum / 10;
    addResultNode(&result, &temp, sum % 10);
  }
  return result;
}

int Solution::processNode(ListNode** l) {
  int value = (*l)->val;
  *l = (*l)->next;
  return value;
}

void Solution::addResultNode(ListNode** result, ListNode** temp, int value) {
  ListNode* current = new ListNode(value);
  if (!*result)
    *result = *temp = current;
  else {
    (*temp)->next = current;
    (*temp) = (*temp)->next;
  }
}

void printResult(ListNode* l) {
  ListNode* temp = l;
  while (temp) {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

void deleteLists(ListNode* l) {
  ListNode* temp;
  while (l) {
    temp = l->next;
    delete l;
    l = temp;
  }
}

int main() {
  ListNode* temp;

  ListNode* l1 = new ListNode(2);
  temp = l1;
  temp->next = new ListNode(4);
  temp = temp->next;
  temp->next = new ListNode(3);

  ListNode* l2 = new ListNode(5);
  temp = l2;
  temp->next = new ListNode(6);
  temp = temp->next;
  temp->next = new ListNode(4);

  Solution sol;

  auto result = sol.addTwoNumbers(l1, l2);
  deleteLists(l1);
  deleteLists(l2);
  printResult(result);
  deleteLists(result);
}
