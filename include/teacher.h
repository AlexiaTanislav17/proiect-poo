//
// Created by Alexia on 16.04.2024.
//

//#ifndef OOP_TEACHER_H
//#define OOP_TEACHER_H

#include <iostream>
#include <string>
#include <list>
#include <utility>

using namespace std;

class Teacher{
private:
    string nume;
    string prenume;
    string email;
    // list<Group> grupe;
public:

    explicit Teacher(std::string  n=" ", std::string p=" ", std::string e=" "): nume(std::move(n)), prenume(std::move(p)), email(std::move(e)) {}

    ~Teacher() {
        nume.clear();
        prenume.clear();
        email.clear();
    }

    //friend class Group;

    void setNumeTeacher(string n) { nume = std::move(n); }
    string getNumeTeacher() { return nume; }
    void setPrenumeTeacher(string p) { prenume = std::move(p); }
    string getPrenumeTeacher() { return prenume; }
    void setEmailTeacher(string e) { email = std::move(e); }
//    string getEmailTeacher() { return email; }

};

//#endif //OOP_TEACHER_H
