#ifndef NODE_H
#define NODE_H
#pragma once

using namespace std;
template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data, Node<T>* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};
#endif
