#include <iostream>
#include <vector>
#include "student.h"

class h_chaining {
    private:
        std::vector<student*> *chain_table;
        int chain_size;
    public:
        h_chaining(int size_);
        ~h_chaining();
        int hash_func(unsigned int key);
        void add(unsigned int SN, std::string lastname);
        void find(unsigned int SN);
        void remove(unsigned int SN);
        void print(int index);
};