#include <iostream>
#include <vector>
#include "student.h"

class h_double {
    private:
        std::vector<student> *double_table;
        int double_size;
    public:
        h_double(int size_);
        ~h_double();
        void add(unsigned int SN, std::string LN);
        void find(unsigned int SN);
        void remove(unsigned int SN);
        int hash_1(unsigned int key);
        int hash_2(unsigned int key);

        //void test_printing();

};