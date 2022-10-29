//
// Created by neekostar on 07.10.22.
//
#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include "Errors.h"
#include <cstring>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>

namespace BinarySearchTree {
    void BinaryTree::LKP(Node *&temp) {
        if (temp != nullptr) {
            LKP(temp->left);
            std::cout << std::setw(8) << temp->data;
            LKP(temp->right);
        }
    }

//--------------------------------------------------------------------------
// прямой порядок обхода (корень-влево-вправо)
//--------------------------------------------------------------------------
    void BinaryTree::KLP(Node *&temp) {
        if (temp != nullptr) {
            std::cout << std::setw(8) << temp->data;
            KLP(temp->left);
            KLP(temp->right);
        }
    }

//--------------------------------------------------------------------------
// обратный порядок обхода (влево-вправо-корень)
//--------------------------------------------------------------------------
    void BinaryTree::LPK(Node *&temp) {
        if (temp != nullptr) {
            LPK(temp->left);
            LPK(temp->right);
            std::cout << std::setw(8) << temp->data;
        }
    }

    Node *BinaryTree::addElem(Node *tr, char x) {
        if (tr == nullptr) {
            tr = new Node;
            tr->data = x;
            tr->left = tr->right = nullptr;
            return tr;
        } else if (x < tr->data) {
            tr->left = addElem(tr->left, x);
        } else if (x > tr->data) {
            tr->right = addElem(tr->right, x);
        }
        countElement++;
        return tr;
    }

    void BinaryTree::PrintTree(Node *tr, int n) {
        if (tr != nullptr) {
            PrintTree(tr->right, n + 1);
            for (int i = 0; i < n; i++) std::cout << "-";
            std::cout << tr->data;
            PrintTree(tr->left, n + 1);
        } else std::cout << std::endl;
    }

    Node *BinaryTree::getMaximum(BinarySearchTree::Node *tr) {
        if (!tr->right) {
            return tr;
        }
        return getMaximum(tr->right);
    }

    Node *BinaryTree::getMinimum(BinarySearchTree::Node *tr) {
        if (!tr->left) {
            return tr;
        }
        return getMinimum(tr->left);
    }

    void BinaryTree::checkMinElement() {
        if (!empty) {
            std::cout << "Минимальный элемент в дереве" << std::endl;
            char result = getMinimum(root)->data;
            std::cout << (result) << std::endl;
        }

    }

    void BinaryTree::checkMaxElement() {
        if (!empty) {
            std::cout << "Максимальный элемент в дереве" << std::endl;
            char result = getMaximum(root)->data;
            std::cout << (result) << std::endl;
        }

    }

    Node *BinaryTree::delElem(BinarySearchTree::Node *tr, char x) {
        if (tr == nullptr) {
            return tr;
        }
        if (x == tr->data) {
            Node *tmp;
            if (tr->right == nullptr)
                tmp = tr->left;
            else {
                Node *ptr = tr->right;
                if (ptr->left == nullptr) {
                    ptr->left = tr->left;
                    tmp = ptr;
                } else {
                    Node *pmin = ptr->left;
                    while (pmin->left != nullptr) {
                        ptr = pmin;
                        pmin = ptr->left;
                    }
                    ptr->left = pmin->right;
                    pmin->left = tr->left;
                    pmin->right = tr->right;
                    tmp = pmin;
                }
            }
            delete tr;
            return tmp;
        } else if (x < tr->data) {
            tr->left = delElem(tr->left, x);
        } else {
            tr->right = delElem(tr->right, x);
        }
        countElement--;
        return tr;
    }

    void BinaryTree::deleteItem() {
        LKP(root);
        std::cout << "Введите элемент, который хотите удалить" << std::endl;
        char valueForDel{};
        std::cin >> valueForDel;
        if (empty) {
            std::cout << "Ваше дерево пустое" << std::endl;
        } else {
            Node *check = findElem(root, valueForDel);
            if (check) {
                delElem(root, valueForDel);
            } else {
                std::cout << "Нет такого элемента в дереве" << std::endl;
            }
        }
    }

