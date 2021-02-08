#include<iostream>
using namespace std;
template <class T>
struct TreeNode {
  T data;
  TreeNode *firstChild;
  TreeNode *nextSibling;
};

template <class T>
class Tree {
  public:
    Tree();
    ~Tree() {};
    void PreOrder() { PreOrder(root); };  //前序遍历
    void PostOrder() { PostOrder(root); };  //后序遍历
  private:
    TreeNode *root;
    void Release(TreeNode *bt);
    void PreOrder(TreeNode *bt);
    void PostOrder(TreeNode *bt);
};

template <class T>
Tree<T>::Tree() {
}

int main() {
  Tree<int> tree;
  return 0;
}
