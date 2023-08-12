
// 二叉树的树状遍历

#include "btree.h"
#include <stdio.h>
#include <queue>

void tree_order(BinTreeNode* root)
{
  if (root != nullptr) {
    std::queue<BinTreeNode*> _queue;
    _queue.push(root);
    int cur = 1;    // 开始时从根节点开始，根节点只有一个
    int next = 0;
    
    while (_queue.size() > 0) {
      BinTreeNode* node = _queue.front();
      _queue.pop();
      cur--;
      printf("%d ", node->val);
      if (node->left) {
        _queue.push(node->left);
        next++; 
      }
      if (node->right) {
        _queue.push(node->right);
        next++;
      }
      if (cur == 0) {
        printf("\n");
        cur = next;
        next = 0;
      }
    }
    printf("\n");
  }
}

//     1
//    / \
//   2   3
//  /   / \
// 4   5   6
//      \
//       7
int main()
{
  BinTreeNode* node1 = create_node(1);
  BinTreeNode* node2 = create_node(2);
  BinTreeNode* node3 = create_node(3);
  BinTreeNode* node4 = create_node(4);
  BinTreeNode* node5 = create_node(5);
  BinTreeNode* node6 = create_node(6);
  BinTreeNode* node7 = create_node(7);

  connect_node(node1, node2, node3);
  connect_node(node2, node4, nullptr);
  connect_node(node3, node5, node6);
  connect_node(node5, nullptr, node7);

  tree_order(node1);

  destroy_tree(&node1);

  return 0;
}