#include <iostream>
#include <cstring>
using namespace std;
template <class T>
int getLength(T& array)  //使用模板定义一个函数getArrayLen,该函数将返回数组array的长度
{ 
  return (sizeof(array) / sizeof(array[0]));
}

void List(char a[]) {
  for(int i = 0; i < strlen(a); i++) {
    cout << a[i]  << " ";
  }
}

//朴素的模式匹配算法 最坏时间复杂度O(m*n)
int pattern(char s[],char t[]) {
  int i = 0;
  int j = 0;
  int sl = strlen(s);
  int tl = strlen(t);
  while(i < sl && j < tl) {
    if(s[i] == t[j]) {
      i++;
      j++;
    }else {
      i = i - j + 1;
      j = 0;
    }
  }
  if(j == tl) {
    return i - j;
  }
  return -1;
}

// Kmp
int Kmp(char s[],char t[],int next[]) {
  int i = 0;
  int j = 0;
  int sl = strlen(s);
  int tl = strlen(t);
  while(i < sl && j < tl) {
    if(j == -1 || s[i] == t[j]) {
      i++;
      j++;
    }else {
      j = next[j];
    }
  }
  if(j == tl) return i-j;
  return -1;
}

void getNext(char s[],int next[]) {
  next[0] = -1;
  int i = 0, j = -1;
	while (i < strlen(s) - 1)
	{
		if (j == -1 || s[i] == s[j])
		{
			++i;
			++j;
			next[i] = j;
		}	
		else
			j = next[j];
	}
}

//获取最长的前后缀
void getMatchPattern(char s[],int match[]) {
  match[0] = 0;
  int i = 1, j = 0;
  while(i <= strlen(s) - 1) {
    if(s[i] == s[j]) {
      j++;
      match[i] = j;
      i++;
    }
    else {
      if(j > 0) {
        j = match[j-1];
      } else {
        match[i] = 0;
        j = 0;
        i++;
      }
    }
  }
}

int main() {
  char S[] = "abbacba";
  char T[] = "abab";
  int next[4] = {'0'};
  int match[4] = {'0'};
  getNext(T,next);
  getMatchPattern(T,match);
  cout << match[3];
  // cout << Kmp(S,T,next);
  // cout << pattern(S,T);
}