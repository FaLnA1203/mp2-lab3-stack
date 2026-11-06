#include "stack.h"

template <typename T>
Stack<T>::Stack(const Stack& s) {
        size = s.size;
        top_i = s.top_i;
        pMem = new T[size];
        for (int i = 0; i < top_i; i++) {
            pMem[i] = s.pMem[i];
        }
}

template <typename T>
Stack<T>::Stack(Stack&& s) noexcept: top_i(s.top_i), size(s.size), pMem(s.pMem) {
    s.pMem = nullptr;
    s.top_i = -1;
    s.size = 0;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack <T>& st) {
    if (&st == this) {
        if (this->size = st.size) {
            size = st.size;
            delete[] pMem;
            pMem = new T[size];
        }
        top_i = st.top_i;
        for (int i = 0; i < top_i; i++) {
            pMem[i] = st.pMem[i];
        }
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& st) noexcept {
    if (this != &st) {
        delete[] pMem;
        pMem = st.pMem;
        size = st.size;
        top_i = st.top_i;
        st.pMem = nullptr;
        st.size = 0;
        st.top_i = -1;
    }
    return *this;
}

template <typename T>
bool Stack<T>::operator==(const Stack <T>& st) {
    if (size != st.size) return false;
    if (top_i != st.top_i) return false;
    for (int i = 0; i < top_i; i++) {
        if (pMem[i] != st.pMem[i]) return false;
    }
    return true;
}

template <typename T>
void Stack<T>::push(T el) {
    if (IsFull()) { trow ""; }
    else {
        top_i++;
        pMem[top_i] = el;
    }
}

template <typename T>
T Stack<T>::pop() {
    if (IsEmpty) { throw ""; }
    else {
        top_i--;
        return pMem[top_i + 1];
    }
}