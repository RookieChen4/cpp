#include<iostream>
#include <map>
using namespace std;
#define MaxSize 10
template <class T>
class myStack {
  private: 
    T data[MaxSize];
    int length;
  public:
    myStack();
    bool isEmpty();
    bool pushStack(T e);
    T popStack();
    T getTop();
    int getLength();
    void List();
};

template <class T>
myStack<T>::myStack() {
  this->length = 0;
}
template <class T>
bool myStack<T>::isEmpty() {
  return this->length == 0;
}

template <class T>
bool myStack<T>::pushStack(T e) {
  if(this->length == MaxSize) throw std::out_of_range("myStack<>::pushStack(): stack is full");
  this->data[this->length++] = e;
  return true;
}

template <class T>
T myStack<T>::popStack() {
  if(this->length == 0) throw out_of_range("myStack<>::popStack(): empty stack");
  return this->data[--this->length];
}

template <class T>
T myStack<T>::getTop() {
  if(this->length == 0) throw out_of_range("myStack<>::popStack(): empty stack");
  int i = this->length - 1;
  return this->data[i];
}

template <class T>
int myStack<T>::getLength() {
  return this->length;
}

template <class T>
void calculateOp(char opt,int a, int b, myStack<T> &s) {
  if(opt == '+') {
    s.pushStack(a+b);
  }
  if(opt == '-') {
    cout << a << b << endl;
    s.pushStack(a-b);
  }
  if(opt == '*') {
    s.pushStack(a * b);
  }
  if(opt == '/') {
    s.pushStack(a / b);
  }
}

template <class T>
void calculate(myStack<T> &s,char opt) {
  // cout << s.getTop() << s.getTop() << endl;
  calculateOp(opt,s.popStack(),s.popStack(),s);
}

bool ispriority(char a,char b,map<char, int> Emap) {
  return Emap[a] >= Emap[b];
}

int main() {
  map<char, int> Emap;
  Emap['+'] = 0;
  Emap['-'] = 0;
  Emap['*'] = 1;
  Emap['/'] = 1;
  myStack<int> EStack;
  myStack<char> OpStack;
  char opt = '0';
  string expression = "(1+1+(2*2)+1-1)/2";
  for(int i = 0; i < expression.size();i++) {
    if(isdigit(expression[i]) != 0) {
      EStack.pushStack(expression[i] - '0');
    }else if(expression[i] == '('){
      OpStack.pushStack(expression[i]);
    }else if(expression[i] == ')') {
      opt = OpStack.popStack();
      while(opt != '(') {
        calculate(EStack,opt);
        opt = OpStack.popStack(); 
      }
    }else {
      while(!OpStack.isEmpty()&&OpStack.getTop() != '(') {
        if(ispriority(OpStack.getTop(),expression[i],Emap)) {
          opt = OpStack.popStack(); 
          calculate(EStack,opt);
        }
      }
      OpStack.pushStack(expression[i]);
    }
  }
  while (!OpStack.isEmpty()) {
    opt = OpStack.popStack();
    calculate(EStack,opt);
  }
  cout << EStack.getTop();
  return 0;
}