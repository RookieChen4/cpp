#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <charconv>
using namespace std;
void List(char a[]) {
  for(int i = 0; i < strlen(a); i++) {
    cout << a[i]  << " ";
  }
}
char getTop(char s[]) {
  int index = strlen(s);
  return s[index -1];
}
void pushStack(char s[],char e) {
  int index = strlen(s);
  s[index] = e;
}
void popStack(char s[],char &e) {
  int index = strlen(s);
  e = s[index -1];
  s[index -1] = 0;
}
bool isEmpty(char s[]) {
  return strlen(s) == 0;
}
bool ispriority(char a,char b,map<char, int> Emap) {
  return Emap[a] >= Emap[b];
}

void calculate(char t,char a, char b, char s[]) {
  char *temp;
  if(t == '+') {
    pushStack(s,(a - '0') + (b - '0') + '0');
  }
  if(t == '-') {
    pushStack(s,(a - '0') - (b - '0')+ '0');
  }
  if(t == '*') {
    pushStack(s,(a - '0') * (b - '0')+ '0');
  }
  if(t == '/') {
    pushStack(s,(a - '0') / (b - '0')+ '0');
  }
}

int main() {
  map<char, int> Emap;
  Emap['+'] = 0;
  Emap['-'] = 0;
  Emap['*'] = 1;
  Emap['/'] = 1;
  string e = "(1+1+(2*2)+1-1)/2";
  char Estack[20] = {0};
  char stack[20] = {0};
  char temp = '0';
  char a = '0';
  char b = '0';
  for(int i = 0; i < e.size();i++) {
    if(isdigit(e[i]) != 0) {
      pushStack(Estack,e[i]);
    }else if(e[i] == '('){
      pushStack(stack,e[i]);
    }else if(e[i] == ')') {
      popStack(stack,temp);
      while(temp != '(') {
        popStack(Estack,a);
        popStack(Estack,b);
        calculate(temp,b,a,Estack);
        popStack(stack,temp);
      }
    }else {
      while(!isEmpty(stack)&&getTop(stack) != '(') {
        if(ispriority(getTop(stack),e[i],Emap)) {
          popStack(stack,temp);
          popStack(Estack,a);
          popStack(Estack,b);
          calculate(temp,b,a,Estack);
        }
      }
      pushStack(stack,e[i]);
    }
  }
  while (strlen(stack) != 0) {
    popStack(stack,temp);
    popStack(Estack,a);
    popStack(Estack,b);
    calculate(temp,b,a,Estack);
    cout << Estack[0];
  }
  return 0;
}