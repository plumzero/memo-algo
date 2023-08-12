
// 102 二叉树的层序遍历

#include "btree.h"
#include <stdio.h>
#include <queue>

void level_order(BinTreeNode* root)
{
  if (root != nullptr) {
    std::queue<BinTreeNode*> _queue;
    _queue.push(root);
    
    while (_queue.size() > 0) {
      BinTreeNode* node = _queue.front();
      _queue.pop();
      printf("%d ", node->val);
      if (node->left) {
        _queue.push(node->left);
      }
      if (node->right) {
        _queue.push(node->right);
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

  level_order(node1);

  destroy_tree(&node1);

  return 0;
}