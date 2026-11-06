#pragma once

template <typename T>
class Stack{
    int top_i, size;
    T* pMem;
public:
    Stack(int _size = 1) : top_i(-1), size(_size) {
        pMem = new T[size];
    }
    ~Stack() {
        delete[] pMem;
    }

    Stack(const Stack& s);

    Stack(Stack&& s) noexcept;

    Stack<T>& operator=(const Stack <T>& st);

    Stack<T>& operator=(Stack&& st) noexcept;

    bool operator==(const Stack <T>& st);

    bool IsFull() {
        return top_i == size - 1;
    }
    bool IsEmpty() {
        return top_i == -1;
    }

    void Clear() {
        top = -1;
    }

    void push(T el);

    T pop();
};