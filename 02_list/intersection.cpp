
#include "listnode.h"

/**
 * 两个单链表，元素均由小到大排列。求两个链表的交集
 * 要求空间复杂度为 O(1)，且交集中不能有重复元素
*/

ListNode* intersection(ListNode* pHead1, ListNode* pHead2)
{
  if (pHead1 == nullptr || pHead2 == nullptr)
    return nullptr;

  ListNode* pNode1 = pHead1;
  ListNode* pNode2 = pHead2;
  ListNode* pHead = nullptr;
  ListNode* pCur = nullptr;

  while (pNode1 && pNode2) {
    if (pNode1->val > pNode2->val) {
      pNode2 = pNode2->next;
    } else if (pNode1->val < pNode2->val) {
      pNode1 = pNode1->next;
    } else {
      if (pHead == nullptr) {
        pHead = pNode1;
      } else {
        pCur->next = pNode1;
      }
      pCur = pNode1;
      pNode1 = pNode1->next; // 为了更易理解，这两行不要去掉
      pNode2 = pNode2->next;
    }

    // 去掉重复元素
    while (pNode1 && pCur && pCur->val == pNode1->val) {
      pNode1 = pNode1->next;
    }
    while (pNode2 && pCur && pCur->val == pNode2->val) {
      pNode2 = pNode2->next;
    }
  }

  // 将后面的元素全部丢弃
  pCur->next = nullptr;

  return pHead;
}

int main()
{
  {
    ListNode* head1 = create_list(9, 1, 1, 2, 3, 5, 7, 7, 9, 9);
    ListNode* head2 = create_list(8, 1, 2, 3, 6, 7, 8, 9, 10);
    ListNode* head = intersection(head1, head2);
    print_list(head);
    // destroy_list(&head);
  }

  return 0;
}