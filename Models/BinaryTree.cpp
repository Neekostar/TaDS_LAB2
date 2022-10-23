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
//    BinaryTree::BinaryTree() {
//        head = nullptr;
//        tail = nullptr;
//        lenList = 0;
//    }
//
//    BinaryTree::~BinaryTree() {
//        while (head) {
//            tail = head->next;
//            delete head;
//            head = tail;
//        }
//        lenList = 0;
//    }

//
////    void BinaryTree::deleteTree() {
////        Node **root = nullptr;
////        helpToRemoveBinaryTree(root);
////    }
//
//    void BinaryTree::createNode() {
//        int data{};
//        std::cout << "Введите элемент для добавления" << std::endl;
//        std::cin >> data;
//        helpToCreateNode(data);
//    }
//
//    void BinaryTree::insertElement() {
//        int value{};
//        std::cout << "Введите элемент для добавления" << std::endl;
//        std::cin >> value;
//        Node **temp = nullptr;
//        helpToInsert(temp, value);
//    }

//
//    bool BinaryTree::isUniqueValueInsert(Node *temp, const int checking_value) {
//        // "прошли" все дерево, не встретив дубликатного значения
//        if (temp == NULL) {
//            return true;
//        }
//
//        // встали на узел, имеющий такой же ключ (встретили дубликат)
//        if (checking_value == temp->data) {
//            return false;
//        }
//
//        // продвигаемся по дереву
//        if (checking_value < temp->data) {
//            return isUniqueValueInsert(temp->left, checking_value);
//        } else {
//            return isUniqueValueInsert(temp->right, checking_value);
//        }
//    }

    void BinaryTree::LKP(Node *&temp) {
        if (temp != NULL) {
            LKP(temp->left);
            std::cout << std::setw(8) << temp->data;
            LKP(temp->right);
        }
    }

//
////--------------------------------------------------------------------------
//// прямой порядок обхода (корень-влево-вправо)
////--------------------------------------------------------------------------
    void BinaryTree::KLP(Node *&temp) {
        if (temp != NULL) {
            std::cout << std::setw(8) << temp->data;
            KLP(temp->left);
            KLP(temp->right);
        }
    }

//
////--------------------------------------------------------------------------
//// обратный порядок обхода (влево-вправо-корень)
////--------------------------------------------------------------------------
    void BinaryTree::LPK(Node *&temp) {
        if (temp != NULL) {
            LPK(temp->left);
            LPK(temp->right);
            std::cout << std::setw(8) << temp->data;
        }
    }
//
//    bool BinaryTree::SearchNodeByKey(Node *temp, const int value) {
//        if (temp == NULL)
//            return false;
//
//        if (temp->data == value)
//            return true;
//
//        if (value < temp->data)
//            return (SearchNodeByKey(temp->left, value));
//        else
//            return (SearchNodeByKey(temp->right, value));
//    }
//
//    void BinaryTree::searchElement() {
//        Node* temp = nullptr;
//        int value{};
//        std::cout<<"Введите значение для поиска"<<std::endl;
//        std::cin>>value;
//        bool result = SearchNodeByKey(temp, value);
//        std::cout<<result<<std::endl;
//    }
//
////--------------------------------------------------------------------------
//// подсчет количество узлов дерева (рекурсивный обход)
////--------------------------------------------------------------------------
//    int BinaryTree::GetCountNodes(Node *temp) {
//
//        if (temp == NULL)
//            return 0;
//        else
//            return GetCountNodes(temp->left) + GetCountNodes(temp->right) + 1;
//    }
//
////--------------------------------------------------------------------------
//// подсчет количество узлов-листьев дерева (рекурсивный обход)
////--------------------------------------------------------------------------
//    int BinaryTree::GetCountLeaves(Node *temp) {
//        if (temp == NULL)
//            return 0;
//
//        if ((temp->left == NULL) && (temp->right == NULL))
//            return 1;
//        else
//            return (GetCountLeaves(temp->left) + GetCountLeaves(temp->right));
//    }
//
//    void BinaryTree::DeleteBinaryTree(Node **proot) {
//        if (*proot != NULL) {
//            DeleteBinaryTree(&((*proot)->left));
//            DeleteBinaryTree(&((*proot)->right));
//
//            // текущий удаляемый узел гарантировано является листом
//            delete *proot;
//            *proot = NULL;
//        }
//    }
//
//    void BinaryTree::deleteTree() {
//        Node **temp = nullptr;
//        DeleteBinaryTree(temp);
//    }
//
//    void BinaryTree::countNodes() {
//        Node *temp = nullptr;
//        int result = GetCountNodes(temp);
//        std::cout<<result<<std::endl;
//    }
//
//    void BinaryTree::countLeaves() {
//        Node* temp = nullptr;
//        int result = GetCountLeaves(temp);
//        std::cout<<result<<std::endl;
//    }

