#include <iostream>
#include<vector>
#include<list>
using namespace std;
void List(int a[], int length) {
  for(int i = 0; i < length; i++) {
    cout << a[i]  << " ";
  }
}
// 将元素依次插入前面有序的列表（直接插入）
void InsertSort(int a[],int length) {
  for(int i = 0; i < length -1; i++) {
    int temp = a[i+1];
    for(int j = i; temp < a[j] ;j--) {
      a[j + 1] = a[j];
      a[j] = temp;
    }
  }
}

// 折半插入
void BInsertSort(int a[], int length) {
  int low,high,mid;
  for(int i = 0; i < length -1; i++) {
    int temp = a[i+1];
    low = 0;
    high = i;
    // 折半查找插入的位置
    while(low <= high) {
      mid = (low + high) / 2;
      if(a[mid] > temp) {
        high = mid - 1;
      }else {
        low = mid + 1;
      }
    }
    // 移动元素
    for(int j = i; j > high;j--) {
      a[j + 1] = a[j];
    }
    a[high + 1] = temp;
  }
}

// 希尔排序
void shellSort(int a[],int length) {
  for(int dk = length/2; dk>=1; dk=dk/2) {
    for(int i = 0; i < length - dk; i+=dk) {
      int temp = a[i + dk];
      for(int j = i; temp < a[j] ;j-=dk) {
        a[j + dk] = a[j];
        a[j] = temp;
      }
    }
  }
}

// 三种插入排序
// 最好和平均的时间复杂度 O(n^2)
int main() {
  int a[] = {10,11,8,14,6,5,4,3,2,1};
  shellSort(a,10);
  List(a,10);
  return 0;
}