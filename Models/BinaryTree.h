//
// Created by neekostar on 07.10.22.
//
#ifndef LAB2_BINARY_SEARCH_TREE_H
#define LAB2_BINARY_SEARCH_TREE_H

#include <string>

namespace BinarySearchTree {
    struct Node {
        char data;
        Node *left, *right;
        bool state = false;
    };

    class BinaryTree {
    private:
        int countElement{};
        Node *root;
        bool empty = true;
        char DestroyNode(Node *node, char out);

    public:
        Node *addElem(Node *tr, char x);

        void PrintTree(Node *tr, int n);

        Node *getMinimum(Node *tr);

        Node *getMaximum(Node *tr);

        Node *delElem(Node *tr, char x);

        Node *findElem(Node *tr, char x);

        Node *delTree(Node *tr);

        void LKP(Node *&temp); // симметричных обход дерева

        void KLP(Node *&temp); // прямой обход дерева

        void LPK(Node *&temp); // обратный обход дерева

        void insert(char _data);

        Node *insertNode(Node *root, char data);

        char clearTree(char out);

        void Printing(int n);

        void printNode(Node *t, int n);

        int getCountElement() const;

        void LPK_printing();

        void LKP_printing();

        void KLP_printing();

        void checkMinElement();

        void checkMaxElement();

        void findValue();

        void deleteItem();

        void deleteVowels();

        void InfoFileOutput(Node *tr);

        void writeInFile();

        void InfoFileInput(BinarySearchTree::Node *tr);

        void readFromFile();

    };

}

#endif //LAB2_BINARY_SEARCH_TREE_H
