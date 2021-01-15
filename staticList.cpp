#include <iostream>
using namespace std;
#define MaxSize 10
struct Node {
  int data;
  int next;
};

typedef struct {
  int data;
  int next;
} SLinkList[MaxSize];

int main() {
  struct Node a[MaxSize];
  cout << sizeof(a);
  SLinkList b;
  cout << sizeof(b);
}