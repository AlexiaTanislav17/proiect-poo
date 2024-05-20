#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H

#include <iostream>
#include <string>
#include <list>
#include <utility>

using namespace std;

class Student{
private:
    string nume;
    string prenume;
    string email;
    //list<Group> grupe;
public:

    explicit Student(string n=" ", string p=" ", string e=" ");

    ~Student();

    //friend class Group;

    void setNumeStudent(string n);
    string getNumeStudent();
    void setPrenumeStudent(string p);
    string getPrenumeStudent();
    void setEmailStudent(string e);
    string getEmailStudent();

    friend ostream& operator<<(ostream& out, const Student& student);
    friend bool operator==(const Student& student1, const Student& student2);

};

#endif //OOP_STUDENT_H
