#include <iostream>
#include <vector>
#include "hash_double.h"

h_double::h_double(int size_) {
    double_size = size_;
    double_table = new std::vector<student>[size_];
    std::cout << "success" << std::endl;
    }

h_double::~h_double() {
    delete [] double_table;
    }
int h_double::hash_1(unsigned int key) {
    return key%double_size;
}
int h_double::hash_2(unsigned int key) {
    int result = (key/double_size)%double_size;
    if (result%2 == 0) {
        return (result + 1);
    }
    return result;
}
void h_double::add(unsigned int SN, std::string LN) {
    int h1 = hash_1(SN);
    int h2 = hash_2(SN);
    int collisions{0};
    bool duplicate = false;
    while ( (double_table[((h1 + collisions*h2)%double_size)].size() != 0) && (collisions < double_size)) {
        if (double_table[((h1 + collisions*h2)%double_size)][0].get_SN() == SN && !(double_table[((h1 + collisions*h2)%double_size)][0].deleted())) {
            duplicate = true;
            break;
        }
        if (double_table[((h1 + collisions*h2)%double_size)][0].deleted()) {
            break;
        } else {
        collisions++;
        }
    }
    if (!duplicate) {
        if (collisions == double_size) {
            std::cout << "failure" << std::endl;
        } else if (collisions < double_size) {
            student *new_entry = new student(SN, LN);
            if (double_table[((h1 + collisions*h2)%double_size)].size() == 0) {
                double_table[((h1 + collisions*h2)%double_size)].push_back(*new_entry);
                std::cout << "success" << std::endl;
            } else if (double_table[((h1 + collisions*h2)%double_size)][0].deleted()) {
                double_table[((h1 + collisions*h2)%double_size)][0] = *new_entry;
                std::cout << "success" << std::endl;
            }
        }
    } else if (duplicate) {
        std::cout << "failure" << std::endl;
    }
}

void h_double::find(unsigned int SN) {
    bool found = false;
    int h1 = hash_1(SN);
    int h2 = hash_2(SN);
    int collisions{0};
    int index = ((h1 + collisions*h2)%double_size);
    while (double_table[((h1 + collisions*h2)%double_size)].size() != 0 && collisions < double_size) {
        if (SN == double_table[((h1 + collisions*h2)%double_size)][0].get_SN() && !(double_table[((h1 + collisions*h2)%double_size)][0].deleted())) {
                found = true;
                break;
        } else {
        ++collisions; 
        }
    }
    if (!found) {
        std::cout << "not found" << std::endl;
    } else {
        std::cout << "found " << double_table[((h1 + collisions*h2)%double_size)][0].get_LN() << " in " << (h1 + collisions*h2)%double_size << std::endl;
    }
}

void h_double::remove(unsigned int SN) {
    bool found = false;
    int h1 = hash_1(SN);
    int h2 = hash_2(SN);
    int collisions{0};
    int index = ((h1 + collisions*h2)%double_size);
    while (double_table[((h1 + collisions*h2)%double_size)].size() != 0 && collisions < double_size) {
        if (SN == double_table[((h1 + collisions*h2)%double_size)][0].get_SN() && !(double_table[((h1 + collisions*h2)%double_size)][0].deleted())) {
                found = true;
                break;
        } else {
        ++collisions; 
        }
    }
    if (!found) {
        std::cout << "failure" << std::endl;
    } else {
        double_table[((h1 + collisions*h2)%double_size)][0].swap_deletion();
        std::cout << "success" << std::endl;
    }
}


/*
void h_double::test_printing() {
    for ( int i{0}; i<double_size; ++i) {
        if (double_table[i].size() != 0)
            if(double_table[i][0].deleted() == false)
            std::cout << double_table[i][0].get_SN() << " at index "<< i << std::endl; 
    }
}
*/