#include <bits/stdc++.h>

using namespace std;

class Stack{
    int top;
    unsigned capacity;
    int* arr;
public:
    Stack(unsigned capacity);
    int isEmpty();
    void push(char ch);
    char pop();
};

Stack::Stack(unsigned c){
    this->top = -1;
    this->capacity = c;
    this->arr = (int*)malloc(c*sizeof(int));
}

int Stack::isEmpty(){
    return (this->top == -1);
}

void Stack::push(char ch){
    arr[++this->top] = ch;
}

char Stack::pop(){
    if(!isEmpty()){
        return this->arr[this->top--];
    }
   return '$';
}

int main(){
Stack st(5);
st.push('a');
st.push('k');
st.push('h');
st.push('i');
while(!st.isEmpty()){
    cout<<st.pop()<<endl;
}
return 0;
}
