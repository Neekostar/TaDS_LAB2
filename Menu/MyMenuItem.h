//
// Created by neekostar on 07.10.22.
//
#pragma once

#include <iostream>
#include <string>
#include <any>
#include "/home/neekostar/CLionProjects/TaDS_LAB2/Models/Errors.h"

using namespace std;
namespace BinarySearchTree {

    class MyMenuItem {
    public:
        using func_type = void (*)(any &param);

        MyMenuItem(string _name, func_type _func);

        void run(any &param);

        void print();


    private:
        std::string name{};
        func_type func;
    };
}//MYMENU_CPP_MYMENUITEM_H
