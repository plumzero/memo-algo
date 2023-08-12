
// 110 平衡二叉树

// 问题
// 平衡二叉树: 每一个节点的左子树和右子树的高度差的绝对值不超过 1

// 分析
// 每遍历到一个节点，计算该节点左右子树的高度之差

#include "btree.h"
#include <algorithm>
#include <math.h>

int get_depth(BinTreeNode* node)
{
  if (node == nullptr)
    return 0;
  
  int left_height = get_depth(node->left);
  if (left_height == -1)
    return -1;
  
  int right_height = get_depth(node->right);
  if (right_height == -1)
    return -1;
  
  return abs(left_height - right_height > 1) ? -1 : 1 + std::max(left_height, right_height);
}

bool is_balanced(BinTreeNode* root)
{
  return get_depth(root) == -1 ? false : true;
}

int main()
{
  {
    //     5
    //    / \
    //   4   6
    //  / \
    // 1   2
    BinTreeNode* node5 = create_node(5);
    BinTreeNode* node4 = create_node(4);
    BinTreeNode* node6 = create_node(6);
    BinTreeNode* node1 = create_node(1);
    BinTreeNode* node2 = create_node(2);

    connect_node(node5, node4, node6);
    connect_node(node4, node1, node2);

    printf("is balanced: %d\n", is_balanced(node5));

    destroy_tree(&node5);
  }

  {
    //     5
    //    / \
    //   4   6
    //  / \
    // 1   2
    //  \
    //   7 
    BinTreeNode* node5 = create_node(5);
    BinTreeNode* node4 = create_node(4);
    BinTreeNode* node6 = create_node(6);
    BinTreeNode* node1 = create_node(1);
    BinTreeNode* node2 = create_node(2);
    BinTreeNode* node7 = create_node(7);

    connect_node(node5, node4, node6);
    connect_node(node4, node1, node2);
    connect_node(node1, nullptr, node7);

    printf("is balanced: %d\n", is_balanced(node5));

    destroy_tree(&node5);
  }

  return 0;
}