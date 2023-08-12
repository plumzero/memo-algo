
// 112 路径总和

// 问题
// 找到一条从根节点到叶子节点的路径，使这个路径的节点总和等于目标值

#include "btree.h"
#include <vector>

bool traverse(BinTreeNode* node, std::vector<BinTreeNode*>& path, int& sum, int target)
{
  if (node == nullptr)
    return false;
  
  path.push_back(node);
  sum += node->val;

  if (node->left == nullptr && node->right == nullptr) {
    if (sum == target) {
      return true;
    } else {
      return false;
    }
  }
  
  if (node->left) {
    if (! traverse(node->left, path, sum, target)) {
      sum -= node->left->val;
      path.pop_back();
    }
  }

  if (node->right) {
    if (! traverse(node->right, path, sum, target)) {
      sum -= node->right->val;
      path.pop_back();
    }
  }

  return true;
}

//     5
//    / \
//   4   6
//  / \
// 1   2
//  \
//   7 
int main()
{
  {
    BinTreeNode* node5 = create_node(5);
    BinTreeNode* node4 = create_node(4);
    BinTreeNode* node6 = create_node(6);
    BinTreeNode* node1 = create_node(1);
    BinTreeNode* node2 = create_node(2);
    BinTreeNode* node7 = create_node(7);

    connect_node(node5, node4, node6);
    connect_node(node4, node1, node2);
    connect_node(node1, nullptr, node7);

    std::vector<std::vector<BinTreeNode*>> paths;
    std::vector<BinTreeNode*> path;
    int sum = 0;
  
    bool res = traverse(node5, path, sum, 11);

    printf("res=%d\n", res);
    printf("path.size=%lu\n", path.size());
    for (auto elem : path) {
      printf("%d ", elem->val);
    }
    printf("\n");

    destroy_tree(&node5);
  }

  return 0;
}