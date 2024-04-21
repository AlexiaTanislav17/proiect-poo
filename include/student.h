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

    explicit Student(string n=" ", string p=" ", string e=" "): nume(std::move(n)), prenume(std::move(p)), email(std::move(e)) {}

    ~Student() {
        nume.clear();
        prenume.clear();
        email.clear();
    }

    //friend class Group;

    void setNumeStudent(string n) { nume = std::move(n); }
    string getNumeStudent() { return nume; }
    void setPrenumeStudent(string p) { prenume = std::move(p); }
    string getPrenumeStudent() { return prenume; }
    void setEmailStudent(string e) { email = std::move(e); }
    string getEmailStudent() { return email; }

    friend ostream& operator<<(ostream& out, const Student& student){
        out << "Nume si Prenume: " << student.nume << " " << student.prenume << endl;
        out << "Email: " << student.email << endl;
        return out;
    }

    bool operator==(const Student& student) const{
        if (nume == student.nume && prenume == student.prenume && email == student.email){
            return true;
        }
        return false;
    }

};

#endif //OOP_STUDENT_H
