#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Set
{
	T* _data;
	size_t _size = 0;
public:
	bool hasEl(const T &el);
	bool addEl(const T &el);
	bool removeEl(const T &el);
	Set<T> setUnion(const Set<T> &set);
	Set<T> intersection(const Set<T> &set);
	Set<T> difference(const Set<T> &set);
	void printSet();
	void printSet(const Set<T> &set);
	Set<T>(const Set<T> &set);
	Set<T>();
	~Set<T>();
};

template <typename T>
inline bool Set<T>::hasEl(const T & el)
{
	for (size_t i = 0; i < _size; ++i)
	{
		if (_data[i] == el)
			return true;
	}
	return false;
}

template <typename T>
inline bool Set<T>::addEl(const T & el)
{
	if (this->hasEl(el))
		return false;
	else
	{
		T* newData = new T[_size + 1];
		for (size_t i = 0; i < _size; ++i)
			newData[i] = _data[i];
		newData[_size++] = el;
		if(_data)
			delete[] _data;
		_data = newData;
		return true;
	}
}

template <typename T>
inline bool Set<T>::removeEl(const T & el)
{
	if(!this->hasEl(el))
		return false;
	else
	{
		T* newData = new T[_size - 1];
		int j = 0;
		for (size_t i = 0; i < _size; ++i)
		{
			if (_data[i] != el)
			{
				newData[j] = _data[i];
				++j;
			}
		}
		--_size;
		delete[] _data;
		_data = newData;
		return true;
	}
}

template <typename T>
inline Set<T> Set<T>::setUnion(const Set<T>& set)
{
	Set<T> uSet(*this);
	for (size_t i = 0; i < set._size; ++i)
		uSet.addEl(set._data[i]);
	return uSet;
}

template<typename T>
inline Set<T> Set<T>::intersection(const Set<T>& set)
{
	Set<T> iSet;
	for (size_t i = 0; i < set._size; ++i)
	{
		if (this->hasEl(set._data[i]))
			iSet.addEl(set._data[i]);
	}
	return iSet;
}

template<typename T>
inline Set<T> Set<T>::difference(const Set<T>& set)
{
	Set<T> dSet(*this);
	for (size_t i = 0; i < set._size; ++i)
		if (!dSet.addEl(set._data[i]))
			dSet.removeEl(set._data[i]);
	return dSet;
}

template<typename T>
inline void Set<T>::printSet()
{
	for (size_t i = 0; i < _size; ++i)
		cout << _data[i] << endl;
}

template<typename T>
inline void Set<T>::printSet(const Set<T>& set)
{
	set.printSet();
}

template<typename T>
inline Set<T>::Set(const Set<T>& set) : _size(set._size)
{
	_data = new T[_size];
	for (size_t i = 0; i < _size; ++i)
		_data[i] = set._data[i];
}

template<typename T>
inline Set<T>::Set()
{
}

template<typename T>
inline Set<T>::~Set()
{
	delete[] _data;
}
