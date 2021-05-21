#pragma once
#include <iostream>
#include "treey.h"
#define COUNT 10

class TreeX;
class TreeY;

struct TreeNodeX
{
    TreeY* y_tree = new TreeY;
    TreeNodeX* left;
    TreeNodeX* right;
    int value;
    int depth;
};
TreeNodeX* minValueNode(TreeNodeX* node)
{
    TreeNodeX* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}
class TreeX
{
private:
    TreeNodeX* m_root_node;
    size_t m_node_count;
public:
    TreeX() : m_node_count(0) { m_root_node = NULL;};
    ~TreeX() {};


    TreeNodeX* Remove(TreeNodeX* root, int key)
    {
        if (root == NULL)
            return root;

        if (key < root->value)
            root->left = Remove(root->left, key);

  
        else if (key > root->value)
            root->right = Remove(root->right, key);


        else
        {
           
            if ((root->left == NULL) ||
                (root->right == NULL))
            {
                TreeNodeX* temp = root->left ?
                    root->left :
                    root->right;

              
                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else 
                    *root = *temp;
                                  
                free(temp);
            }
            else
            {
  
                TreeNodeX* temp = minValueNode(root->right);

                root->value = temp->value;

                root->right = Remove(root->right,
                    temp->value);
            }
        }

  
        if (root == NULL)
            return root;

   
        root->depth = 1 + GetMax(GetHeight(root->left),
            GetHeight(root->right));

        int balance = GetBalance(root);

  
        // Rotations 

        // Left Left 
        if (balance > 1 &&
            GetBalance(root->left) >= 0)
            return RotateRight(root);

        // Left Right 
        if (balance > 1 &&
            GetBalance(root->left) < 0)
        {
            root->left = RotateLeft(root->left);
            return RotateRight(root);
        }

        // Right Right 
        if (balance < -1 &&
            GetBalance(root->right) <= 0)
            return RotateLeft(root);

        // Right Left 
        if (balance < -1 &&
            GetBalance(root->right) > 0)
        {
            root->right = RotateRight(root->right);
            return RotateLeft(root);
        }

        return root;
    }

    TreeNodeX* CreateNewNode(int key, int y_val)
    {
        TreeNodeX* node = new TreeNodeX();
        node->y_tree->InsertAtRoot(y_val);
        node->value = key;
        node->left = NULL;
        node->right = NULL;
        node->depth = 1;

        return (node);
    }

    int GetHeight(TreeNodeX* node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->depth;
    }

    int GetBalance(TreeNodeX* node)
    {
        if (node == NULL)
        {
            return 0;
        }

        return GetHeight(node->left) - GetHeight(node->right);
    }
    
    TreeNodeX* Insert(TreeNodeX* node, int x_key, int ytree)
    {
        if (m_node_count <= 0)
        {
            m_root_node = node;
        }
        
        if (node == NULL)
        {
            return (CreateNewNode(x_key, ytree));
        }

        if (x_key < node->value)
            node->left = Insert(node->left, x_key, ytree);
        else if (x_key > node->value)
            node->right = Insert(node->right, x_key, ytree);
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


    void PrintTree(TreeNodeX* root)
    {
        if (root != NULL)
        {
            printf("node value %d at depth %d \n", root->value, root->depth);
            PrintTree(root->left);
            PrintTree(root->right);
        }
    }

    TreeNodeX* GetRoot()
    {
        return m_root_node;
    }

    TreeNodeX* RotateLeft(TreeNodeX* a)
    {
        TreeNodeX* b = a->right;
        TreeNodeX* subtree2 = b->left;

        b->left = a;
        a->right = subtree2;

        // update depth
        a->depth = GetMax(GetHeight(a->left), GetHeight(b->right)) + 1;
        b->depth = GetMax(GetHeight(b->left), GetHeight(b->right)) + 1;

        return b;
    }

    TreeNodeX* RotateRight(TreeNodeX* a)
    {
        TreeNodeX* b = a->left;
        TreeNodeX* subtree2 = b->right;

        b->right = a;
        a->right = subtree2;

        // update depth
        a->depth = GetMax(GetHeight(a->left), GetHeight(b->right)) + 1;
        b->depth = GetMax(GetHeight(b->left), GetHeight(b->right)) + 1;

        return b;
    }


    void print2DUtil(TreeNodeX *root, int space) 
    { 
        // Base case 
        if (root == NULL) 
            return; 
    
        // Increase distance between levels 
        space += COUNT; 
    
        // Process right child first 
        print2DUtil(root->right, space); 
    
        // Print current node after space 
        // count 
        std::cout << std::endl; 
        for (int i = COUNT; i < space; i++) 
            std::cout<<" "; 
        std::cout<< "x: " << root->value << "y: ";
        root->y_tree->PrintTree(root->y_tree->GetRoot());
        std::cout << "\n";
    
        // Process left child 
        print2DUtil(root->left, space); 
    } 
  
// Wrapper over print2DUtil() 
    void print2D(TreeNodeX *root) 
    { 
        // Pass initial space count as 0 
        print2DUtil(root, 0); 
    }
};




