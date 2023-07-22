
// 22 链表中倒数第 k 个节点

// 问题: 输入一个链表，输出该链表中倒数第 k 个节点。
// 例如一个链表有 6 个节点，从头节点开始，它们的值依次是 1 2 3 4 5 6 。这个链表的倒数
// 第 3 个节点是值为 4 的节点

// 分析:
// 定义两个指针 pa 和 pb 同时指向头节点，pa 指针先走 k-1 步，之后 pb 也开始遍历，始终保持
// 两个指针间隔为 k-1 步，当 pa 指针到达尾节点时，pb 指向的节点即为倒数第 k 个节点。
// 注意链表长度小于 k 的情况

#include <stdio.h>

#include "listnode.h"

ListNode* kth_from_end(ListNode* pHead, int k)
{
  // assert(pHead != nullptr && k > 0);

  ListNode *pFast, *pSlow;
  pFast = pSlow = pHead;

  // pFast 先走 k-1 步，保证 pFast 与 pSlow 间隔 k-1 步
  for (int i = 1; i < k; i++) {
    // 当 i = 1 时: 若 pFast->next 不等于 nullptr，则说明链表中存在倒数第 1 个节点；否则链表中不存在倒数第 1 个节点
    // 当 i = 2 时: 若 pFast->next 不等于 nullptr，则说明链表中存在倒数第 2 个节点；否则链表中不存在倒数第 2 个节点
    // 以此类推
    if (pFast->next == nullptr) {
      return nullptr;
    }
    pFast = pFast->next;
  }

  while (pFast->next != nullptr) {
    pFast = pFast->next;
    pSlow = pSlow->next;
  }

  return pSlow;
}

int main()
{
    {
        ListNode* head = create_list(6, 11, 22, 33, 44, 55, 66);
        ListNode* node = kth_from_end(head, 1);
        if (node != nullptr) {
            printf("%d\n", node->val);
        }
        destroy_list(&head);
    }

    {
        ListNode* head = create_list(6, 11, 22, 33, 44, 55, 66);
        ListNode* node = kth_from_end(head, 3);
        if (node != nullptr) {
            printf("%d\n", node->val);
        }
        destroy_list(&head);
    }

    {
        ListNode* head = create_list(6, 11, 22, 33, 44, 55, 66);
        ListNode* node = kth_from_end(head, 6);
        if (node != nullptr) {
            printf("%d\n", node->val);
        }
        destroy_list(&head);
    }

    {
        ListNode* head = create_list(6, 11, 22, 33, 44, 55, 66);
        ListNode* node = kth_from_end(head, 7);
        if (node != nullptr) {
            printf("%d\n", node->val);
        }
        destroy_list(&head);
    }

    {
        ListNode* head = create_list(1, 11);
        ListNode* node = kth_from_end(head, 2);
        if (node != nullptr) {
            printf("%d\n", node->val);
        }
        destroy_list(&head);
    }

    return 0;
}