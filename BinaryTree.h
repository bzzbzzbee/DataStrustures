#pragma once
#include "Node.h"
#define SPACE 7
using namespace std;

template <typename T>
class BinaryTree {
    shared_ptr<Node<T>> _root = nullptr;
    shared_ptr<Node<T>> insert(shared_ptr<Node<T>> root, const T& data);
    shared_ptr<Node<T>> rotateRight(shared_ptr<Node<T>> node);
    shared_ptr<Node<T>> rotateLeft(shared_ptr<Node<T>> node);
    shared_ptr<Node<T>> balance(shared_ptr<Node<T>> node);
    void printTree(shared_ptr<Node<T>> root, int count = 0);
    shared_ptr<Node<T>> search(shared_ptr<Node<T>> root, const T &data);
    shared_ptr<Node<T>> deleteNode(shared_ptr<Node<T>> root, const T &data);
    shared_ptr<Node<T>> findMin(shared_ptr<Node<T>> root);
    shared_ptr<Node<T>> removeMin(shared_ptr<Node<T>> root);
public:
    void insert(const T& data);
    void deleteNode(const T & data);
    bool search(const T& data);
    void printTree();
};

template<class T>
void BinaryTree<T>::insert(const T &data) {
    _root = insert(_root, data);
}

template<class T>
shared_ptr<Node<T>> BinaryTree<T>::insert(shared_ptr<Node<T>> root, const T &data) {
    if (!root) return make_shared<Node<T>>(data);

    if (data > root->getDataRef())
        root->setRight(insert(root->getRight(), data));
    else
        root->setLeft(insert(root->getLeft(), data));
    return balance(root);
}

template<class T>
bool BinaryTree<T>::search(const T &data) {
    return search(_root, data) ? true : false;
}

template<typename T>
shared_ptr<Node<T>> BinaryTree<T>::search(shared_ptr<Node<T>> root, const T &data) {
    if (root == nullptr || data == root->getDataRef())
        return root;
    if (data < root->getDataRef())
        return search(root->getLeft(), data);
    else
        return search(root->getRight(), data);
}

template<typename T>
shared_ptr<Node<T>> BinaryTree<T>::deleteNode(shared_ptr<Node<T>> root, const T &data) {
    if (!root) return 0;

    if (data < root->getDataRef())
        root->setLeft(deleteNode(root->getLeft(), data));

    else if (data > root->getDataRef())
        root->setRight(deleteNode(root->getRight(), data));

    else
    {
        auto l = root->getLeft();
        auto r = root->getRight();

        root.reset();

        if (!r) return l;
        auto min = findMin(r);
        min->setRight(removeMin(r));
        min->setLeft(l);
        return balance(min);
    }
    return balance(root);
}

template<typename T>
void BinaryTree<T>::deleteNode(const T &data) {
    _root = deleteNode(_root, data);
}
template<typename T>
shared_ptr<Node<T>> BinaryTree<T>::rotateRight(shared_ptr<Node<T>> node) {
    auto r = node->getLeft();
    node->setLeft(r->getRight());
    r->setRight(node);

    node->setHeight();
    r->setHeight();
    return r;
}

template<typename T>
shared_ptr<Node<T>> BinaryTree<T>::rotateLeft(shared_ptr<Node<T>> node) {
    auto l = node->getRight();
    node->setRight(l->getLeft());
    l->setLeft(node);

    node->setHeight();
    l->setHeight();
    return l;
}

template<typename T>
shared_ptr<Node<T>> BinaryTree<T>::balance(shared_ptr<Node<T>> node) {
    node->setHeight();

    if (node->bFactor() == 2)
    {
        if (node->getRight()->bFactor() < 0)
            node->setRight(rotateRight(node->getRight()));
        return rotateLeft(node);
    }

    if (node->bFactor() == -2)
    {
        if(node->getLeft()->bFactor() > 0)
            node->setLeft(rotateLeft(node->getLeft()));
        return rotateRight(node);
    }
    return node;
}

template<typename T>
void BinaryTree<T>::printTree(shared_ptr<Node<T>> root, int count) {
    if (!root) return;

    count += SPACE;

 printTree(root->getRight(), count);

    cout << endl;

    for (int i = SPACE; i < count; i++)
        cout << " ";
    cout << root->getDataRef() << endl;

    printTree(root->getLeft(), count);
}

template<typename T>
void BinaryTree<T>::printTree() {
    printTree(_root, 0);
}

template<typename T>
shared_ptr<Node<T>> BinaryTree<T>::findMin(shared_ptr<Node<T>> root) {
    return (root->getLeft()) ? findMin(root->getLeft()) : root;
}

template<typename T>
shared_ptr<Node<T>> BinaryTree<T>::removeMin(shared_ptr<Node<T>> root) {
    if((root->getLeft()) == 0)
        return root->getRight();
    root->setLeft(removeMin(root->getLeft()));
    return balance(root);
}
