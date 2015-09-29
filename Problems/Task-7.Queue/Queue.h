#pragma once

template <typename T>
class Queue
{

    class Node
    {
        T* _data;
        Node* _next;
        Node* _previous;

    public:
        Node();
        Node(T* data);
        Node(T* data, Node* previous, Node* next);

        /* Getters & Setters */
        T* Data() const;
        void Data(T* val);
        Node* Next() const;
        void Next(Node* val);
        Node* Previous() const;
        void Previous(Node* val);

        bool operator<(const Node &second);
        bool operator>(const Node &second);
        bool operator<=(const Node &second);
        bool operator>=(const Node &second);
    };

    Node * _head;
    Node * _tail;

    Node * _partitition(Node * begin, Node * end);
    void _qsort(Node * begin, Node * end);
public:
    Queue();
    ~Queue();
    Node* Head() const;
    void Head(Node* val);
    Node* Tail() const;
    void Tail(Node* val);

    void push(T* data);
    T* pop();

    void qsort();
    void swap(Node * a, Node * b);

    int size();
    Node * at(unsigned int i);
    int index(Node * node);
    /*void isort();*/

};