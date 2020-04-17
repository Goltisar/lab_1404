#pragma once
#include "TreeNode.h"

template <typename T>
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(const T);
    ~BinaryTree();
    void insert(const T);
    void printTree(TreeNode<T>*) const;
    TreeNode<T>* search(const T) const;
    TreeNode<T>* get_root() const { return root; }
private:
    TreeNode<T>* root;
    void insert(TreeNode<T>*, const T);
    TreeNode<T>* search(TreeNode<T>* , const T) const;
    void delete_tree(TreeNode<T>*);
};

template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = new TreeNode<T>();
}

template<typename T>
BinaryTree<T>::BinaryTree(const T iData)
{
    root = new TreeNode<T>(iData);
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    delete_tree(root);
}

template<typename T>
void BinaryTree<T>::insert(TreeNode<T>* node, const T val)
{
    if (node->get_parent() == nullptr)
        root = node;
    else
    {
        if (val < node->get_parent()->get_data())
            node->get_parent()->set_left(node);
        else
            node->get_parent()->set_right(node);
    }
}

template<typename T>
void BinaryTree<T>::insert(const T val)
{
    TreeNode<T>* node = new TreeNode<T>(val);
    TreeNode<T>* curr;
    TreeNode<T>* prevCurr = node->get_parent();
    if (search(val) != nullptr)
        return;
    curr = root;
    while (curr != nullptr)
    {
        prevCurr = curr;
        if (val < curr->get_data())
            curr = curr->get_left();
        else
            curr = curr->get_right();
    }
    node->set_parent(prevCurr);
    insert(node, val);
}

template<typename T>
TreeNode<T>* BinaryTree<T>::search(TreeNode<T>* node, const T val) const
{
    if (node == nullptr || val == node->get_data())
        return node;
    if (val > node->get_data())
        return search(node->get_right(), val);
    else
        return search(node->get_left(), val);
}

template<typename T>
TreeNode<T>* BinaryTree<T>::search(const T val) const
{
    return search(root, val);
}

template<typename T>
void BinaryTree<T>::printTree(TreeNode<T>* node) const
{
    if (node != nullptr)
    {
        printTree(node->get_left());
        if (node == root)
            std::cout << "root -> ";
        std::cout << node->get_data() << std::endl;
        printTree(node->get_right());
    }
}

template<typename T>
void BinaryTree<T>::delete_tree(TreeNode<T>* node)
{
    if (node != nullptr)
    {
        delete_tree(node->get_left());
        delete_tree(node->get_right());
        delete node;
    }
    root = nullptr;
}

