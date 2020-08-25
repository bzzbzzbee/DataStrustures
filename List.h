#pragma once
#include "ListNode.h"
template <typename T>
class List
{
	size_t _size = 0;
	ListNode<T> *_head = nullptr;
public:
	void push(const T &data);
	void insert(const T &data);
	T pop();
	bool del();
	ListNode<T>* getNode();
	const T& getDataRef();
	size_t getSize() const;
	void setSize(size_t size);
};

template<typename T>
inline void List<T>::push(const T & data)
{
	ListNode<T>* newNode = new ListNode<T>;
	newNode->setData(data);
	_size++;

	if (_head != nullptr)
	{
		_head->setNext(newNode);
		newNode->setPrevious(_head);
		_head = newNode;
	}
	else
	{
		_head = newNode;
	}
}

template<typename T>
inline void List<T>::insert(const T & data)
{
	ListNode<T>* newNode = new ListNode<T>;
	newNode->setData(data);
	_size++;

	if (_head != nullptr)
	{
		ListNode<T>* tmp = _head;

		while (auto temp = tmp->getPrevious())
			tmp = temp;

		newNode->setNext(tmp);
		newNode->setPrevious(nullptr);
		tmp->setPrevious(newNode);
	}
	else
	{
		_head = newNode;
	}
}

template<typename T>
inline T List<T>::pop()
{
	if (_size == 0)
		return false;
	T data = _head->getData();
	if (_head->getPrevious() != nullptr)
	{
		ListNode<T>* tmp = _head;
		_head = _head->getPrevious();
		_head->setNext(nullptr);
		delete tmp;
	}
	else
	{
		delete _head;
	}
	_size--;
	return data;
}

template<typename T>
inline bool List<T>::del()
{
	if (_size > 0)
	{
		_size--;
		ListNode<T> *tmp = _head;

		while (auto temp = tmp->getPrevious())
			tmp = temp;

		if (tmp->getNext() != nullptr)
		{
			tmp->getNext()->setPrevious(nullptr);
			delete tmp;
			return true;
		}
		else
		{
			delete _head;
			return true;
		}
	}
	else return false;
}

template<typename T>
inline ListNode<T>* List<T>::getNode()
{
	if (_size > 0)
		return _head;
}

template<typename T>
inline const T & List<T>::getDataRef()
{
	return _head->getDataRef();
}

template<typename T>
inline size_t List<T>::getSize() const
{
	return _size;
}

template<typename T>
inline void List<T>::setSize(size_t size)
{
	_size = size;
}
