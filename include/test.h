
#ifndef OOP_TEST_H
#define OOP_TEST_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include "post.h"
#include "teacher.h"

class Test: public Post {
private:
    string file;
    string dueTime;
    int grade;

public:
    Test(const string& t, const string& d, const string& nu,  const string& pu, string f, string dt): Post(t, d, nu, pu) , file(std::move(f)), dueTime(std::move(dt)), grade(0){}

    Test(const Test &t): Post(t), file(t.file), dueTime(t.dueTime), grade(t.grade) {}

    ~Test() {
        titlu.clear();
        descriere.clear();
        numeUser.clear();
        prenumeUser.clear();
        file.clear();
        dueTime.clear();
        grade = 0;
    }

    friend class Teacher;

    void citire(Teacher& t) override {
        setNumeUser(t.getNumeTeacher());
        setPrenumeUser(t.getPrenumeTeacher());
        cout << "Titlul postarii: " << titlu << endl;
        cout << "Descriere postare: " << descriere << endl;
        cout << "Ataseaza te rog fisierul (scrie numele lui):" << file << endl;
        cout << "Pana la ce ora pot studenti sa trimita rezolvarile testelor?" << dueTime << endl;   //cred ca ar trb sa fac cumva un vector de teme postate in cls asta
        cout << "Care e maximul de puncte pe care il pot primi studentii pe acesta tema?" << grade << endl;
    }

    void afisare() override {
        cout << numeUser << " ";
        cout << prenumeUser << endl;
        cout << titlu << endl;
        cout << descriere << endl;
        cout << file << endl;
        cout << dueTime << endl;
        cout << grade << endl;
    }

    Test& operator=(const Test& a) {
        if (this == &a) {
            return *this;
        }
        this->titlu = a.titlu;
        this->numeUser = a.numeUser;
        this->prenumeUser = a.prenumeUser;
        this->file = a.file;
        this->descriere = a.descriere;
        this->dueTime = a.dueTime;
        this->grade = a.grade;
        return *this;
    }

};

#endif //OOP_TEST_H
