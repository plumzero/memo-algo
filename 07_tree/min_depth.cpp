
// 111 二叉树的最小深度

// 问题
// 求一棵二叉树的最小深度，根节点的深度为 1
// 最小深度: 从根节点到最近叶子节点的最短路径上的节点数量

// 示例
//     5
//    / \
//   4   6
//  / \
// 1   2
// 上面的二叉树的最小深度为 2

#include "btree.h"
#include <queue>
#include <algorithm>

// 与计算二叉树中计算度为 1 的个数的方法类似
int min_depth(BinTreeNode* root)
{
  if (root == nullptr)
    return 0;

  // 如果左子树为空，右子树不为空，则说明最小深度是右子树的最小深度 + 1
  if (root->left == nullptr && root->right != nullptr)
    return 1 + min_depth(root->right);

  // 如果右子树为空，左子树不为空，则说明最小深度是左子树的最小深度 + 1  
  if (root->left != nullptr && root->right == nullptr)
    return 1 + min_depth(root->left);

  // 左右子树均非空，分别计算左右子树最小深度，取较小值
  return 1 + std::min(min_depth(root->left), min_depth(root->right));
}

// 还是采用队列的处理方式更容易理解一些
int min_depth2(BinTreeNode* root)
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

    // 判断是否为叶子节点。如果是叶子节点，就返回
    if (node->left == nullptr && node->right == nullptr) {
      return depth + 1;
    }

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

    printf("depth: %d\n", min_depth(node1));

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

    printf("depth: %d\n", min_depth2(node1));

    destroy_tree(&node1);
  }

  return 0;
}