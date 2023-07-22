
#include "listnode.h"

int main()
{
  {
    printf("创建-打印-销毁\n");
    ListNode* head = create_list(6, 11, 22, 33, 44, 55, 66);

    print_list(head);

    destroy_list(&head);

    if (head == nullptr) {
      printf("ok\n");
    }
  }

  {
    printf("创建-打印-删除-打印-销毁\n");
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

    print_list(node1);

    del_node(&node1, node1);
    print_list(node1);

    del_node(&node1, node3);
    print_list(node1);

    del_node(&node1, node7);
    print_list(node1);

    destroy_list(&node1);
  }

  return 0;
}