
// 203 移除链表元素

// 问题
// 删除链表中指定的元素(所有)

#include "listnode.h"

// 使用虚拟头节点更方便
void remove_elements(ListNode** pHead, int val)
{
  ListNode* dummyNode = new ListNode();
  ListNode* preNode = dummyNode;
  ListNode* pNode = *pHead;
  preNode->next = pNode;

  while (pNode) {
    ListNode* pNext = pNode->next;
    if (pNode->val == val) {
      preNode->next = pNext;
      delete pNode;
      pNode = nullptr;
    } else {
      preNode = pNode;
    }
    pNode = pNext;
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