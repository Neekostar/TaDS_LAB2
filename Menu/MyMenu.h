

#include "/home/neekostar/CLionProjects/TaDS_LAB2/Menu/MyMenuItem.h"
#include "/home/neekostar/CLionProjects/TaDS_LAB2/Models/Errors.h"
#include <any>
#include <iostream>

namespace BinarySearchTree {
using namespace std;
    class MyMenu {
    public:
        using func_type = void (*)(std::any &param);

        MyMenu();

        MyMenu(string _name, MyMenuItem *items, size_t count);

        void print();

        void runCommand(any &param);

    private:
        int m_select{-1};
        size_t m_count{};
        string m_title{};
        MyMenuItem *m_items{};
    };

}
 //MYMENU_CMENU_H
