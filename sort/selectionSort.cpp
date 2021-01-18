#include <iostream>
#include<vector>
#include<list>
using namespace std;
template <class T>
int getArrayLen(T& array)  //使用模板定义一个函数getArrayLen,该函数将返回数组array的长度
{ 
  return (sizeof(array) / sizeof(array[0]));
}
void List(int a[], int length) {
  for(int i = 0; i < length; i++) {
    cout << a[i]  << " ";
  }
}
void swap(int &a,int &b) {
  int t = b;
  b = a;
  a = t;
}

// 每次选出最小元素放到起始位置
void selectionSort(int a[],int length) {
  for(int i = 0; i < length-1;i++) {
    int minIndex = i;
    for(int j = i + 1; j < length; j++) {
      if(a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    swap(a[i],a[minIndex]);
  }
}

// 最好和平均的时间复杂度是 O(n^2)
int main() {
  int a[] = {1,3,6,1,2,3,5,8,7,9};
  int length = getArrayLen(a);
  selectionSort(a, length);
  List(a,length);
  return 0;
}