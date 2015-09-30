#pragma once

#include <iostream>

template<typename T>
class List
{
    class Node
    {
        T* _data;
        Node* _next;

    public:
        Node();
        Node(T* data);
        Node(T* data, Node* next);

        T* data() const;
        void setData(T* data);
        Node* next() const;
        void setNext(Node* next);
    };

    Node* _head;
    Node* _tail;
public:
    List();
    ~List();
    void pushBack(T* data);
    void pushFront(T* data);
    void pushAfter(Node* node, T* data);
    T* popBack();
    T* popFront();
    int size();
    Node* at(int position);
    void clear();
    void remove(Node* node);
    int indexOf(T *data);

    template <typename TT>
    friend std::ostream& operator<<(std::ostream& os, List<TT> const & list);

    Node* head() const;
    void setHead(Node* head);
    Node* tail() const;
    void setTail(Node* tail);
};

