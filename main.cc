#include <iostream>
#include "avl.h"




int main()
{
    Tree tree;
    TreeNode* node = NULL;

    int command = 0;
    int val = 0;

    do
    {
        std::cout << "\n commands: \n"
                     "[1] - insert \n"
                     "[2] - print \n"
                     "---------------\n"
                     "enter command: ";
        std::cin >> command;
        std::cout << std::endl;

        switch (command)
        {
        case 1:
        {
            do
            {
                printf("Enter number to insert in tree: ");
                std::cin >> val;
                
            } while (val < 1);

            node = tree.Insert(node,val);
            printf("%d inserted at [%d] \n", node->value, node->depth);
            break;
        }

        case 2:
        {
            tree.PrintTree(node);
            break;
        }

        case 3:
        {

            break;
        }
        default:
            break;
        }

    } while (command != 5);
    



}