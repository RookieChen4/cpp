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

// 直接选择排序
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

// 向下调整
void AdjustDown(int a[],int i,int length) {
  int temp = a[i];
  for(int j = 2*i + 1; j < length; j=j*2+1) {
    if(j+1<length&&a[j+1]>a[j]) j++;
    if(temp > a[j]){
      break;
    }
    else {
      a[i] = a[j];
      i = j;
    }
  }
  a[i] = temp;
}

// 堆排序也是选择排序的一种

//建立堆的时间复杂度O(n)
void BuildMaxHeap(int a[],int length) {
  for(int i = length/2 -1; i >= 0;i--) {
    AdjustDown(a,i,length);
  }
}

// 直接选择排序最好和平均的时间复杂度是 O(n^2) 堆排序的时间复杂度O(n*log^n)
int main() {
  int a[] = {1,3,6,1,2,3,5,8,7,9};
  int b[] = {4,6,8,5,9};
  BuildMaxHeap(b,5);
  for(int i = 4; i > 0;i--) {
    swap(b[0],b[i]);
    AdjustDown(b,0,i);
  }
  List(b,5);
  int length = getArrayLen(a);
  selectionSort(a, length);
  List(a,length);
  return 0;
}