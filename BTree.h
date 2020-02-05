#ifndef BTREE_H
#define BTREE_H

#define T 15

#include <string>

class BTree {
    struct node {
        std::pair<int, std::string> keys[2*T - 1];
        node *sons[2*T];
        int keysCounter;
        bool isLeaf;

        node() {
            isLeaf = true;
            keysCounter = 0;
        }
    };

public:
    BTree();
    ~BTree();
    void insert(const int &popularity, const std::string &name);
    void erase();
    std::string find(int popularity);

private:
    node* root;
    void splitNode(node *toSplit, node *father);
    std::string search(int &popularity, node *tmp);
};


#endif //BTREE_H
