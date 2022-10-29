//
// Created by nekit on 17.09.2022.
//
#include "/home/neekostar/CLionProjects/TaDS_LAB2/Menu/MyMenu.h"
#include <string>
#include <any>
namespace BinarySearchTree {
    MyMenu::MyMenu() {}

    MyMenu::MyMenu(string _name, MyMenuItem *items, size_t count) : m_title(_name), m_items(items), m_count(count) {}

    void MyMenu::print() {
        std::cout << m_title << "\n";
        for (size_t i{}; i < m_count; ++i) {
            std::cout << i + 1 << ". ";
            m_items[i].print();
            std::cout << std::endl;
        }
    }

    void MyMenu::runCommand(std::any &param) {
        cout << "\n";
        print();
        cout << "\nВыберите пункт меню: ";
        cin >> m_select;
        if (m_select > m_count || m_select <= 0) {
            throw Errors{"Wrong index command in menu"};
        }

        return m_items[m_select - 1].run(param);

    }
}