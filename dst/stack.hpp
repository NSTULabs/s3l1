#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "array.hpp"

using namespace std;

template <typename T>
struct Stack {
private:
    Array<T> stack;
    int len;

public:
    Stack() {
        len = 0;
    }
    
    Array<T> data() const {
        return stack;
    }

    int size() {
        return len;
    }

    void push(T val) {
        stack.pushBack(val);
    }

    T pop() {
        if (stack.size() == 0) {
            throw runtime_error("Stack is empty");
        }

        int outIndex = stack.size() - 1;
        T popped = stack.get(outIndex);
        stack.remove(outIndex);
        
        return popped;
    }
};

template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& stack) {
    Array<T> data = stack.data();

    for (int i = data.size() - 1; i >= 0; i--) {
        os << data.get(i) << endl;
    }

    return os;
}

#endif