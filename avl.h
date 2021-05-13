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
    if (node == NULL)
    {
        return 0;
    }
    return node->depth;
}

int GetBalance(TreeNode* node)
{
    if (node == NULL)
    {
        return 0;
    }

    return GetHeight(node->left) - GetHeight(node->right);
}


class Tree
{
private:
    TreeNode* m_root_node;
    size_t m_node_count;
public:
    Tree() : m_node_count(0) { m_root_node = NULL;};
    ~Tree() {};

    TreeNode* CreateNewNode(int key)
    {
        TreeNode* node = new TreeNode();
        node->value = key;
        node->left = NULL;
        node->right = NULL;
        node->depth = 1;

        return (node);
    }

    TreeNode* Insert(TreeNode* node, int x_key)
    {
        if (m_node_count <= 0)
        {
            m_root_node = node;
        }
        
        if (node == NULL)
        {
            return (CreateNewNode(x_key));
        }

        if (x_key < node->value)
            node->left = Insert(node->left, x_key);
        else if (x_key > node->value)
            node->right = Insert(node->right, x_key);
        else
            return node;

        // update depth
        node->depth = 1 + GetMax(GetHeight(node->left), GetHeight(node->right));
        

        // balance
        int balance = GetBalance(node);

        // Left Left
        if (balance > 1 && x_key < node->left->value)
            return RotateRight(node);
        // Right Right 
        if (balance < -1 && x_key > node->right->value)
            return RotateLeft(node);
        // Left Right 
        if (balance > 1 && x_key > node->left->value)
        {
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }
        // Right Left 
        if (balance < -1 && x_key < node->right->value)
        {
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }
        
        m_node_count++;
        return node;
    }


    void PrintTree(TreeNode* root)
    {
        if (root != NULL)
        {
            printf("node value %d at depth %d \n", root->value, root->depth);
            PrintTree(root->left);
            PrintTree(root->right);
        }
    }

    TreeNode* GetRoot()
    {
        return m_root_node;
    }

    TreeNode* RotateLeft(TreeNode* a)
    {
        TreeNode* b = a->right;
        TreeNode* subtree2 = b->left;

        b->left = a;
        a->right = subtree2;

        // update depth
        a->depth = GetMax(GetHeight(a->left), GetHeight(b->right)) + 1;
        b->depth = GetMax(GetHeight(b->left), GetHeight(b->right)) + 1;

        return b;
    }

    TreeNode* RotateRight(TreeNode* a)
    {
        TreeNode* b = a->left;
        TreeNode* subtree2 = b->right;

        b->right = a;
        a->right = subtree2;

        // update depth
        a->depth = GetMax(GetHeight(a->left), GetHeight(b->right)) + 1;
        b->depth = GetMax(GetHeight(b->left), GetHeight(b->right)) + 1;

        return b;
    }

};


        /* --Rotate
                 c                               c
                / \                            /   \ 
               b   T4  right Rotate (b)        a    T4 
              / \      - - - - - - - - ->    /  \      
            T1   a                          b    T3     
                / \                        / \
              T2   T3                    T1   T2
    
        */