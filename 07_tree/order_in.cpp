
// 94 二叉树的中序遍历

#include "btree.h"
#include <stdio.h>
#include <stack>

void inorder(BinTreeNode* root)
{
  if (root != nullptr) {
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
  }
}

void inorder2(BinTreeNode* root)
{
  if (root != nullptr) {
    std::stack<BinTreeNode*> _stack;
    
    BinTreeNode* node = root;
    while (node || _stack.size() > 0) {
      while (node) {
        _stack.push(node);
        node = node->left;
      }
      if (_stack.size() > 0) {
        node = _stack.top();
        _stack.pop();
        printf("%d ", node->val);
        node = node->right;
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

  inorder(node1);
  printf("\n");
  
  inorder2(node1);

  destroy_tree(&node1);

  return 0;
}