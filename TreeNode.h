#pragma once

class TreeNode
{
public:
    TreeNode();
    TreeNode(const int);
    int get_data() const { return data; }
    TreeNode* get_left() const { return left; }
    TreeNode* get_right() const { return right; }
    TreeNode* get_parent() const { return parent; }
    void set_left(TreeNode* value) { left = value; }
    void set_right(TreeNode* value) { right = value; }
    void set_parent(TreeNode* value) { parent = value; }
private:
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int data;
};


inline TreeNode::TreeNode()
{
    data = 0;
    left = right = nullptr;
    parent = nullptr;
}

inline TreeNode::TreeNode(const int iData)
{
    data = iData;
    left = right = nullptr;
    parent = nullptr;
}

