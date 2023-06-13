#include <iostream>
#include "student.h"

student::student(unsigned int new_SN, std::string new_LN) {
    SN = new_SN;
    lastname = new_LN;
    got_deleted = false;
}
student::student() {
    SN = 0;
    lastname = "";
    got_deleted = false;
}
unsigned int student::get_SN() {
    return SN;
}
std::string student::get_LN() {
    return lastname;
}
void student::swap_deletion() {
    got_deleted = true;
}
bool student::deleted() {
    return got_deleted;
}
