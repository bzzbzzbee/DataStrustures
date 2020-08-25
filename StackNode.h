#pragma once
#include "List.h"
template <typename T>
class StackNode
{
	List<T> *_tail;
public:
	StackNode<T>();
	void push(const T& data);
	T pop();
	const T& peek();
	bool isEmpty();
};

template<typename T>
inline void StackNode<T>::push(const T & data)
{
	_tail->push(data);
}

template<typename T>
inline T StackNode<T>::pop()
{
	if (_tail->getSize())
		return _tail->pop();
	else return false;
}

template<typename T>
inline const T & StackNode<T>::peek()
{
	if (_tail->getSize())
		return  _tail->getDataRef();
	else return -1;
}

template<typename T>
inline bool StackNode<T>::isEmpty()
{
	return (!_tail.getSize());
}

template<typename T>
inline StackNode<T>::StackNode() : _tail(new List<T>)
{
}