    void BinaryTree::deleteVowels() {
        std::cout << "Изначальное дерево" << std::endl;
        LKP(root);
        char vowels[] = "aeiouy";

        for (int i = 0; i < countElement; ++i) {
            delElem(root, vowels[0]);
            delElem(root, vowels[1]);
            delElem(root, vowels[2]);
            delElem(root, vowels[3]);
            delElem(root, vowels[4]);
            delElem(root, vowels[5]);

        }
        std::cout << std::endl << "Результат" << std::endl;
        LKP(root);
    }

    Node *BinaryTree::findElem(BinarySearchTree::Node *tr, char x) {
        Node *current = tr;
        while (current != nullptr)
            if (x == current->data)
                return current;
            else
                current = x < current->data ? current->left : current->right;
        return nullptr;
    }

    void BinaryTree::findValue() {
        std::cout << "Введите значение для поиска" << std::endl;
        char value{};
        std::cin >> value;
        Node *result = findElem(root, value);
        if (result) {
            std::cout << "Такой элемент присутствует в дереве" << std::endl;
            std::cout << "Адрес вашего элемента: " << findElem(root, value) << std::endl;
        } else {
            std::cout << "Нет такого элемента в дереве" << std::endl;
        }

    }

    Node *BinaryTree::delTree(BinarySearchTree::Node *tr) {
        if (tr != nullptr) {
            delTree(tr->left);
            delTree(tr->right);
            delete tr;
            tr = nullptr;
            countElement = 0;
            return tr;
        }
    }


    void BinaryTree::insert(char _data) {
        root = insertNode(root, _data);
        empty = false;
        countElement++;
    }

    Node *BinaryTree::insertNode(Node *root, char data) {
        if (root == nullptr) {
            root = new Node;
            root->data = data;
            root->left = nullptr;
            root->right = nullptr;
        } else if (data < root->data) {
            root->left = insertNode(root->left, data);
        } else if (data > root->data) {
            root->right = insertNode(root->right, data);
        }
        return root;
    }

    char BinaryTree::DestroyNode(BinarySearchTree::Node *node, char out) {
        if (node) {
            if (node->state == false) {
                out = DestroyNode(node->left, out);
                out = DestroyNode(node->right, out);
                node->state = true;
            }
            delete node;
        }
        countElement--;
        return out;
    }

    char BinaryTree::clearTree(char out) {
        out = DestroyNode(root, out);
        root = nullptr;
        empty = true;
        countElement = 0;
        return out;
    }

    void BinaryTree::Printing(int n) {
        if (!empty) {
            printNode(root, n);
        }
    }

    void BinaryTree::LPK_printing() {
        if (!empty) {
            std::cout << "Обратный обход" << std::endl;
            LPK(root);
        }
    }

    void BinaryTree::LKP_printing() {
        if (!empty) {
            std::cout << "Симметричный обход" << std::endl;
            LKP(root);
        }
    }

    void BinaryTree::KLP_printing() {
        if (!empty) {
            std::cout << "Прямой обход" << std::endl;
            KLP(root);
        }
    }

    void BinaryTree::printNode(Node *t, int n) {
        if (t) {
            printNode(t->right, n + 2);
            for (int i = 0; i < n; i++) {
                std::cout << " ";
            }
            std::cout << t->data;
            printNode(t->left, n + 2);
        } else {
            std::cout << std::endl;
        }

    }


    int BinaryTree::getCountElement() const {
        return countElement;
    }

    void BinaryTree::InfoFileOutput(Node *tr) {
        std::ofstream fout;
        fout.open("/home/neekostar/CLionProjects/TaDS_LAB2/Output.txt", std::ios::app);
        if (fout.is_open()) {
            if (tr != NULL) {
                fout << tr->data << std::setw(8);
                InfoFileOutput(tr->left);
                InfoFileOutput(tr->right);
            }
        } else std::cout << "Не записано!\n";
        fout.close();
    }

    void BinaryTree::InfoFileInput(BinarySearchTree::Node *tr) {
        std::fstream file;
        std::string s;
        char symbols[255];
        file.open("/home/neekostar/CLionProjects/TaDS_LAB2/Input.txt");

        while (getline(file, s)) {
            strcpy(symbols, s.c_str());
            for (int i = 0; i < s.length(); ++i) {
                insert(symbols[i]);
            }
        }
        file.close();
    }

    void BinaryTree::writeInFile() {
        InfoFileOutput(root);
    }

    void BinaryTree::readFromFile() {
        InfoFileInput(root);
    }

}