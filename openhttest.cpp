#include <iostream>
#include "hash_double.h"

int main() {

    std::string command = "", lastName;
    unsigned int studentNumber;
    int max_size;
    std::cin >> command >> max_size;
    h_double ht(max_size);
    command = "";
    while(std::cin >> command) {

        if (command == "i") {
            std::cin >> studentNumber >> lastName;
            ht.add(studentNumber, lastName);
        } else if (command == "s") {
            std::cin >> studentNumber;
            ht.find(studentNumber);
        } else if (command == "d") {
            std::cin >> studentNumber;
            ht.remove(studentNumber); 
        } 
    }
    return 0;
}