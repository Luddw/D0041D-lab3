#pragma once
#include <iostream>

class Tree;

struct TreeNode
{
    Tree* y_tree;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    int value;
    int depth;
};


int GetMax(const int a, const int b)
{
    return (a > b) ? a : b;
}

int GetHeight(TreeNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->depth;
}

class Tree
{
private:
    TreeNode* m_root_node;
    size_t m_node_count;
public:
    Tree() : m_node_count(0) { m_root_node = nullptr;};
    ~Tree() {};

    TreeNode* CreateNewNode(int key)
    {
        TreeNode* node = new TreeNode();
        node->value = key;
        node->left = nullptr;
        node->right = nullptr;
        node->depth = 1;

        return (node);
    }

    TreeNode* Insert(TreeNode* node, int x_key)
    {
        if (m_node_count <= 0)
        {
            m_root_node = node;
        }
        
        if (node == nullptr)
        {
            return (CreateNewNode(x_key));
        }

        if (x_key < node->value)
            node->left = Insert(node->left, x_key);
        else if (x_key > node->value)
            node->right = Insert(node->right, x_key);
        else
            return node;

        node->depth = 1 + GetMax(GetHeight(node->left), GetHeight(node->right));
        
        m_node_count++;
        return node;
    }

    void PrintTree(TreeNode* root)
    {
        if (root != nullptr)
        {
            printf("node value %d at depth %d \n", root->value, root->depth);
            printf("left: ");
            PrintTree(root->left);
            printf("right: ");
            PrintTree(root->right);
        }
    }

    TreeNode* GetRoot()
    {
        return m_root_node;
    }
};

