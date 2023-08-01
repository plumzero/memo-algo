
// 19 删除倒数第 k 个节点

// 问题
// 删除链表中倒数第 k 个节点(k 从 1 开始)

#include "listnode.h"

// 考虑使用虚拟头节点
void del_kth_from_end(ListNode** pHead, int k)
{
  ListNode* dummyNode = new ListNode();
  ListNode* preNode = dummyNode;
  ListNode* pNode = *pHead;
  preNode->next = pNode;

  ListNode* pFast = *pHead;
  ListNode* pSlow = *pHead;

  for (int i = 1; i <= k - 1; i++) {
    if (pFast->next == nullptr) {
      return ;
    }
    pFast = pFast->next;
  }

  while (pFast->next != nullptr) {
    pFast = pFast->next;
    preNode = pSlow;
    pSlow = pSlow->next;
  }

  preNode->next = pSlow->next;
  delete pSlow;

  *pHead = dummyNode->next;
  delete dummyNode;

  return ;
}

int main()
{
  {
    ListNode* head = create_list(6, 11, 22, 33, 44, 55, 66);
    del_kth_from_end(&head, 1);
    print_list(head);
    destroy_list(&head);
  }

  {
    ListNode* head = create_list(6, 11, 22, 33, 44, 55, 66);
    del_kth_from_end(&head, 3);
    print_list(head);
    destroy_list(&head);
  }

  {
    ListNode* head = create_list(6, 11, 22, 33, 44, 55, 66);
    del_kth_from_end(&head, 6);
    print_list(head);
    destroy_list(&head);
  }

  {
    ListNode* head = create_list(6, 11, 22, 33, 44, 55, 66);
    del_kth_from_end(&head, 7);
    print_list(head);
    destroy_list(&head);
  }

  {
    ListNode* head = create_list(1, 11);
    del_kth_from_end(&head, 2);
    print_list(head);
    destroy_list(&head);
  }

  return 0;
}