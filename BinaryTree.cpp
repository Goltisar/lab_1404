#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
    root = new TreeNode();
}

BinaryTree::BinaryTree(const int iData)
{
    root = new TreeNode(iData);
}

BinaryTree::~BinaryTree()
{
    delete_tree(root);
}

void BinaryTree::insert(TreeNode* node, const int val)
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

void BinaryTree::insert(const int val)
{
    TreeNode* node = new TreeNode(val);
    TreeNode* curr;
    TreeNode* prevCurr = node->get_parent();
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

TreeNode* BinaryTree::search(TreeNode* node, const int val) const
{
    if (node == nullptr || val == node->get_data())
        return node;
    if (val > node->get_data())
        return search(node->get_right(), val);
    else
        return search(node->get_left(), val);
}

TreeNode* BinaryTree::search(const int val) const
{
    return search(root, val);
}

void BinaryTree::printTree(TreeNode* node) const
{
    if (node != nullptr)
    {
        printTree(node->get_left());
        if (node == root)
            cout << "root -> ";
        cout << node->get_data() << endl;
        printTree(node->get_right());
    }
}

void BinaryTree::delete_tree(TreeNode* node)
{
    if (node != nullptr)
    {
        delete_tree(node->get_left());
        delete_tree(node->get_right());
        delete node;
    }
    root = nullptr;
}

