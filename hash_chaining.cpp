#include <iostream>
#include <vector>
#include "hash_chaining.h"

h_chaining::h_chaining(int size_) {
    chain_size = size_;
    chain_table = new std::vector<student*>[size_];
    std::cout << "success" << std::endl;

    }

h_chaining::~h_chaining() {
    delete [] chain_table;
    }
int h_chaining::hash_func(unsigned int key) {
    return key%chain_size;
}

void h_chaining::add(unsigned int SN, std::string lastname) {
    student *new_student = new student(SN, lastname);
    int index_ = hash_func(SN);
    std::vector<student*> temp;
    bool duplicate = false;
    int saved_index = 0;
    if(chain_table[index_].size() == 0) {
        temp.push_back(new_student);
    } else {
        for(int i{0}; i<chain_table[index_].size(); ++i ) {
            if (SN == chain_table[index_][i]->get_SN()) {
                std::cout << "failure" << std::endl;
                duplicate = true;
                break;
            } else if (SN > chain_table[index_][i]->get_SN()) {
                temp.push_back(new_student);
                saved_index = i;
                break;
            } else {
                temp.push_back(chain_table[index_][i]);
                if (i+1 == chain_table[index_].size() ) {
                    saved_index = i+1;
                    temp.push_back(new_student);
                }
            }
        }
        for (int i{saved_index}; i<chain_table[index_].size(); ++i) {
            temp.push_back(chain_table[index_][i]);
        }
    }

    if (!duplicate) {
        chain_table[index_] = temp;
        std::cout << "success" << std::endl;
    }
}

void h_chaining::find(unsigned int SN) {
    int index = hash_func(SN);
    bool found = false;
    if (chain_table[index].size() == 0) {
        std::cout << "not found" << std::endl;
    } else {
        for (int i{0}; i<chain_table[index].size(); ++i) {
            if (SN == chain_table[index][i]->get_SN()) {
                std::cout << "found " << chain_table[index][i]->get_LN() << " in " << index << std::endl;
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "not found" << std::endl;
        }
    }
}

void h_chaining::remove(unsigned int SN) {
    int index = hash_func(SN);
    bool found = false;
    std::vector<student*> temp;
    if (chain_table[index].size() == 0 || (chain_table[index].size() == 1 && (chain_table[index][0]->get_SN() != SN))) {
        std::cout << "failure" << std::endl;
    } else {
        for(int i{0}; i<chain_table[index].size(); ++i) {
            if(chain_table[index][i]->get_SN() != SN) {
                temp.push_back(chain_table[index][i]);
            } else {
                found = true;
            }
        }
    }
    if (found) {
        chain_table[index] = temp;
        std::cout << "success" << std::endl;
    } else{
        std::cout << "failure" << std::endl;
    }
}

void h_chaining::print(int index) {
    if (chain_table[index].size() == 0){
        std::cout << "chain is empty" << std::endl;
    } else {
        int size_of_vector = chain_table[index].size();
        for (int i{0}; i<size_of_vector; ++i) {
            std::cout << chain_table[index][i]->get_SN() << " ";
        }
        std::cout << std::endl;
    }
}
