#pragma once
#include "List.h"
template<typename T>
class Queue
{
	List<T> *_list;
	ListNode<T> *_tail = nullptr;

public:
	Queue<T>();
	void enqueue(const T &data);
	T dequeue();
	size_t getSize() const;
	bool isEmpty();
	~Queue<T>();
};

template<typename T>
inline void Queue<T>::enqueue(const T &data)
{
	if (_tail == nullptr)
	{
		_list->insert(data);
		_tail = _list->getNode();
	}
	else
	{
		ListNode<T>* newNode = new ListNode<T>;
		newNode->setData(data);
		_list->setSize(_list->getSize() + 1);
		_tail->setPrevious(newNode);
		newNode->setNext(_tail);
		_tail = newNode;
	}
}

template<typename T>
inline T Queue<T>::dequeue()
{
	return _list->pop();
}

template<typename T>
inline size_t Queue<T>::getSize() const
{
	return _list->getSize();
}

template<typename T>
inline bool Queue<T>::isEmpty()
{
	return (!_list->getSize());
}

template<typename T>
inline Queue<T>::Queue() : _list(new List<T>)
{
}

template<typename T>
inline Queue<T>::~Queue()
{
	delete _list;
}
