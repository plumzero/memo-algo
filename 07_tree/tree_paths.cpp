
// 257 二叉树的所有路径

// 问题
// 给出一棵二叉树，返回所有从根节点到叶子节点的路径

#include "btree.h"
#include <vector>

// 按照前序遍历的思路

// 感觉对于这种回溯应该都有某种固定的格式，比如一开始入栈，然后当满足某个条件时出栈，否则继续入栈
void traverse(BinTreeNode* node, std::vector<BinTreeNode*>& path, std::vector<std::vector<BinTreeNode*>>& paths)
{
  if (node == nullptr)
    return ;
  
  path.push_back(node);

  if (node->left == nullptr && node->right == nullptr) {
    paths.push_back(path);
    return ;
  }
  
  if (node->left) {
    traverse(node->left, path, paths);
    path.pop_back();
  }

  if (node->right) {
    traverse(node->right, path, paths);
    path.pop_back();
  }

  return ;
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
  
    traverse(node5, path, paths);

    printf("paths.size=%lu\n", paths.size());
    for (size_t i = 0; i < paths.size(); i++) {
      for (size_t j = 0; j < paths[i].size(); j++) {
        printf("%d ", paths[i][j]->val);
      }
      printf("\n");
    }

    destroy_tree(&node5);
  }

  return 0;
}