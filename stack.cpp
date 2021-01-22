#include<iostream>
using namespace std;
#define MaxSize 10
struct StackNode{
  int data;
  struct StackNode *next;
};

typedef struct {
  struct StackNode *top;
  int length;
}LineStack;

// 带头节点
void InitLineStack(LineStack &s) {
  s.length = 0;
  s.top = NULL;
}

bool isEmpty(LineStack s) {
  return s.length == 0;
}

bool push(LineStack &s,int e) {
  if(s.length >= MaxSize) return false;
  StackNode *sn = (StackNode *)malloc(sizeof(StackNode));
  sn->data = e;
  sn->next = s.top;
  s.top = sn;
  s.length ++;
  return true;
}

bool pop(LineStack &s) {
  if(isEmpty(s)) return false;
  cout << s.top->data;
  s.top = s.top->next;
  return true;
}


int main() {
  LineStack s;
  InitLineStack(s);
  push(s,1);
  push(s,2);
  push(s,3);
  pop(s);
  pop(s);
  pop(s);
}