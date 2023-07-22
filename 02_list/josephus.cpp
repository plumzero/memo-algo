

/**
 * 约瑟夫问题。
 * 有 n 个人，编号为 1，2，...,n 。围成一个圆圈，按照顺时针方向从编号为 k 的人从 1 开始报数，报数为 m 的
 * 人出列，他的下一个人重新开始从 1 报数，数到 m 的人出列，这样重复下去，直到所有的人都出列。
 * 编写一个算法，要求输入 n, k, m ，按照出列的顺序输出编号。
 *
 * 解决约瑟夫问题分为三个步骤:
 *  1. 建立一个具有 n 个节点的不带头结点的循环单链表，编号从 1 到 n
 *  2. 找到第 k 个结点，即第一个开始报数的人
 *  3. 编号为 k 的人从 1 开始报数，并开始计数，报到 m 的人出列，即将该节点删除。继续从下一个节点开始报数，
 *     直到最后一个节点被删除。
 * 
 * 因为涉及到节点的删除，所以考虑要定义 preNode 指针
 */

#include "listnode.h"

void josephus(ListNode* pHead, int n, int k, int m)
{
  if (n < k) {
    printf("长度错误\n");
    return ;
  }

  if (m <= 0) {
    printf("报号错误\n");
    return ;
  } 

  // 定位到编号 k
  ListNode* pNode = pHead;
  ListNode* preNode = nullptr;
  for (int i = 1; i < k; i++) {
    preNode = pNode;
    pNode = pNode->next;
  }

  while (pNode != pNode->next) {
    // 报 m 个数
    for (int i = 1; i < m; i++) {
      preNode = pNode;
      pNode = pNode->next;
    }
    ListNode* pNext = pNode->next;
    preNode->next = pNext;
    printf("%d ", pNode->val);
    delete pNode;
    pNode = nullptr;
    pNode = pNext;
  }

  return ;
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
    connect_node(node3, node4);
    connect_node(node4, node5);
    connect_node(node5, node6);
    connect_node(node6, node7);
    connect_node(node7, node1);

    josephus(node1, 7, 2, 3);
  }

  return 0;
}