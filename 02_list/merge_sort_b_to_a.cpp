
/**
 * 存在两个单链表 A 和 B, 其中的元素都是非递减排列。现在将单链表 B 归并到单链表 A ，得到的单链表
 * A 中的元素的值仍然按照非递减排列。
 * 要求不申请额外空间。
 * 
 * 思路:
 * 可以认为是向链表 A 中不断地插入元素。
 * 因为插入元素需要知道插入位置的前一个节点，所以需要为链表 A 定义两个指针操作。
 */

#include "listnode.h"

/**
 * 硬记是记不下来的。如果是徒手写出来，其中一些细节极大可能没办法考虑到，从而导致出错。
 * 所以这必须得运行起来，然后借助工具调试。
 * FUCK!!! DAMN!!!
*/
ListNode* merge_sort_b_to_a(ListNode* pHead1, ListNode* pHead2)
{
  if (pHead1 == nullptr)
    return pHead2;
  if (pHead2 == nullptr)
    return pHead1;

  ListNode* pNode1 = pHead1;
  ListNode* preNode = nullptr;
  ListNode* pNode2 = pHead2;

  while (pNode1 && pNode2) {
    if (pNode1->val <= pNode2->val) {
      if (preNode == nullptr) {
        preNode = pNode1;
      } else {
        preNode->next = pNode1;
      }
      preNode = pNode1;
      pNode1 = pNode1->next;
    } else {
      ListNode* pNext2 = pNode2->next;
      if (preNode == nullptr) {
        preNode = pNode2;
        pHead1 = pNode2;
      } else {
        preNode->next = pNode2;
      }
      pNode2->next = pNode1;
      preNode = pNode2;
      pNode2 = pNext2;
    }
  }

  return pHead1;
}

int main()
{
  {
    ListNode* head1 = create_list(6, 2, 3, 7, 7, 8, 9);
    ListNode* head2 = create_list(6, 1, 4, 5, 5, 6, 8);
    ListNode* head = merge_sort_b_to_a(head1, head2);
    print_list(head);
    destroy_list(&head);
  }

  return 0;
}