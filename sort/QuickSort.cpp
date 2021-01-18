#include <iostream>
#include<vector>
#include<list>
using namespace std;
void List(int a[], int length) {
  for(int i = 0; i < length; i++) {
    cout << a[i]  << " ";
  }
}
int partition(int a[],int low,int high) {
  int pivot = a[low];
  while(low < high) {
    while(low < high&&a[high]>= pivot) high--;
    a[low] = a[high];
    while(low < high&&a[low] <= pivot) low++;
    a[high] = a[low];
  }
  a[low] = pivot;
  return low;
}
// 最好和平均的时间复杂度,空间复杂度 O(n*log^n), O(log^n) 最坏(如果序列已经有序是最坏情况) O(n^2),  O(n)
void QuickSort(int a[], int low, int high) {
  if(low < high) {
    int pivotpos = partition(a,low,high);
    QuickSort(a,low,pivotpos-1);
    QuickSort(a,pivotpos+1,high);
  }
}

int main() {
  int a[] = {1,3,6,1,2,3,5,8,7,9};
  QuickSort(a,0,9);
  List(a,10);
  return 0;
}