#include <iostream>
//acts as a node class
class student {
    private:
        unsigned int SN;
        std::string lastname;
        bool got_deleted;
    public:
        student(unsigned int new_SN, std::string new_LN);
        student();
        unsigned int get_SN();
        std::string get_LN();
        void swap_deletion();
        bool deleted();
};