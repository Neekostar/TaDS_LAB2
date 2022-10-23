//
// Created by neekostar on 07.10.22.
//
#ifndef LAB2_BINARY_SEARCH_TREE_H
#define LAB2_BINARY_SEARCH_TREE_H
#include <string>

namespace BinarySearchTree {
    struct Node {
        std::string data;
        Node *left, *right;
        bool state= false;
    };

    class BinaryTree {
    private:
//        Node *head, *tail;
//
        int countElement{}; //вспомогательный метод определения длины списка
        Node* root;
        bool empty = true;
        std::string DestroyNode(Node* node, std::string out);
//        bool isUniqueValueInsert(Node *temp, const int checking_value);
//
//        void DeleteBinaryTree(Node **temp); // удаление всех узлов из дерева
//
//        int GetCountNodes(Node *temp); // подсчет узлов дерева
//
//        int GetCountLeaves(Node *temp); // подсчет узлов-листьев дерева
    public:
//        BinaryTree();
//
//        ~BinaryTree();
        Node *addElem(Node *tr, std::string x);

        void PrintTree(Node *tr, int n);

        void PrintLevel(Node *tr, int level);

        bool CheckForEmpty(Node *&tr);

        Node *getMinimum(Node *tr);

        Node *getMaximum(Node *tr);

        Node *delElem(Node *tr, std::string x);

        Node *findElem(Node *tr, std::string x);

        Node *delTree(Node *tr);

        void LKP(Node *&temp); // симметричных обход дерева

        void KLP(Node *&temp); // прямой обход дерева

        void LPK(Node *&temp); // обратный обход дерева

//        void outputFile(Node *tr, int n);
//
//        void inputFromFile(Node *tr);

        void insert(std::string _data);

        Node *insertNode(Node *_root, std::string _data);
        std::string clearTree(std::string out);
        void Printing(int n);
        void printNode(Node *t, int n);
        int getCountElement() const;

    };

}

#endif //LAB2_BINARY_SEARCH_TREE_H
