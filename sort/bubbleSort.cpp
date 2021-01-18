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

// 从前往后排序
// void bubbleSort(int a[], int length) {
//   // 第一层循环表示要执行n-1次的冒泡
//   for(int i = 0; i < length - 1; i++) {
//     //用来判断这次冒泡是否发生过置换，如果没有就说明已经是有序的了
//     bool flag = false;
//     // 每一次冒泡都会确定一个元素的最终位置
//     for(int j = 0;j < length - 1 - i;j++) {
//       if(a[j] > a [j+1]) {
//         flag = true;
//         swap(a[j],a[j+1]);
//       }
//     }
//     if(flag == false) return;
//   }
// }

// 从后往前排序
void bubbleSort(int a[],int length) {
  for(int i = 0; i < length -1; i ++) {
    bool flag = false;
    for(int j = length - 1; j > i;j--) {
      if(a[j-1] > a[j]) {
        flag = true;
        swap(a[j-1],a[j]);
      }
    }
    if(flag == false) return;
  }
}

// 时间复杂度 最好和平均O(n^2)
int main() {
  int a[] = {1,3,6,1,2,3,5,8,7,9};
  int length = getArrayLen(a);
  bubbleSort(a, length);
  List(a,length);
  return 0;
}