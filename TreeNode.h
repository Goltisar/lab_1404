#pragma once
template <typename T>
class TreeNode
{
public:
    TreeNode();
    TreeNode(const T);
    T get_data() const { return data; }
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
    T data;
};

template<typename T>
TreeNode <T>::TreeNode()
{
    data = T();
    left = right = nullptr;
    parent = nullptr;
}

template<typename T>
TreeNode <T>::TreeNode(const T iData)
{
    data = iData;
    left = right = nullptr;
    parent = nullptr;
}

