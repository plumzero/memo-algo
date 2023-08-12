
// 145 二叉树的后序遍历

#include "btree.h"
#include <stdio.h>
#include <stack>

void postorder(BinTreeNode* root)
{
  if (root != nullptr) {
    postorder_print(root->left);
    postorder_print(root->right);
    printf("%d ", root->val);
  }
}

void postorder2(BinTreeNode* root)
{
  if (root != nullptr) {
    std::stack<BinTreeNode*> _stack;
    
    BinTreeNode* node = root;
    BinTreeNode* rnode = nullptr;       // rnode 指向最近一次访问过的某子树的右节点(当然，实际程序中也会指向左边节点)
    while (node || _stack.size() > 0) {
      while (node) {
        _stack.push(node);
        node = node->left;
      }
      if (_stack.size() > 0) {
        node = _stack.top();
        if (node->right == nullptr || node->right == rnode) { // 如果 node 没有右孩子节点，或者右孩子节点已经访问过
          printf("%d ", node->val);
          rnode = node;
          node = nullptr;
          _stack.pop();
        } else {
          node = node->right;
        }
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

  postorder(node1);
  printf("\n");
  
  postorder2(node1);

  destroy_tree(&node1);

  return 0;
}