//    void BinaryTree::outputFile(Node *tr, int n) {
//        std::ofstream fout;
//        fout.open("/home/neekostar/CLionProjects/TaDS_LAB2/Output.txt", std::ios::out);
//        if (fout.is_open()) {
//            if (tr != NULL) {
//                outputFile(tr->right, n + 1);
//                for (int i = 0; i < n; i++) fout << "-";
//                fout << tr->data;
//                outputFile(tr->left, n + 1);
//            } else fout << std::endl;
//
//            std::cout << "Запись в файл завершена!" << std::endl;
//            fout.close();
//        } else {
//            throw Errors{"File didn't open"};
//        }
//
//
//    }

//
//    void BinaryTree::inputFromFile(Node *tr) {
//        std::ifstream in;
//        std::string line;
//        char temp;
//        in.open("/home/neekostar/CLionProjects/TaDS_LAB2/Input.txt", std::ios::in);
//        if (in.is_open()) {
//            while (in.get(temp) && !in.eof()) {
//                if (std::isdigit(temp) || std::isalpha(temp)) {
//                    addElem(tr, temp);
//                }
//            }
//            in.close();
//            std::cout << "Чтение файла завершено!" << std::endl;
//            PrintTree(tr, lenList);
//        } else {
//            throw Errors{"File didn't open"};
//        }
//    }

    Node *BinaryTree::addElem(Node *tr, std::string x) {
        if (tr == NULL) {
            tr = new Node;
            tr->data = x;
            tr->left = tr->right = NULL;
            return tr;
        } else if (x < tr->data) {
            tr->left = addElem(tr->left, x);
        } else if (x > tr->data) {
            tr->right = addElem(tr->right, x);
        }
        return tr;
    }

    void BinaryTree::PrintTree(Node *tr, int n) {
        if (tr != NULL) {
            PrintTree(tr->right, n + 1);
            for (int i = 0; i < n; i++) std::cout << "-";
            std::cout << tr->data;
            PrintTree(tr->left, n + 1);
        } else std::cout << std::endl;
    }

    void BinaryTree::PrintLevel(BinarySearchTree::Node *tr, int level) {
        if (tr == NULL) {
            return;
        } else {
            PrintLevel(tr->left, level - 1);  // Ñ ïîìîùüþ ðåêóðñèè ïîñåùàåì ëåâîå ïîääåðåâî
            if (level == 0) {
                // level áóäåò ðàâåí íóëþ íà íóæíîé ãëóáèíå, òàê êàê ïðè êàæäîì ðåêóðñèâíîì âûçîâå çíà÷åíèå level óìåíüøàåòñÿ íà îäèí
                std::cout << tr->data << std::endl;  // Ïîêàçûâàåì ýëåìåíò, åñëè îí íà íóæíîì íàì óðîâíå
            }
            PrintLevel(tr->right, level - 1);  // Ñ ïîìîùüþ ðåêóðñèè ïîñåùàåì ïðàâîå ïîääåðåâî
        }
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

    Node *BinaryTree::delElem(BinarySearchTree::Node *tr, std::string x) {
        if (tr == NULL) {
            return tr;
        }
        if (x == tr->data) {
            Node *tmp;
            if (tr->right == NULL)
                tmp = tr->left;
            else {
                Node *ptr = tr->right;
                if (ptr->left == NULL) {
                    ptr->left = tr->left;
                    tmp = ptr;
                } else {
                    Node *pmin = ptr->left;
                    while (pmin->left != NULL) {
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
        return tr;
    }

    Node *BinaryTree::findElem(BinarySearchTree::Node *tr, std::string x) {
        Node *current = tr;
        while (current != NULL)
            if (x == current->data)
                return current;
            else
                current = x < current->data ? current->left : current->right;
        return NULL;
    }

    bool BinaryTree::CheckForEmpty(BinarySearchTree::Node *&tr) {
        bool check = false;
        if (!tr) {
            check = true;
        }
        return check;
    }

    Node *BinaryTree::delTree(BinarySearchTree::Node *tr) {
        if (tr != NULL) {
            delTree(tr->left);
            delTree(tr->right);
            delete tr;
            tr = NULL;
            return tr;
        }


    }

    void BinaryTree::insert(std::string _data) {
        root=insertNode(root, _data);
        empty=false;
        countElement++;
    }

    Node *BinaryTree::insertNode(Node *_root, std::string _data) {
        if (_root == nullptr) {
            _root = new Node;
            _root->data = _data;
            _root->left = nullptr;
            _root->right = nullptr;
        } else if (_data < _root->data) {
            _root->left = insertNode(_root->left, _data);
        } else if (_data > _root->data) {
            _root->right = insertNode(_root->right, _data);
        }
        return _root;
    }

    std::string BinaryTree::DestroyNode(BinarySearchTree::Node *node, std::string out) {
        if (node) {
            if (node->state == false) {
                out += node->data + "\n";
                out = DestroyNode(node->left, out);
                out = DestroyNode(node->right, out);
                node->state = true;
            }
            delete node;
            countElement--;
        }
        return out;
    }

    std::string BinaryTree::clearTree(std::string out) {
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

    void BinaryTree::printNode(Node *t, int n) {
        if (t) {
            printNode(t->right, n + 2);
            for (int i = 0; i < n; i++) {
                std::cout << "-";
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

}