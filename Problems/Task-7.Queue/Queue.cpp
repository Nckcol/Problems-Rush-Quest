#include "stdafx.h"
#include "Queue.h"

template<typename T>
Queue<T>::Node::Node()
{
}

template<typename T>
Queue<T>::Node::Node(T * data):
	_data(data)
{
}

template<typename T>
Queue<T>::Node::Node(T * data, Node * previous, Node * next):
	_data(data), _previous(previous), _next(next)
{
}

template<typename T>
T * Queue<T>::Node::Data() const 
{
	return _data;
}

template<typename T>
void Queue<T>::Node::Data(T * val)
{
	_data = val;
}

template<typename T>
typename Queue<T>::Node * Queue<T>::Node::Next() const
{
	return _next;
}

template<typename T>
void Queue<T>::Node::Next(Node * val)
{
	_next = val;
}

template<typename T>
typename Queue<T>::Node * Queue<T>::Node::Previous() const
{
	return _previous;
}

template<typename T>
void Queue<T>::Node::Previous(Node * val)
{
	_previous = val;
}

template <typename T>
Queue<T>::Queue()
{
}

template <typename T>
Queue<T>::~Queue()
{
}

template<typename T>
typename Queue<T>::Node * Queue<T>::Head() const
{
	return _head;
}

template<typename T>
void Queue<T>::Head(Node * val)
{
	_head = val;
}

template<typename T>
typename Queue<T>::Node * Queue<T>::Tail() const
{
	return _tail;
}

template<typename T>
void Queue<T>::Tail(Node * val)
{
	_tail = val;
}

template<typename T>
void Queue<T>::push(T * data)
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
T * Queue<T>::pop()
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


