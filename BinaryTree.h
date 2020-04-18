#pragma once
#include "TreeNode.h"

class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(const int);
    ~BinaryTree();
    void insert(const int);
    void printTree(TreeNode*) const;
    TreeNode* search(const int) const;
    TreeNode* get_root() const { return root; }
    void set_root(TreeNode* node) { root = node; }
private:
    TreeNode* root;
    void insert(TreeNode*, const int);
    TreeNode* search(TreeNode* , const int) const;
    void delete_tree(TreeNode*);
};

