#include <iostream>
using namespace std;

class Queue {
    private:
        int maxSize;
        int* arr;
        int front;
        int rear;
        int elementCount;
    
    public: 
        Queue() {
            maxSize = 1000;
            arr = new int[maxSize];
            front = -1;
            rear = -1;
            elementCount = 0;
        }

        void push(int x) {
            if (elementCount == maxSize) {
                cout << "Queue is full";
                return;
            }

            if (rear == -1) {
                front = 0;
                rear = 0;
            } else 
                rear = (rear + 1) % maxSize;

            arr[rear] = x;
            elementCount += 1;
        }

        int pop() {
            if (front == -1) {
                cout << "Queue is empty";
                return -1;
            }

            int temp = arr[front];
            if (elementCount == 1) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % maxSize;
            }
            elementCount -= 1;

            return temp;
        }

        int top() {
            if (front == -1) {
                cout << "Queue is empty";
                return -1;
            }

            return arr[front];
        }

        int size() {
            return elementCount;
        }
};

int main() {
    Queue q;

    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;
    return 0;
}