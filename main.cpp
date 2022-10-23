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

const int pointsOfMenu = 6;

void loadTree(std::any &param){
    auto *bt = any_cast<BinaryTree *>(param);
    fstream file;
    string s;
    file.open("Input.txt");
    while (getline(file, s)){
        bt->insert(s);
    }
    file.close();
}

void addToTree(any &param){
    auto *bt = any_cast<BinaryTree *>(param);
    std::cout << "Пожалуйста, введите новое слово  --> ";
    std::string _data;
    std::cin >> _data;
    bt->insert(_data);
    std::cout << "Слово успешно добавлено!\n";
}

void SaveData(string file_name, BinaryTree *bt) {
    ofstream file;
    string s;
    file.open(file_name, std::ios::out);
    s = bt->clearTree(s);
    file << s;
    file.close();
}

void PrintTree(any &param){
    auto *bt = any_cast<BinaryTree *>(param);
    if (bt->getCountElement() == 0) cout << "Словарь пуст.\n";
    else if (bt->getCountElement() > 20) {
        cout
                << "Количество слов в словаре превышает 20. Отображение может быть некорректным.\nВы уверены, что хотите распечатать словарь?\n1) Да\n0) Вернуться назад\n==> ";
        int ind{};
        cin >> ind;
        switch (ind) {
            case 1:
                bt->Printing(10);
            case 0:
                break;
            default:
                break;
        }
    } else {
        bt->Printing(10);
    }
}

void getCountWord(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    if (bt->getCountElement() != 0) {
        cout << "Количество слов в словаре: " << bt->getCountElement() << " слов.\n";
    } else {
        cout << "Словарь пуст";
    }
}

void ext(any& param) {
    auto *bt = any_cast<BinaryTree *>(param);
    cout << "Выполняется сохранение данных в выходной файл";
    SaveData("Output.txt", bt);
    exit(0);
}

void clearTree(any &param) {
    auto *bt = any_cast<BinaryTree *>(param);
    bt->clearTree("");
    cout << "Очистка словаря завершена.\n";
}

//void deleteEl(any &param) {
//    auto *bt = any_cast<BinaryTree *>(param);
//    std::cout << "Пожалуйста, введите слово для удаления  --> ";
//    std::string _data;
//    std::cin >> _data;
//    //нужно допилить!
//    bt->deleteEl(_data);
//    std::cout << "Слово успешно удалено!\n";
//}



string Errors::file_name="Errors.txt";


int main(int argc, char* argv[]) {
    std::string load_data_file = "Input.txt";
    std::string write_data_file = "Output.txt";
    std::string log_data_file = "Errors.txt";
    if (argc >= 3) {
        load_data_file = argv[1];
        write_data_file = argv[2];
        log_data_file = argv[3];
    }
    Errors::setFileName(log_data_file);

    BinaryTree *tree = new BinaryTree;

    MyMenuItem items[pointsOfMenu]{
            MyMenuItem{"Добавить элемент в дерево", addToTree},
            MyMenuItem{"Распеччатать дерево", PrintTree},
            MyMenuItem{"Количество элементов", getCountWord},
            MyMenuItem{"Очистить", clearTree},
            MyMenuItem{"Добавить в файл", loadTree},
            MyMenuItem{"Выход из программы", ext}
    };
    MyMenu menu("Меню бинарного дерева", items, pointsOfMenu);
    any param = tree;
    while (true){
        try {
            menu.runCommand(param);
        }
        catch (const Errors &ex){
            cout<<"Error: "<<ex.getError()<<endl;
        }
    }
    return 0;
}
