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

void merge(int a[],int low,int mid,int high,int temp[]) {
  int t = 0;
  int leftIndex = low;
  int rightIndex = mid+1;
  while(leftIndex<=mid && rightIndex<=high) {
    if(a[leftIndex] < a[rightIndex]) {
      temp[t] = a[leftIndex];
      leftIndex ++;
    }else {
      temp[t] = a[rightIndex];
      rightIndex ++;
    }
    t++;
  }
  while(leftIndex<=mid) {
    temp[t] = a[leftIndex];
    t++;
    leftIndex ++;
  }
  while(rightIndex<=high) {
    temp[t] = a [rightIndex];
    t++;
    rightIndex ++;
  }
  t = 0;
  while(low <= high) {
    a[low++] = temp[t++];
  }
}

void mergeSort(int a[],int low,int high,int temp[]) {
  if(low < high) {
    int mid = (high + low) / 2;
    cout << low << high << endl;
    mergeSort(a,low,mid,temp);
    mergeSort(a,mid+1,high,temp);
    merge(a, low, mid, high,temp);
  }
}

// 归并排序的平均时间复杂度是O(n*log^n)
int main() {
  int a[] = {1,6,3,1,2,3,5,8,7,9};
  int length = getArrayLen(a);
  int *temp = (int *)malloc((length + 1) * sizeof(int));
  mergeSort(a,0,length-1,temp);
  List(a,length);
  // int b[] = {1,3,5,7,1,2,4,6};
  // int blength = getArrayLen(b);
  // int mid = (blength -1) /2;
  // merge(b,0,mid,blength -1,temp);
  // List(temp,length);
  return 0;
}