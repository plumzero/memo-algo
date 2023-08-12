
#include "btree.h"
#include <stdio.h>
#include <stack>

// 144 二叉树的前序遍历

// 递归写法
void preorder(BinTreeNode* root)
{
  if (root != nullptr) {
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
  }
}

// 栈写法
void preorder2(BinTreeNode* root)
{
  if (root != nullptr) {
    std::stack<BinTreeNode*> _stack;

    BinTreeNode* node = root;
    while (node || _stack.size() > 0) {
      while (node) {
        printf("%d ", node->val);
        _stack.push(node);
        node = node->left;
      }
      if (_stack.size() > 0) {
        node = _stack.top();
        _stack.pop();
        node = node->right;
      }
    }
    printf("\n");
  }
}

// 二叉树的前序遍历还有一种在代码上更简洁的写法，如下:
void preorder3(BinTreeNode* root)
{
  if (root != nullptr) {
    std::stack<BinTreeNode*> _stack;
    _stack.push(root);
    while (_stack.size() > 0) {
      BinTreeNode* node = _stack.top();
      _stack.pop();
      printf("%d ", node->val);
      if (node->right) _stack.push(node->right);
      if (node->left) _stack.push(node->left);
    }
    printf("\n");
  }
}
// 不过上面的这种格式，在应用到中序遍历或后序遍历时，风格不统一。
// 所以这里更建议使用 preorder2 的栈写法。

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

  preorder(node1);
  printf("\n");
  
  preorder2(node1);

  preorder3(node1);

  destroy_tree(&node1);

  return 0;
}