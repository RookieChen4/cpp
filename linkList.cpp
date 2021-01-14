#include <iostream>
using namespace std;
typedef struct LNode {
  int data;
  struct LNode *next;
}LNode, *LinkList;

// 不带头结点
bool InitList(LinkList &L) {
  L = NULL;
  return true;
}

int main() {
 LinkList L;
 InitList(L);
}