
// 101 对称二叉树

// 问题
// 给出一棵二叉树，判断其是不是中心轴对称的

// 思考: 不仅二叉的结构是中心轴对称的，而且相应的值也是中心轴对称的

#include "btree.h"
#include <queue>
#include <stack>

// 这里采用后序遍历的思路来实现
bool _is_symmetrical(BinTreeNode* left, BinTreeNode* right)
{
  if (left == nullptr && right == nullptr)
    return true;

  if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr))
    return false;
  
  if (left->val != right->val)  // 如果按照 left->val == right->val 进行判断，则后续无法对各自的子树进行判断
    return false;

  // 以上的条件都判断完毕之后，才可以递归比较各自的子树

  // 按照是否对称的比较，left 的左子树应该与 right 的右子树比较，而 left 的右子树应该与 right 的左子树比较
  bool outside = _is_symmetrical(left->left, right->right);
  bool inside = _is_symmetrical(left->right, right->left);
  
  // 内外侧分别判断完毕之后，再根据返回值来判断两棵子树的内外侧节点是否均相等
  bool is_same = outside && inside;

  return is_same;
}

bool is_symmetrical(BinTreeNode* root)
{
  if (root == nullptr)
    return true;
  
  return _is_symmetrical(root->left, root->right);
}

// 这里也可以使用迭代法。但这里的迭代法不能采用后序遍历的迭代写法，因为它不是对一个节点进行"遍历"，而是对两个节点进行"遍历"

// 队列的写法: 每次入队时，必须保证"成双入队"
bool is_symmetrical_queue(BinTreeNode* root)
{
  if (root == nullptr)
    return true;

  std::queue<BinTreeNode*> _queue;
  _queue.push(root->left);
  _queue.push(root->right);

  while (_queue.size() > 0) {
    BinTreeNode* left = _queue.front();
    _queue.pop();
    BinTreeNode* right = _queue.front();
    _queue.pop();

    // 再按照递归终止条件的判断逻辑进行处理
    if (left == nullptr && right == nullptr) {
      continue;
    }
    if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr))
      return false;
    if (left->val != right->val)
      return false;
    
    _queue.push(left->left);
    _queue.push(right->right);
    _queue.push(left->right);
    _queue.push(right->left);
  }
  
  return true;
}

// 栈的写法: 与队列无异
bool is_symmetrical_stack(BinTreeNode* root)
{
  if (root == nullptr)
    return true;

  std::stack<BinTreeNode*> _stack;
  _stack.push(root->left);
  _stack.push(root->right);

  while (_stack.size() > 0) {
    BinTreeNode* left = _stack.top();
    _stack.pop();
    BinTreeNode* right = _stack.top();
    _stack.pop();

    // 再按照递归终止条件的判断逻辑进行处理
    if (left == nullptr && right == nullptr) {
      continue;
    }
    if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr))
      return false;
    if (left->val != right->val)
      return false;
    
    _stack.push(left->left);
    _stack.push(right->right);
    _stack.push(left->right);
    _stack.push(right->left);
  }
  
  return true;
}

//      1
//     /  \
//    2    2
//   / \   / \
//  3   4 4   3
// / \       / \
// 5  6     6   5

int main()
{
  {
    BinTreeNode* node1 = create_node(1);
    BinTreeNode* node2 = create_node(2);
    BinTreeNode* node3 = create_node(2);
    BinTreeNode* node4 = create_node(3);
    BinTreeNode* node5 = create_node(4);
    BinTreeNode* node6 = create_node(4);
    BinTreeNode* node7 = create_node(3);
    BinTreeNode* node8 = create_node(5);
    BinTreeNode* node9 = create_node(6);
    BinTreeNode* node10 = create_node(6);
    BinTreeNode* node11 = create_node(5);

    connect_node(node1, node2, node3);
    connect_node(node2, node4, node5);
    connect_node(node4, node8, node9);
    connect_node(node3, node6, node7);
    connect_node(node7, node10, node11);

    printf("is symmetrical: %d\n", is_symmetrical(node1));

    destroy_tree(&node1);
  }

  {
    BinTreeNode* node1 = create_node(1);
    BinTreeNode* node2 = create_node(2);
    BinTreeNode* node3 = create_node(2);
    BinTreeNode* node4 = create_node(3);
    BinTreeNode* node5 = create_node(4);
    BinTreeNode* node6 = create_node(4);
    BinTreeNode* node7 = create_node(3);
    BinTreeNode* node8 = create_node(5);
    BinTreeNode* node9 = create_node(6);
    BinTreeNode* node10 = create_node(6);
    BinTreeNode* node11 = create_node(5);

    connect_node(node1, node2, node3);
    connect_node(node2, node4, node5);
    connect_node(node4, node8, node9);
    connect_node(node3, node6, node7);
    connect_node(node7, node10, node11);

    printf("is symmetrical: %d\n", is_symmetrical_queue(node1));

    destroy_tree(&node1);
  }

  {
    BinTreeNode* node1 = create_node(1);
    BinTreeNode* node2 = create_node(2);
    BinTreeNode* node3 = create_node(2);
    BinTreeNode* node4 = create_node(3);
    BinTreeNode* node5 = create_node(4);
    BinTreeNode* node6 = create_node(4);
    BinTreeNode* node7 = create_node(3);
    BinTreeNode* node8 = create_node(5);
    BinTreeNode* node9 = create_node(6);
    BinTreeNode* node10 = create_node(6);
    BinTreeNode* node11 = create_node(5);

    connect_node(node1, node2, node3);
    connect_node(node2, node4, node5);
    connect_node(node4, node8, node9);
    connect_node(node3, node6, node7);
    connect_node(node7, node10, node11);

    printf("is symmetrical: %d\n", is_symmetrical_stack(node1));

    destroy_tree(&node1);
  }

  return 0;
}