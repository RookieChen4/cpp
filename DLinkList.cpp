#include <iostream>
using namespace std;
typedef struct DNode {
  int data;
  struct DNode *prior,*next;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList &L) {
  L = (DNode *)malloc(sizeof(DNode));
  if(L == NULL) return false;
  L->prior = NULL;
  L->next = NULL;
  return true;
}

// 插入到指定结点
bool InsertNextNode(DNode *p, DNode *s) {
  if(p == NULL || s == NULL) return false;
  s->next = p->next;
  s->prior = p;
  // 判断是否是最后一个结点
  if(p->next != NULL) p->next->prior = s;
  p->next = s;
  return true;
}


// 删除后继结点
bool DeleteNextNode(DNode *p) {
  if(p == NULL) return false;
  if(p->next == NULL) return false;
  DNode *q = p->next;
  p->next = q->next;
  if(q->next != NULL) q->next->prior = p;
  free(q);
  return true;
}

//清空链表
void DestoryList(DLinkList &L) {
  while(L->next != NULL) {
    DeleteNextNode(L);
  }
  free(L);
  L = NULL;
}

// 遍历
void forList(DLinkList L) {
  DNode *p = L;
  while(p->next != NULL) {
    p = p->next;
    cout << p->data;
  }
}

int main() {
  DLinkList L;
  InitDLinkList(L);
  for(int i = 0; i < 10; i++) {
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->next = NULL;
    s->prior = NULL;
    s->data = i;
    InsertNextNode(L, s);
  }
  DeleteNextNode(L);
  forList(L);
}