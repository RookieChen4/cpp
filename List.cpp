#include <iostream>
#include <stdio.h>
using namespace std;
#define InitSize 10
typedef struct {
	int *data;
	int length;
	int MaxSize;
}SqList;
void InitList(SqList &L) {
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}
void IncreaseSize(SqList &L,int len) {
	int *temp = L.data;
	L.data = (int *)malloc((L.MaxSize + len)*sizeof(int));
	for(int i = 0; i < L.length; i++) {
		L.data[i] = temp[i];
	}
	L.MaxSize = L.MaxSize + len;
	free(temp);
}
bool ListInsert(SqList &L,int i,int e) {
	if(i<i || i> L.length+1){
		return false;
	}
	if(L.length >= L.MaxSize) {
		return false;
	}
	for(int j = L.length; j >=i; j--) {
		L.data[j] = L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
}
bool ListDelete(SqList &L,int i,int &e) {
	if(i<i || i> L.length+1){
		return false;
	}
	e = L.data[i-1];
	for(int j = i; j < L.length;j++) {
		L.data[i-1] = L.data[i];
	}
	L.length--;
	return true;
}

int ListFindIndex(SqList L,int i) {
	return L.data[i-1];
}

int ListFindElement(SqList L,int e) {
	for(int i = 0; i < L.length; i++) {
		if(L.data[i] == e) return i+1;
	}
	return 0;
}
	
int main()
{
	SqList L;
	InitList(L);
	for(int i=0; i < L.MaxSize; i++) {
		L.data[i] = i;
		L.length = L.MaxSize;
	}
	IncreaseSize(L,5);
	for(int i=0; i < L.MaxSize - 2; i++) {
		L.data[i] = i;
		L.length = L.MaxSize - 2;
	}
	ListInsert(L,10,99);
	cout << L.data[9] << endl;
	int e;
	ListDelete(L,10,e);
	cout << e << endl;
	int t = ListFindIndex(L,10);
	cout << t << endl;
	cout << ListFindElement(L,1) << endl;
   return 0;
}