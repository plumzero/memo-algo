
// 0226 反转二叉树
// 也叫做镜像二叉树或者交换左右子树

#include <stdio.h>
#include <stack>
#include <queue>
#include "btree.h"

void swap(BinTreeNode** node1, BinTreeNode** node2)
{
  BinTreeNode* node = *node1;
  *node1 = *node2;
  *node2 = node;
}

void mirror(BinTreeNode* root)
{
  if (root != nullptr ) {
    swap(&root->left, &root->right);
    mirror(root->left);
    mirror(root->right);
  }
}
// 上面的代码按照前序遍历的思想，先操作父节点，再分别镜像左右子树。
// 事实上，这里也可以使用后序遍历的思想。如下:
void mirror2(BinTreeNode* root)
{
  if (root != nullptr ) {
    mirror2(root->left);
    mirror2(root->right);
    swap(&root->left, &root->right);
  }
}
// 但是，不能按照中序遍历的方式去操作，因为这样可能会使某些左右子树反转两次

// 上面是代码是以递归方式实现的。也可以采用非递归实现，这里按照前序遍历的思路作为示例:
void mirror_stack(BinTreeNode* root)
{
  if (root == nullptr)
    return ;

  std::stack<BinTreeNode*> _stack;
  BinTreeNode* node = root;

  while (node || _stack.size() > 0) {
    while (node) {
      swap(&node->left, &node->right);
      _stack.push(node);
      node = node->left;
    }
    if (_stack.size() > 0) {
      node = _stack.top();
      _stack.pop();
      node = node->right;
    }
  }
}

// 其实也可以按照层序遍历的方式来进行处理
void mirror_level(BinTreeNode* root)
{
  if (root == nullptr)
    return ;
  
  std::queue<BinTreeNode*> _queue;
  _queue.push(root);

  while (_queue.size() > 0) {
    BinTreeNode* node = _queue.front();
    _queue.pop();
    swap(&node->left, &node->right);
    if (node->left) _queue.push(node->left);
    if (node->right) _queue.push(node->right);
  }
}

// 转换前
//      1
//    /  \
//   2    3
//  / \   /
// 4   5 6
// 转换后
//      1
//    /  \
//   3    2
//    \  / \
//     6 5  4

// 转换前
//      4
//    /  \
//   2    7
//  / \   / \
// 1   3 6   9
// 转换后
//      4
//    /  \
//   7    2
//  / \  / \
// 9   6 3  1

int main()
{
  {
    BinTreeNode* node1 = create_node(1);
    BinTreeNode* node2 = create_node(2);
    BinTreeNode* node3 = create_node(3);
    BinTreeNode* node4 = create_node(4);
    BinTreeNode* node5 = create_node(5);
    BinTreeNode* node6 = create_node(6);

    connect_node(node1, node2, node3);
    connect_node(node2, node4, node5);
    connect_node(node3, node6, nullptr);

    tree_print(node1);
    mirror(node1);
    tree_print(node1);

    destroy_tree(&node1);
  }

  {
    BinTreeNode* node4 = create_node(4);
    BinTreeNode* node2 = create_node(2);
    BinTreeNode* node7 = create_node(7);
    BinTreeNode* node1 = create_node(1);
    BinTreeNode* node3 = create_node(3);
    BinTreeNode* node6 = create_node(6);
    BinTreeNode* node9 = create_node(9);

    connect_node(node4, node2, node7);
    connect_node(node2, node1, node3);
    connect_node(node7, node6, node9);

    tree_print(node4);
    mirror2(node4);
    tree_print(node4);

    destroy_tree(&node4);
  }

  {
    BinTreeNode* node1 = create_node(1);
    BinTreeNode* node2 = create_node(2);
    BinTreeNode* node3 = create_node(3);
    BinTreeNode* node4 = create_node(4);
    BinTreeNode* node5 = create_node(5);
    BinTreeNode* node6 = create_node(6);

    connect_node(node1, node2, node3);
    connect_node(node2, node4, node5);
    connect_node(node3, node6, nullptr);

    tree_print(node1);
    mirror_stack(node1);
    tree_print(node1);

    destroy_tree(&node1);
  }

  {
    BinTreeNode* node4 = create_node(4);
    BinTreeNode* node2 = create_node(2);
    BinTreeNode* node7 = create_node(7);
    BinTreeNode* node1 = create_node(1);
    BinTreeNode* node3 = create_node(3);
    BinTreeNode* node6 = create_node(6);
    BinTreeNode* node9 = create_node(9);

    connect_node(node4, node2, node7);
    connect_node(node2, node1, node3);
    connect_node(node7, node6, node9);

    tree_print(node4);
    mirror_level(node4);
    tree_print(node4);

    destroy_tree(&node4);
  }

  return 0;
}