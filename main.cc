#include <iostream>
#include <sstream>
#include <string>
#include "avl.h"




int main()
{
    TreeX tree;
    TreeNodeX* node = NULL;
    TreeNodeY* ynode = NULL;

    int command = 0;
    int x_val = 0;
    int y_val = 0;




    std::string commandstring;
    do
    {
        std::cout << "\n commands: \n"
                     "[1] - insert \n"
                     "[2] - print \n"
                     "[3] - remove\n"

                     "---------------\n"
                     "enter command: ";
        
        std::getline(std::cin, commandstring);
        command = stoi(commandstring);
        std::cout << std::endl;

        switch (command)
        {
        case 1:
        {
            do
            {
                printf("Enter x-pos to insert in tree: ");
                std::getline(std::cin, commandstring);
                x_val = stoi(commandstring);

                printf("Enter y-pos to insert in tree: ");
                std::getline(std::cin, commandstring);
                y_val = stoi(commandstring);
                
            } while (x_val == NULL && y_val == NULL);
            node = tree.Insert(node, x_val, y_val);
            printf("{%d, %d} inserted at [%d]-depth \n", x_val, y_val, node->depth);
            break;
        }

        case 2:
        {
            tree.print2D(node);
            break;

        }

        case 3:
        {
            do
            {
                printf("Enter x-pos to delete: ");
                std::getline(std::cin, commandstring);
                x_val = stoi(commandstring);

            } while (x_val == NULL && y_val == NULL);
            node = tree.Remove(node, x_val);
            break;
        }
        case 4:
        {
            break;
        }
        default:
            break;
        }

    } while (command != 5);
    



}