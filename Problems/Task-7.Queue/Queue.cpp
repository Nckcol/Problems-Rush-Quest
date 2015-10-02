#include "stdafx.h"
#include "Queue.h"

template<typename T>
inline Queue<T>::Node::Node()
{
}

template<typename T>
inline Queue<T>::Node::Node(T * data):
    _data(data)
{
}

template<typename T>
inline Queue<T>::Node::Node(T * data, Node * previous, Node * next):
    _data(data), _previous(previous), _next(next)
{
}

template<typename T>
inline T * Queue<T>::Node::Data() const 
{
    return _data;
}

template<typename T>
inline void Queue<T>::Node::Data(T * val)
{
    _data = val;
}

template<typename T>
inline typename Queue<T>::Node * Queue<T>::Node::Next() const
{
    return _next;
}

template<typename T>
inline void Queue<T>::Node::Next(Node * val)
{
    _next = val;
}

template<typename T>
inline typename Queue<T>::Node * Queue<T>::Node::Previous() const
{
    return _previous;
}

template<typename T>
inline void Queue<T>::Node::Previous(Node * val)
{
    _previous = val;
}

template<typename T>
inline bool Queue<T>::Node::operator<(const Node & second)
{
    if (!this) return false;

    auto current = this;
    if (current == &second)
    {
        return false;
    }
    while (current != &second)
    {
        current = current->Next();
        if (!current) return false;
    }

    return true;
}

template<typename T>
inline bool Queue<T>::Node::operator>(const Node & second)
{
    if (!this) return false;

    auto current = this;
    if (current == &second)
    {
        return false;
    }
    while (current != &second)
    {
        current = current->Previous();
        if (!current) return false;
    }

    return true;
}

template<typename T>
inline bool Queue<T>::Node::operator<=(const Node & second)
{
    if (!this) return false;

    auto current = this;
    while (current != &second)
    {
        current = current->Next();
        if (!current) return false;
    }

    return true;
}

template<typename T>
inline bool Queue<T>::Node::operator>=(const Node & second)
{
    if (!this) return false;

    auto current = this;
    while (current != &second)
    {
        current = current->Previous();
        if (!current) return false;
    }

    return true;
}

template<typename T>
inline typename Queue<T>::Node * Queue<T>::_partitition(Node * begin, Node * end)
{
    swap(middle(begin, end), begin);
    auto l = begin->Next();
    auto r = end;
    bool out = (l == r);
    while (!out) {
        while (!out && *l->Data() <= *begin->Data()) {
            out = (l == r) || out;
            l = l->Next();
            if (!l) break;
        }

        while (!out && *r->Data() > *begin->Data()) {
            out = (l == r) || out;
            r = r->Previous();
            if (!r) break;
        }

        if (!out) {
            swap(l, r);
        }
    }
    if (!l)
    {
        l = end;
    }
    else
    {
        l = l->Previous();
    }

    swap(begin, l);

    return l;
}

template<typename T>
inline void Queue<T>::_qsort(Node * begin, Node * end)
{
    if (*begin >= *end || !begin || !end) {
        return;
    }

    auto left = begin,
         right = end,
         middle = _partitition(begin, end);

    _qsort(left, middle->Previous());
    _qsort(middle->Next(), right);
}

template <typename T>
inline Queue<T>::Queue()
{
}

template <typename T>
inline Queue<T>::~Queue()
{
}

template<typename T>
inline typename Queue<T>::Node * Queue<T>::Head() const
{
    return _head;
}

template<typename T>
inline void Queue<T>::Head(Node * val)
{
    _head = val;
}

template<typename T>
inline typename Queue<T>::Node * Queue<T>::Tail() const
{
    return _tail;
}

template<typename T>
inline void Queue<T>::Tail(Node * val)
{
    _tail = val;
}

template<typename T>
inline void Queue<T>::push(T * data)
{
    if (!Head())
    {
        Head(new Node(data, nullptr, nullptr));
        Tail(Head());
        return;
    }

    Tail()->Next(new Node(data, Tail(), nullptr));
    Tail(Tail()->Next());
}

template<typename T>
inline T * Queue<T>::pop()
{
    if(!Head())
        return nullptr;

    auto data = Head()->Data();

    if (Head() == Tail())
    {
        Tail(nullptr);
    }
    
    Head(Head()->Next());

    return data;
}

template<typename T>
void Queue<T>::insertAfter(typename Queue<T>::Node * after, typename Queue<T>::Node * node)
{
    if (!after && !node) return;

    if (node->Before() && node->Next())
    {
        node->Before()->Next(node->Next());
        node->Next()->Before(node->Before());
    }
    else if (node->Next())
    {
        node->Next()->Before(nullptr);
        Head(node->Next());
    }
    else
    {
        node->Before()->Next(nullptr);
        Tail(node->Before());
    }

    node->Previous(after);
    node->Next(after->Next());
    after->Next(node);
    if (!node->Next())
    {
        Tail(node);
    }
    else
    {
        node->Next()->Previous(node);
    }
}

template<typename T>
void Queue<T>::inserBefore(typename Queue<T>::Node * before, typename Queue<T>::Node * node)
{
    if (!before && !node) return;

    if (node->Before() && node->Next())
    {
        node->Before()->Next(node->Next());
        node->Next()->Before(node->Before());
    }
    else if (node->Next())
    {
        node->Next()->Before(nullptr);
        Head(node->Next());
    }
    else
    {
        node->Before()->Next(nullptr);
        Tail(node->Before());
    }

    node->Previous(before->Previous());
    node->Next(before);
    before->Previous(node);
    if (!node->Previous())
    {
        Head(node);
    }
    else
    {
        node->Previous()->Next(node);
    }
}

template<typename T>
inline void Queue<T>::qsort()
{
    _qsort(Head(), Tail());
}

template<typename T>
inline void Queue<T>::isort()
{
    if (!Head()) return;

    auto pointer = Head()->Next();

    while (pointer)
    {
        auto currentElement = pointer;
        pointer = pointer->Next();

        while (*currentElement->Data() < *currentElement->Previous()->Data())
        {
            swap(currentElement, currentElement->Previous());
            currentElement = currentElement->Previous();
            if (!currentElement->Previous()) break;
        }
    }
}

template<typename T>
inline void Queue<T>::swap(Node * a, Node * b)
{
    if (a == b) return;
    
    T * tmp = b->Data();
    b->Data(a->Data());
    a->Data(tmp);
}

template<typename T>
inline typename Queue<T>::Node * Queue<T>::middle(typename Queue<T>::Node * from, typename Queue<T>::Node * to)
{
    while (from != to && from != to->Previous())
    {
        from = from->Next();
        to = to->Previous();
    }

    return from;
}

template<typename T>
inline int Queue<T>::size()
{
    if(!Head())
        return 0;

    int count = 0;
    auto current = Head();
    while (current)
    {
        current = current->Next();
        count++;
    }

    return count;
}

template<typename T>
inline typename Queue<T>::Node * Queue<T>::at(unsigned int i)
{
    auto current = Head();
    while(i--)
    {
        current = current->Next();
        if (!current) return nullptr;
    }
    return current;
}

template<typename T>
inline int Queue<T>::index(Node * node)
{
    int count = 0;
    auto current = Head();
    while (current != node)
    {
        current = current->Next();
        if (!current) return -1;
        count++;
    }

    return count;
}