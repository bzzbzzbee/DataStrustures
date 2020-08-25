#pragma once

template <typename T>
class Stack
{
	size_t _top;
	size_t _max;
	T* _stack;
public:
	Stack<T>(size_t max);
	bool push(const T& data);
	T pop();
	T peek();
	bool isEmpty();
	~Stack();
};

template<typename T>
inline Stack<T>::Stack(size_t max) : _max(max)
{
	_stack = new T[_max];
	_top = 0;
}

template<typename T>
inline bool Stack<T>::push(const T & data)
{
	if (_top >= _max)
		return 0;
	else
		_stack[_top++] = data;
	return 1;
}

template<typename T>
inline T Stack<T>::pop()
{
	if (_top <= 0)
		return 0;
	else
		return _stack[--_top];
}

template<typename T>
inline T Stack<T>::peek()
{
	if (_top <= 0)
		return 0;
	else
		return _stack[_top -1];
}

template<typename T>
inline bool Stack<T>::isEmpty()
{
	return (_top <= 0);
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] _stack;
}
