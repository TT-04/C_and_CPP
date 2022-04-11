#include <iostream>
#include "support1.hpp"

int main()
{
    constexpr size_t CH_NUM = 3;

    NTree<int, CH_NUM> tr;
    NTree<int, CH_NUM>::Node* currNode = tr.getRoot();

    while(true)
    {
        char cmd = 'A';

        std::cin >> cmd;
        switch(cmd)
        {
            case 'e': // exit
                return 0;

            case 's': // set value
                {
                    int val = 0;
                    std::cin >> val;
                    currNode->data = val;
                }
                break;

            case 'p': // go to parent
                if (currNode->getParent() != nullptr)
                    currNode = currNode->getParent();
                break;
            
            case 'c': // go to child
                {
                    size_t id = 0;
                    std::cin >> id;
                    if (currNode->getChild(id) != nullptr)
                        currNode = currNode->getChild(id);
                }
                break;

            case 'n': // add new node
                {
                    size_t id = 0;
                    int value = 0;
                    std::cin >> id;
                    std::cin >> value;

                    currNode->addChild(id, value);
                }
                break;

            case 'd': // display
                std::cout << tr;
                break;

            case 'r': // delete Node
               { 
                   NTree<int, CH_NUM>::Node* dead = currNode->getParent();
                    delete currNode;
                    currNode = dead;
               }
                break;
               

            default:
                std::cout << "wrong cmd" << std::endl;
                break;
        }
    }

    return 0;
}