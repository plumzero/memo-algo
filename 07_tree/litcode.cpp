
// 记录一些操作，时常练习

#include "btree.h"
#include <queue>
#include <algorithm>

// 返回二叉树最左边的节点
BinTreeNode* leftmost_node(BinTreeNode* root)
{
  if (root == nullptr)
    return nullptr;

  BinTreeNode* node = root;
  BinTreeNode* pre = nullptr;
  while (node) {
    pre = node;
    node = node->left;
  }

  return pre;
}

// 返回二叉树最右边的节点
BinTreeNode* rightmost_node(BinTreeNode* root)
{ 
  BinTreeNode* node = root;
  BinTreeNode* pre = nullptr;
  while (node) {
    pre = node;
    node = node->right;
  }

  return pre;
}

// 返回最底层最左边的元素
BinTreeNode* bottom_leftmost_node(BinTreeNode* root)
{
  if (root == nullptr)
    return nullptr;
  
  BinTreeNode* blnode = nullptr;
  BinTreeNode* pre = nullptr;  // 保存遍历中，最近一次具有左子树的父节点

  std::queue<BinTreeNode*> _queue;
  _queue.push(root);

  while (_queue.size() > 0) {
    BinTreeNode* node = _queue.front();
    _queue.pop();
    if (node->left) {
      _queue.push(node->left);
      pre = node->left;
    }
    if (node->right) {
      _queue.push(node->right);
    }
    if (pre == node) {
      blnode = node;
    }
  }

  return blnode;
}

// 返回某个节点的高度
int height(BinTreeNode* node)
{
  if (node == nullptr)
    return 0;

  int left_height = height(node->left);
  int right_height = height(node->right);

  // 因为 node != nullptr，所以 1 表示算上当前节点
  return 1 + std::max(left_height, right_height);
}

//     1
//    / \
//   2   3
//  /   / \
// 4   5   6
// \    \   \
//  7    8   9
//      / \
//     10  11

int main()
{
  BinTreeNode* node1 = create_node(1);
  BinTreeNode* node2 = create_node(2);
  BinTreeNode* node3 = create_node(3);
  BinTreeNode* node4 = create_node(4);
  BinTreeNode* node5 = create_node(5);
  BinTreeNode* node6 = create_node(6);
  BinTreeNode* node7 = create_node(7);
  BinTreeNode* node8 = create_node(8);
  BinTreeNode* node9 = create_node(9);
  BinTreeNode* node10 = create_node(10);
  BinTreeNode* node11 = create_node(11);

  connect_node(node1, node2, node3);
  connect_node(node2, node4, nullptr);
  connect_node(node3, node5, node6);
  connect_node(node4, nullptr, node7);
  connect_node(node5, nullptr, node8);
  connect_node(node6, nullptr, node9);
  connect_node(node8, node10, node11);

  BinTreeNode* lnode = leftmost_node(node1);
  printf("leftmost node: %d\n", lnode->val);

  BinTreeNode* rnode = rightmost_node(node1);
  printf("rightmost node: %d\n", rnode->val);

  BinTreeNode* blnode = bottom_leftmost_node(node1);
  printf("bottom leftmost node: %d\n", blnode->val);

  printf("node1 %d\n", height(node1));
  printf("node2 %d\n", height(node2));
  printf("node3 %d\n", height(node3));
  printf("node8 %d\n", height(node8));
  printf("node9 %d\n", height(node9));

  destroy_tree(&node1);

  return 0;
}