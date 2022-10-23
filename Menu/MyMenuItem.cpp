//
// Created by neekostar on 07.10.22.
//
#include "/home/neekostar/CLionProjects/TaDS_LAB2/Menu/MyMenuItem.h"
#include <any>

namespace BinarySearchTree {

    MyMenuItem::MyMenuItem(string _name, MyMenuItem::func_type _func) {
        name = _name;
        func = _func;
    }

    void MyMenuItem::run(any &param) {
        return func(param);
    }

    void MyMenuItem::print() {
        cout << name;
    }
}