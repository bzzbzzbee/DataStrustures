#pragma once
template <typename T>
class ListNode
{
	T _data;
	ListNode<T> *_next = nullptr, *_previous = nullptr;
public:
	const T& getDataRef();
	T getData();
	ListNode<T>* getPrevious();
	ListNode<T>* getNext();
	bool setPrevious(ListNode<T> *previous);
	bool setNext(ListNode<T> *next);
	bool setData(const T& data);
};

template<typename T>
inline const T & ListNode<T>::getDataRef()
{
	return _data;
}

template<typename T>
inline T ListNode<T>::getData()
{
	return _data;
}

template<typename T>
inline ListNode<T>* ListNode<T>::getPrevious()
{
	return _previous;
}

template<typename T>
inline ListNode<T>* ListNode<T>::getNext()
{
	return _next;
}

template<typename T>
inline bool ListNode<T>::setPrevious(ListNode<T>* previous)
{
	_previous = previous;
	return true;
}

template<typename T>
inline bool ListNode<T>::setNext(ListNode<T>* next)
{
	_next = next;
	return true;
}

template<typename T>
inline bool ListNode<T>::setData(const T & data)
{
	_data = data;
	return true;
}
