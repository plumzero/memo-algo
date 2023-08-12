
// 度为 x 的节点个数

#include "btree.h"
#include <stdio.h>

// 度为 0 (叶子节点)的节点个数
int leaf_count(BinTreeNode* root)
{
  if (root == nullptr)
    return 0;

  if (root->left == nullptr && root->right == nullptr)
    return 1;
  
  int left_count = leaf_count(root->left);
  int right_count = leaf_count(root->right);

  return left_count + right_count;
}

// 度为 1 的节点个数
int degree_one_count(BinTreeNode* root)
{
  if (root == nullptr)
    return 0;

  // 当前的节点度为1(因为左子树为空)，还要加上右子树中度为 1 的节点个数
  if (root->left == nullptr && root->right != nullptr)
    return 1 + degree_one_count(root->right);

  // 同理
  if (root->left != nullptr && root->right == nullptr)
    return 1 + degree_one_count(root->left);
  
  // 若左右子树均不为空
  return degree_one_count(root->left) + degree_one_count(root->right);
}

// 度为 2 的节点个数
int degree_two_count(BinTreeNode* root)
{
  if (root == nullptr)
    return 0;

  // 注意，不能进行下面这样的判断，否则递归到这一层之后直接返回，root 的左右子树便不再遍历了
  // if (root->left != nullptr && root->right != nullptr)
  //   return 1;

  // 当前的节点度为2(因为左右子树均非空)，还要加上左右子树中度为 2 的节点个数
  if (root->left != nullptr && root->right != nullptr)
    return 1 + degree_two_count(root->left) + degree_two_count(root->right);

  return 0;
}

//     1
//    / \
//   2   3
//  /   / \
// 4   5   6
//    / \
//   7   8

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

  connect_node(node1, node2, node3);
  connect_node(node2, node4, nullptr);
  connect_node(node3, node5, node6);
  connect_node(node5, node7, node8);

  printf("0: %d\n", leaf_count(node1));
  printf("1: %d\n", degree_one_count(node1));
  printf("2: %d\n", degree_two_count(node1));

  destroy_tree(&node1);

  return 0;
}