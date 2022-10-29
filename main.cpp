//
// Created by neekostar on 07.10.22.
//
#include <iostream>
#include "Models/BinaryTree.h"
#include "Menu/MyMenu.h"
#include "Menu/MyMenuItem.h"
#include "Models/Errors.h"
#include <cstdlib>
#include <fstream>
#include <any>
#include <cstring>

using namespace BinarySearchTree;
using namespace std;

const int pointsOfMenu = 15;


void addToTree(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    std::cout << "Введите симво для добавления:";
    char _data;
    std::cin >> _data;
    bt->insert(_data);
    std::cout << "Элемент успешно добавлен!" << std::endl;
}

void SaveData(string file_name, BinaryTree *bt) {
    fstream file;
    string s;
    char symbols[255];
    file.open(file_name);
    while (getline(file, s)){
        strcpy(symbols, s.c_str());
        for (int i = 0; i < s.length(); ++i) {
            bt->insert(symbols[i]);
        }
    }
    file.close();
}

void PrintTree(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    if (bt->getCountElement() == 0) {
        cout << "В дереве нет элементов"<<endl;
    }else {
        bt->Printing(10);
    }
}

void getCountWord(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    if (bt->getCountElement() != 0) {
        cout << "В дереве : " << bt->getCountElement() << " слов.\n";
    } else {
        cout << "В дереве нет элементов";
    }
}

void ext(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    exit(0);
}

void clearTree(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    char s{};
    bt->clearTree(s);
    cout << "Дерево очищено"<<endl;
}

void deleteEl(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    bt->deleteItem();
}

void LPK_print(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    bt->LPK_printing();
}

void LKP_print(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    bt->LKP_printing();
}

void KLP_print(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    bt->KLP_printing();
}

void checkMin(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    bt->checkMinElement();
}

void checkMax(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    bt->checkMaxElement();
}

void findInTree(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    bt->findValue();
}

void personalEx(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    bt->deleteVowels();
}

void fileOutput(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    bt->writeInFile();
}

void fileInput(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    char s{};
    bt->clearTree(s);
    bt->readFromFile();
}


string Errors::file_name = "Errors.txt";


int main(int argc, char *argv[]) {
    std::string load_data_file = "/home/neekostar/CLionProjects/TaDS_LAB2/Input.txt";
    std::string write_data_file = "/home/neekostar/CLionProjects/TaDS_LAB2/Output.txt";
    std::string log_data_file = "/home/neekostar/CLionProjects/TaDS_LAB2/Errors.txt";
    if (argc >= 3) {
        load_data_file = argv[1];
        write_data_file = argv[2];
        log_data_file = argv[3];
    }
    Errors::setFileName(log_data_file);

    BinaryTree *tree = new BinaryTree;
    SaveData(load_data_file, tree);


    MyMenuItem items[pointsOfMenu]{
            MyMenuItem{"Добавить элемент в дерево", addToTree},
            MyMenuItem{"Распечатать дерево", PrintTree},
            MyMenuItem{"Количество элементов в дереве", getCountWord},
            MyMenuItem{"Очистить дерево", clearTree},
            MyMenuItem{"Обратный обход", LPK_print},
            MyMenuItem{"Симметричный обход", LKP_print},
            MyMenuItem{"Прямой обход обход", KLP_print},
            MyMenuItem{"Минимальный элемент дерева", checkMin},
            MyMenuItem{"Максимальный элемент дерева", checkMax},
            MyMenuItem{"Поиск элемента в дереве", findInTree},
            MyMenuItem{"Удаление элемента по ключу", deleteEl},
            MyMenuItem{"Удаление гласных букв из дерева", personalEx},
            MyMenuItem{"Запись дерева в файл", fileOutput},
            MyMenuItem{"Чтение дерева из файла", fileInput},
            MyMenuItem{"Выход из программы", ext}
    };
    MyMenu menu("Меню бинарного дерева", items, pointsOfMenu);
    any param = tree;
    while (true) {
        try {
            menu.runCommand(param);
        }
        catch (const Errors &ex) {
            cout << "Error: " << ex.getError() << endl;
            menu.runCommand(param);
        }
    }
    return 0;
}
