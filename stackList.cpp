#include<iostream>
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
void calculate(myStack<T> s,char opt) {
  s.popStack();
  s.popStack();
}

int main() {
  myStack<int> EStack;
  myStack<char> OpStack;
  char opt = '0';
  string expression = "(1+1+(2*2)+1-1)/2";
  for(int i = 0; i < expression.size();i++) {
    if(isdigit(expression[i]) != 0) {
      EStack.pushStack(expression[i]);
    }else if(expression[i] == '('){
      OpStack.pushStack(expression[i]);
    }else if(expression[i] == ')') {
      opt = OpStack.popStack(); 
      while(opt != '(') {
        calculate(Estack,opt);
        opt = OpStack.popStack(); 
      }
    }else {
      while(!isEmpty()&&getTop(stack) != '(') {
        if(ispriority(getTop(stack),expression[i],Emap)) {
          popStack(stack,temp);
          popStack(Estack,a);
          popStack(Estack,b);
          calculate(temp,b,a,Estack);
        }
      }
      pushStack(stack,e[i]);
    }
  }
  return 0;
}