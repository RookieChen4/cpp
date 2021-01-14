#include <iostream>
using namespace std;
typedef struct LNode {
  int data;
  struct LNode *next;
}LNode, *LinkList;

// 不带头结点
// bool InitList(LinkList &L) {
//   L = NULL;
//   return true;
// }

// bool Empty(LinkList L) {
//   return (L == NULL);
// }

// bool ListInsert(LinkList &L,int i,int e) {
//  if(i < 1) return false;
//  if(i==1){
//    LNode *s =(LNode *)malloc(sizeof(LNode));
//    s->data = e;
//    s->next = L;
//    L = s;
//    return true;
//  }
//  LNode *p;
//  int j = 1;
//  p = L;
//  while(p!=NULL&&j < i - 1) {
//    p = p->next;
//    j++;
//  }
//  if(p == NULL) return false;
//  LNode *s = (LNode *)malloc(sizeof(LNode));
//  s->data = e;
//  s->next = p->next;
//  p->next = s;
//  return true;
// }

// 带头结点
bool InitList(LinkList &L) {
 L = (LNode *)malloc(sizeof(LNode));
 if(L == NULL) return false;
 L->next = NULL;
 return true;
}

bool Empty(LinkList L) {
  return (L->next == NULL);
}

bool ListInsert(LinkList &L,int i,int e) {
 if(i < 1) return false;
 LNode *p;
 int j = 0;
 p = L;
 while(p!=NULL&&j < i - 1) {
   p = p->next;
   j++;
 }
 if(p == NULL) return false;
 LNode *s = (LNode *)malloc(sizeof(LNode));
 s->data = e;
 s->next = p->next;
 p->next = s;
 return true;
}

// 后插操作
bool InsertNextNode(LNode *p, int e) {
  if(p == NULL) return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  if(s==NULL) return false;
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

// 前插操作
bool InsertPriorNode(LNode *p,int e) {
  if(p == NULL) return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  if(s==NULL) return false;
  s->next = p->next;
  p->next = s;
  s->data = p->data;
  p->data = e;
  return true;
}

bool ListDelete(LinkList &L, int i,int &e) {
  if(i<1) return false;
  LNode *p;
  int j = 0;
  p = L;
  while(p!=NULL&&j<i-1) {
    p = p->next;
    j++;
  }
  if(p==NULL) return false;
  if(p->next == NULL) return false;
  LNode *q= p->next;
  e = q->data;
  p->next = q->next;
  free(q);
  return true;
}

// 删除指定节点
bool DeleteNode(LNode *p) {
  if(p == NULL) return false;
  LNode *q= p->next;
  p->next = q->next;
  p->data = q->next->data;
  free(q);
  return true;
}

// 按位查找
LNode * GetElem(LinkList L,int i) {
  if(i < 0) return NULL;
  LNode *p;
  p = L;
  int j = 0;
  while(p!=NULL&& j < i) {
    p = p->next;
    j++;
  }
  return p;
}

// 按值查找
LNode * LocateElem(LinkList L,int e) {
  LNode * p = L->next;
  while(p !=NULL&&p->data != e) {
    p = p->next;
  }
  return p;
}

// 求表的长度
int Length(LinkList L) {
  int j = 0;
  LNode *p = L->next;
  while(p!=NULL) {
    p = p->next;
    j++;
  }
  return j;
}

//尾插法
LinkList List_TailInsert(LinkList &L) {
  int x;
  L = (LinkList)malloc(sizeof(LNode));
  LNode *s,*r = L;
  scanf("%d",&x);
  while(x!=9999) {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;
    scanf("%d",&x);
  }
  r->next = NULL;
  return L;
}

LinkList List_HeadInsert(LinkList &L) {
  int x;
  L = (LinkList)malloc(sizeof(LNode));
  LNode *s;
  L->next = NULL;
  scanf("%d",&x);
  while(x!=9999) {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = L->next;
    L->next = s;
    scanf("%d",&x);
  }
  return L;
}

// 头插法

int main() {
 LinkList L;
 InitList(L);
//  List_TailInsert(L);
 List_HeadInsert(L);
 cout << Length(L);
}