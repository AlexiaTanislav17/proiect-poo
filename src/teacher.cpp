#include "teacher.h"


Teacher::Teacher(std::string  n, std::string p, std::string e): nume(std::move(n)), prenume(std::move(p)), email(std::move(e)) { totalGroups = 0; }

Teacher::~Teacher() {
    nume.clear();
    prenume.clear();
    email.clear();
    totalGroups = 0;
}

void Teacher::setNumeTeacher(string n) { nume = std::move(n); }
string Teacher::getNumeTeacher() { return nume; }
void Teacher::setPrenumeTeacher(string p) { prenume = std::move(p); }
string Teacher::getPrenumeTeacher() { return prenume; }
void Teacher::setEmailTeacher(string e) { email = std::move(e); }
string Teacher::getEmailTeacher() { return email; }

int Teacher::getTotalGroups() { return totalGroups; }      //static
void Teacher::incrementTotalGroups() { totalGroups++; }   //static
void Teacher::decrementTotalGroups() {                   //static
    if (totalGroups > 0) {
        totalGroups--;
    }
}
void Teacher::afTotalGroups()
{
    cout << "Nr total de grupe create de tine: " << Teacher::totalGroups << endl;
}
