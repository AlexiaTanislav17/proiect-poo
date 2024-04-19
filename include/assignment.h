
#ifndef OOP_ASSIGNMENT_H
#define OOP_ASSIGNMENT_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include "post.h"
#include "teacher.h"


class Assignment: public Post {
private:
    string file;
    string dueDate;
    int grade;

public:
    Assignment(const string& t, const string& d, const string& nu,  const string& pu, string f, string dd): Post(t, d, nu, pu) , file(std::move(f)), dueDate(std::move(dd)), grade(0){}

    Assignment(const Assignment &a): Post(a), file(a.file), dueDate(a.dueDate), grade(a.grade) {}

    ~Assignment() {
        titlu.clear();
        descriere.clear();
        numeUser.clear();
        prenumeUser.clear();
        file.clear();
        dueDate.clear();
        grade = 0;
    }

    friend class Teacher;

    void citire(Teacher& t) override {
        setNumeUser(t.getNumeTeacher());
        setPrenumeUser(t.getPrenumeTeacher());
        cout << "Titlul postarii: " << titlu << endl;
        cout << "Descriere postare: " << descriere << endl;
        cout << "Ataseaza te rog fisierul (scrie numele lui):" << file << endl;
        cout << "Pana cand pot studenti sa trimita temele?" << dueDate << endl;   //cred ca ar trb sa fac cumva un vector de teme postate in cls asta
        cout << "Care e maximul de puncte pe care il pot primi studentii pe acesta tema?" << grade << endl;
    }

    void afisare() override {
        cout << numeUser << " ";
        cout << prenumeUser << endl;
        cout << titlu << endl;
        cout << descriere << endl;
        cout << file << endl;
        cout << dueDate << endl;
        cout << grade << endl;
    }

    Assignment& operator=(const Assignment& a) {
        if (this == &a) {
            return *this;
        }
        this->titlu = a.titlu;
        this->numeUser = a.numeUser;
        this->prenumeUser = a.prenumeUser;
        this->file = a.file;
        this->descriere = a.descriere;
        this->dueDate = a.dueDate;
        this->grade = a.grade;
        return *this;
    }

};

#endif //OOP_ASSIGNMENT_H
