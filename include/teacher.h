
#ifndef OOP_TEACHER_H
#define OOP_TEACHER_H

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
    static int totalGroups;
public:

    explicit Teacher(std::string  n=" ", std::string p=" ", std::string e=" ");

    ~Teacher();

    //friend class Group;

    void setNumeTeacher(string n);
    string getNumeTeacher();
    void setPrenumeTeacher(string p);
    string getPrenumeTeacher();
    void setEmailTeacher(string e);
    string getEmailTeacher();
    static int getTotalGroups();
    static void incrementTotalGroups();
    static void decrementTotalGroups();
    void afTotalGroups();

};

#endif //OOP_TEACHER_H
