#include <iostream>
using namespace std;
#define MaxSize 10
//顺序存储
typedef struct {
  int font,rear;
  int data[MaxSize];
  int size;
}SqQueue;

void InitQueue(SqQueue &Q) {
  Q.font = 0;
  Q.rear = 0;
  Q.size = 0;
}

bool EnQueue(SqQueue &Q,int e) {
  if(Q.size == MaxSize) {
    return false;
  }
  Q.data[Q.rear] = e;
  Q.rear = (Q.rear+1) % MaxSize;
  Q.size++;
  return true;
}

bool DeQueue(SqQueue &Q,int &e) {
  if(Q.size == 0) {
    return false;
  }
  e = Q.data[Q.font];
  Q.font = (Q.font+1) % MaxSize;
  Q.size--;
  return true;
}

int main() {
  SqQueue Q;
  InitQueue(Q);
  int e = 9999;
  DeQueue(Q,e);
  cout << e;
  DeQueue(Q,e);
  cout << e;
  return 0;
}