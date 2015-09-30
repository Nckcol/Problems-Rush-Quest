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


template <typename T>
List<T>::Node::Node() :
    _data(nullptr), _next(nullptr)
{

}

template <typename T>
List<T>::Node::Node(T* data) :
    _data(data), _next(nullptr)
{

}

template <typename T>
List<T>::Node::Node(T* data, typename List<T>::Node* next) :
    _data(data), _next(next)
{

}

template <typename T>
T *List<T>::Node::data() const
{
    return _data;
}

template <typename T>
void List<T>::Node::setData(T* data)
{
    _data = data;
}

template <typename T>
typename List<T>::Node *List<T>::Node::next() const
{
    return _next;
}

template <typename T>
void List<T>::Node::setNext(typename List<T>::Node* next)
{
    _next = next;
}

template <typename T>
List<T>::List() :
    _head(nullptr), _tail(nullptr)
{

}

template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
void List<T>::pushBack(T* data)
{
    if (!head())
    {
        setHead(new Node(data));
        setTail(head());

        return;
    }

    tail()->setNext(new Node(data));
    setTail(tail()->next());
}

template <typename T>
void List<T>::pushFront(T *data)
{
    if (!head())
    {
        setHead(new Node(data));
        setTail(head());

        return;
    }

    setHead(new Node(data, head()));
}

template <typename T>
void List<T>::pushAfter(typename List<T>::Node* node, T* data)
{
    node->setNext(new Node(data, node->next()));
    if (!node->next()->next()) setTail(node->next());
}

template <typename T>
T* List<T>::popBack()
{
    if (!head())
    {
        return nullptr;
    }

    if (head() == tail())
    {
        T* data = head()->data();
        delete head();
        setHead(nullptr);
        setTail(nullptr);
        return data;
    }

    Node* current = head();

    while (current->next()->next())
    {
        current = current->next();
    }

    setTail(current);
    T* data = tail()->next()->data();
    delete tail()->next();
    tail()->setNext(nullptr);
    return data;
}

template <typename T>
T* List<T>::popFront()
{
    if (!head())
    {
        return nullptr;
    }

    if (head() == tail())
    {
        T* data = head()->data();
        delete head();
        setHead(nullptr);
        setTail(nullptr);
        return data;
    }

    Node* head = head();
    setHead(head()->next());
    T* data = head()->next()->data();
    delete head;
    return data;
}

template <typename T>
int List<T>::size()
{
    int size = 0;
    Node* current = head();

    while (!current->next())
    {
        current = current->next();
        size++;
    }

    return size;
}

template <typename T>
typename List<T>::Node* List<T>::at(int position)
{
    Node* current = head();
    for (int i = 0; current->next() && i < position; i++)
    {
        current = current->next();
    }
    return current;
}

template <typename T>
void List<T>::clear()
{
    Node* next = head();
    Node* current;
    while (next)
    {
        current = next;
        next = next->next();
        delete current;
    }
    setTail(nullptr);
    setHead(nullptr);
}

template <typename T>
void List<T>::remove(typename List<T>::Node* node)
{
    Node* current = head();

    if (node == head())
    {
        setHead(node->next());
    }
    else
    {
        while (current->next())
        {
            if (current->next() == node)
            {
                current->setNext(node->next());
                if (node == tail()) setTail(current);
                break;
            }
            current = current->next();
        }

        // return; //deleting node outside the list may provides some errors.. or does not?
    }

    
    delete node;
}

template <typename T>
int List<T>::indexOf(T *data)
{
    int count = 0;
    for (auto i = head(); i->next(); i = i->next(), count++)
    {
        if (i->data() == data) return count;
    }

    return -1;
}

template <typename TT>
std::ostream& operator<<(std::ostream& os, List<TT> const & list)
{
    auto current = list.head();

    while (current)
    {
        os << *current->data() << " ";
        current = current->next();
    }
    return os;
}

/**
* Getters & Setters
**/

template <typename T>
typename List<T>::Node* List<T>::head() const
{
    return _head;
}

template <typename T>
void List<T>::setHead(typename List<T>::Node* head)
{
    _head = head;
}

template <typename T>
typename List<T>::Node* List<T>::tail() const
{
    return _tail;
}

template <typename T>
void List<T>::setTail(typename List<T>::Node* tail)
{
    _tail = tail;
}