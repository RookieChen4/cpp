#include <iostream>
#include<vector>
#include<list>
using namespace std;
void List(int a[], int length) {
  for(int i = 0; i < length; i++) {
    cout << a[i]  << " ";
  }
}
// 将元素依次插入前面有序的列表
void InsertSort(int a[],int length) {
  for(int i = 0; i < length -1; i++) {
    int temp = a[i+1];
    for(int j = i; temp < a[j] ;j--) {
      a[j + 1] = a[j];
      a[j] = temp;
    }
  }
}

// 最好和平均的时间复杂度 O(n^2)
int main() {
  int a[] = {1,3,6,1,2,3,5,8,7,9};
  InsertSort(a,10);
  List(a,10);
  return 0;
}