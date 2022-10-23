//
// Created by neekostar on 07.10.22.
//
#ifndef LAB1_MYEXCEPTION_H
#define LAB1_MYEXCEPTION_H
#include <string>
#include <string_view>
namespace BinarySearchTree {

    class Errors {
    private:
        void logging();
        std::string m_error;

    public:
        Errors(std::string error);
        const char* getError() const;
        static void setFileName(std::string _name);
        static std::string file_name;
    };

} // KVA

#endif //TADS_LAB2_ERRORS_H

