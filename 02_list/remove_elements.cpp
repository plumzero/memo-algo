
// 203 移除链表元素

// 问题
// 删除链表中指定的元素(所有)

#include "listnode.h"

// 需要考虑特殊的头节点情况
// 使用虚拟头节点更方便
void remove_elements(ListNode** pHead, int val)
{
  ListNode* dummyNode = new ListNode();
  ListNode* preNode = dummyNode;
  ListNode* pNode = *pHead;
  preNode->next = pNode;

  while (pNode) {
    if (pNode->val == val) {
      ListNode* pNext = pNode->next;
      preNode->next = pNext;
      delete pNode;
      pNode = pNext;
    } else {
      preNode = pNode;
      pNode = pNode->next;
    }
  }

  *pHead = dummyNode->next;
  delete dummyNode;
}

int main()
{
  {
    ListNode* head = create_list(4, 1, 4, 2, 4);
    remove_elements(&head, 4);
    print_list(head);
    destroy_list(&head);
  }

  {
    ListNode* head = create_list(4, 1, 4, 2, 4);
    remove_elements(&head, 1);
    print_list(head);
    destroy_list(&head);
  }

  return 0;
}