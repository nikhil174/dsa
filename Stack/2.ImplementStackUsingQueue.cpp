// * https://leetcode.com/problems/implement-stack-using-queues/description/ */

// 2 Queues used
// TC = O(N) , SC = O(N) = 2N
class MyStack {
    queue<int> q;
    queue<int> temp;
public:
    MyStack() {    
    }
    
    void push(int x) {
        temp.push(x);
        while(!q.empty()) {
            temp.push(q.front());
            q.pop();
        }

        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
    }
    
    int pop() {
        if (q.empty())
            return -1;
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
       if (q.empty())
            return -1;
        return q.front(); 
    }  
    
    bool empty() {
       return q.empty(); 
    }
};


// 1 queue 
// TC = O(N) , SC = O(N)
class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if (q.empty())
            return -1;
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        if (q.empty())
            return -1;
        return q.front();    
    }
    
    bool empty() {
        return q.empty();
    }
};