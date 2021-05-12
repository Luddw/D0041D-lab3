#include <iostream>
#include "avl.h"




int main()
{
    Tree tree = Tree();
    TreeNode* node = new TreeNode();
    node->value = 123123;
    tree.Insert(node, 123123);
    tree.PrintTree(tree.GetRoot());
}