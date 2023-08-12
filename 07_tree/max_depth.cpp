
// 104 二叉树的最大深度

// 问题
// 求一棵二叉树的最大深度，根节点的深度为 1

// 按照后序遍历的思路，先计算左右子树的最大深度，然后比较得到二者较大值，将结果加 1 后作为当前节点的深度

#include "btree.h"
#include <queue>
#include <algorithm>

int max_depth(BinTreeNode* root)
{
  if (root == nullptr)
    return 0;
  
  int left_depth = max_depth(root->left);
  int right_depth = max_depth(root->right);
  
  int depth = 1 + std::max(left_depth, right_depth); // 1 表示加上当前节点
  return depth;
}

// 因为是对左右子树的操作，而不是对节点的操作，所以这里无法使用后序遍历的栈写法
// 可以参考对树状遍历的实现来计算最大深度
int max_depth2(BinTreeNode* root)
{
  if (root == nullptr)
    return 0;
  
  int cur = 1;
  int next = 0;
  int depth = 0;

  std::queue<BinTreeNode*> _queue;
  _queue.push(root);

  while (_queue.size() > 0) {
    BinTreeNode* node = _queue.front();
    _queue.pop();
    cur--;
    if (node->left) {
      _queue.push(node->left);
      next++;
    }
    if (node->right) {
      _queue.push(node->right);
      next++;
    }
    if (cur == 0) {
      cur = next;
      next = 0;
      depth += 1;
    }
  }

  return depth;
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

    printf("depth: %d\n", max_depth(node1));

    destroy_tree(&node1);
  }

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

    printf("depth: %d\n", max_depth2(node1));

    destroy_tree(&node1);
  }

  return 0;
}