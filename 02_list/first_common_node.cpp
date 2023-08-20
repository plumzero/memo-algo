
// 52 两个链表的第一个公共节点

// 问题: 输入两个链表，找出它们的第一个公共节点。
// 例如如下的两个链表，其第一个公共节点的值是 6
// 1 -> 2 -> 3
//           ↓
//           6 -> 7
//           ↑
//      4 -> 5

// 分析:
// 依次遍历两个链表，得到各自的长度，计算长度的差值为 k 。长链表从头节点移动 k 步，之后
// 长, 短链表同时移动，直到遇到第一个公共节点为止。

// 关于代码优化:
// 1. 对于多次使用的操作，应该将其独立为一个函数，比如这里的获取链表的长度

#include <stdio.h>
#include "listnode.h"

int list_len(ListNode* pHead)
{
  ListNode* pNode = pHead;
  int len = 0;

  while (pNode) {
    len++;
    pNode = pNode->next;
  }

  return len;
}

ListNode* first_common_node(ListNode* pHead1, ListNode* pHead2)
{
  // assert(pHead1 != nullptr && pHead2 != nullptr);

  int len1 = list_len(pHead1);
  int len2 = list_len(pHead2);

  ListNode* pLong = pHead1;
  ListNode* pShort = pHead2;
  int diff = len1 - len2;
  
  if (len1 < len2) {
    pLong = pHead2;
    pShort = pHead1;
    diff = len2 - len1;
  }

  for (int i = 1; i <= diff; i++) {
    pLong = pLong->next;
  }

  while (pLong != pShort) {
    pLong = pLong->next;
    pShort = pShort->next;
  }

  return pLong;
}

int main()
{
  {
    ListNode* node1 = create_node(1);
    ListNode* node2 = create_node(2);
    ListNode* node3 = create_node(3);
    ListNode* node4 = create_node(4);
    ListNode* node5 = create_node(5);
    ListNode* node6 = create_node(6);
    ListNode* node7 = create_node(7);

    connect_node(node1, node2);
    connect_node(node2, node3);
    connect_node(node3, node6);
    connect_node(node6, node7);
    connect_node(node4, node5);
    connect_node(node5, node6);

    ListNode* node = first_common_node(node1, node4);
    if (node) {
      printf("%d\n", node->val);
    }
  }

  {
    ListNode* node1 = create_node(1);
    ListNode* node2 = create_node(2);
    ListNode* node3 = create_node(3);
    ListNode* node4 = create_node(4);
    ListNode* node5 = create_node(5);
    ListNode* node6 = create_node(6);
    ListNode* node7 = create_node(7);

    connect_node(node1, node2);
    connect_node(node2, node3);
    connect_node(node3, node6);
    connect_node(node6, node7);
    connect_node(node4, node5);
    connect_node(node5, node6);

    ListNode* node = first_common_node(node4, node1);
    if (node) {
      printf("%d\n", node->val);
    }
  }

  {
    ListNode* node = first_common_node(nullptr, nullptr);
    if (node) {
      printf("%d\n", node->val);
    }
  }

  {
    ListNode* node1 = create_node(1);
    ListNode* node = first_common_node(node1, nullptr);
    if (node) {
      printf("%d\n", node->val);
    }
  }

  {
    ListNode* node1 = create_node(1);
    ListNode* node = first_common_node(nullptr, node1);
    if (node) {
      printf("%d\n", node->val);
    }
  }

  return 0;
}