#include <iostream>

#include <BTree.h>

int main() {
    int howManyCommands, popularity;
    std::cin >> howManyCommands;

    BTree Tree;
    std::string command, name;
    for (int i = 0; i < howManyCommands; ++i) {
        std::cin >> command;
        if (command == "A") {
            std::cin >> popularity >> name;
            Tree.insert(popularity, name);
        }
    }

    return 0;
}