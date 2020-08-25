#pragma once
#include <memory>
using namespace std;

template <typename T>
class Node {
    const T _data;
    unsigned char _height;
    shared_ptr<Node<T>> _left = nullptr, _right = nullptr;
public:
    explicit Node(const T& data);
    const T& getDataRef();
    T getData();
    shared_ptr<Node<T>> getLeft();
    shared_ptr<Node<T>> getRight();
    void setLeft(shared_ptr<Node<T>> left);
    void setRight(shared_ptr<Node<T>> right);
    unsigned char getHeight() const;
    void setHeight();
    int bFactor();
};

template<class T>
Node<T>::Node(const T &data) : _data(data), _height(1) {
}

template<class T>
const T &Node<T>::getDataRef() {
    return _data;
}

template<class T>
T Node<T>::getData() {
    return _data;
}

template<class T>
shared_ptr<Node<T>> Node<T>::getLeft() {
    return _left;
}

template<class T>
shared_ptr<Node<T>> Node<T>::getRight() {
    return _right;
}

template<class T>
void Node<T>::setLeft(shared_ptr<Node<T>> left) {
    _left = left;
}

template<class T>
void Node<T>::setRight(shared_ptr<Node<T>> right) {
    _right = right;
}

template<class T>
unsigned char Node<T>::getHeight() const {
    return _height;
}

template<class T>
void Node<T>::setHeight() {
    auto r = ((_right == nullptr) ? 0 : _right->getHeight());
    auto l = ((_left == nullptr) ? 0 : _left->getHeight());
    _height = (r > l ? r : l) + 1;
}

template<class T>
int Node<T>::bFactor() {
    return (((_right == nullptr) ? 0 : _right->getHeight()) - ((_left == nullptr) ? 0 : _left->getHeight()));
}