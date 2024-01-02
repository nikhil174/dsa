#include <iostream>
using namespace std;

class Stack {
  int length;
  int* arr;
  int top;

 public:
  Stack() {
    length = 1000;
    arr = new int[length];
    top = -1;
  }

  int push(int x) {
    top++;
    arr[top] = x;
  }

  int pop() {
    if (top == -1)
      return -1;
    int temp = arr[top];
    top--;
    return temp;
  }

  int peek() {
    if (top != -1)
      return arr[top];
    return -1;
  }

  int size() {
    return top + 1;
  }
};

int main() {
  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);

  cout << "Top of stack is before deleting any element " << s.peek() << endl;
   cout << "Size of stack before deleting any element " << s.size() << endl;
   cout << "The element deleted is " << s.pop() << endl;
   cout << "Size of stack after deleting an element " << s.size() << endl;
   cout << "Top of stack after deleting an element " << s.peek() << endl;
  
  return 0;
}