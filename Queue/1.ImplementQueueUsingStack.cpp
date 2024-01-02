/** https://leetcode.com/problems/implement-queue-using-stacks */
#include<iostream>
using namespace std;

class MyQueue {
private:
        stack<int> input;
        stack<int> output;
public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (!output.empty()) {
            int temp = output.top();
            output.pop();
            return temp;
        }
        else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }

            if (output.empty())
                return -1;

            int temp = output.top();
            output.pop();
            return temp;
        }
    }
    
    int peek() {
        if (!output.empty()) {
            return output.top();
        } else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }

            if (output.empty())
                return -1;

            return output.top();
        }
    }
    
    bool empty() {
        return output.empty() && input.empty();
    }
};


int main() {
    MyQueue myQueue;

    // Push some elements into the queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Peek at the front element
    std::cout << "Front element: " << myQueue.peek() << std::endl;

    // Pop and print elements until the queue is empty
    while (!myQueue.empty()) {
        std::cout << "Popped element: " << myQueue.pop() << std::endl;
    }

    // Check if the queue is empty
    std::cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}