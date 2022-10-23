//
// Created by neekostar on 07.10.22.
//
#include "/home/neekostar/CLionProjects/TaDS_LAB2/Models/Errors.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
namespace BinarySearchTree {
    const char *Errors::getError() const {
        return m_error.c_str();
    }
    Errors::Errors(std::string error) {
        m_error = error;
        logging();
    }

    void Errors::logging() {
        std::fstream file;
        auto now = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(now);
        file.open(file_name, std::ios::app);
        file <<  "WARNING: " << m_error.c_str() << " | " << std::ctime(&end_time);
        file.close();
    }

    void Errors::setFileName(std::string _name) {
        file_name = _name;
    }
}
