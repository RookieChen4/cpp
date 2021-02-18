#include<iostream>
using namespace std;
#include <stack>
#include <queue>

typedef struct TreeNode {
  int data;
  TreeNode *leftChild;
  TreeNode *rightChild;
}TreeNode;

class Tree {
  public:
    Tree();
    ~Tree() {};
    TreeNode* build(TreeNode *root,int val);
    void PreOrder(TreeNode *root);  //前序遍历 
    void PreOrder2(TreeNode *root);  //前序遍历(非递归)
    void PostOrder(TreeNode *root);  //后序遍历
    void PostOrder2(TreeNode *root);  //后序遍历(非递归)
    void InOrder(TreeNode *root);  //中序遍历
    void InOrder2(TreeNode *root);  //中序遍历(非递归)
    void LevelOrder(TreeNode *root); // 层次遍历
  private:
    void Release(TreeNode *bt);
};

Tree::Tree() {
}

TreeNode* Tree::build(TreeNode *root, int val) {
  if(root == NULL) {
    root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = val;
    root->leftChild = NULL;
    root->rightChild = NULL;
    return root;
  }
  if(val < root->data) root->leftChild = build(root->leftChild, val);
  else if(val > root->data) root->rightChild = build(root->rightChild, val);
  return root;
}

// 前序遍历
void Tree::PreOrder(TreeNode *root) {
  if (root != NULL)
	{
		cout << root->data << endl;
		PreOrder(root->leftChild);
		PreOrder(root->rightChild);
	}
}

// 前序遍历(非递归)
void Tree::PreOrder2(TreeNode *root) {
  stack<TreeNode*> s;
  TreeNode *temp = root;
  while (temp != NULL||!s.empty())
	{
		if(temp != NULL) {
      cout << temp->data << endl;
      s.push(temp);
      temp = temp->leftChild;
    } else {
      temp = s.top();
      temp = temp->rightChild;
      s.pop();
    }
	}
}

// 后序遍历
void Tree::PostOrder(TreeNode *root) {
  if (root != NULL)
	{
		PostOrder(root->leftChild);
		PostOrder(root->rightChild);
    cout << root->data << endl;
	}
}

// 后序遍历(非递归)
void Tree::PostOrder2(TreeNode *root) {
  stack<TreeNode*> s;
  TreeNode *node = root;
  TreeNode *temp;
  while (node != NULL || !s.empty())
	{
    if(node != NULL) {
      s.push(node);
      node = node->leftChild;
    }else {
      node = s.top();
      if(node->rightChild != NULL&&node->rightChild != temp) {
        node = node->rightChild;
      }else {
        cout << node->data << endl;
        s.pop();
        temp = node;
        node = NULL;
      }
    }
	}
}

// 中序遍历
void Tree::InOrder(TreeNode *root) {
  if (root != NULL)
	{
		InOrder(root->leftChild);
    cout << root->data << endl;
		InOrder(root->rightChild);
	}
}

void Tree::InOrder2(TreeNode *root) {
  stack<TreeNode*> s;
  TreeNode *node = root;
  while (node != NULL || !s.empty())
	{
    if(node != NULL) {
      s.push(node);
      node = node->leftChild;
    }else {
      node = s.top();
      cout << node->data << endl;
      s.pop();
      node = node->rightChild;
    }
	}
}

// 层次遍历
void Tree::LevelOrder(TreeNode *root) {
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()) {
    TreeNode *temp = q.front();
    q.pop();
    cout << temp->data << endl;
    if(temp->leftChild != NULL) q.push(temp->leftChild);
    if(temp->rightChild) q.push(temp->rightChild);
  }
}

int main() {
  Tree tree;
  TreeNode *root = NULL;
  root = tree.build(root, 2);
  root = tree.build(root, 1);
  root = tree.build(root, 3);
  tree.InOrder2(root);
  return 0;
}
