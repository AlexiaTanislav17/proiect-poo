
#ifndef OOP_POST_H
#define OOP_POST_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include "teacher.h"

using namespace std;


class Post {
protected:
    string titlu;
    string descriere;
    string numeUser;
    string prenumeUser;

public:

    Post(string t, string d, string nu, string pu): titlu(std::move(t)), descriere(std::move(d)), numeUser(std::move(nu)), prenumeUser(std::move(pu)) {}

    ~Post() {
        titlu.clear();
        descriere.clear();
        numeUser.clear();
        prenumeUser.clear();
    }

//    void setTitlu(string t) { titlu = std::move(t); }
//    string getTitlu() { return titlu; }
//    void setDescriere(string d) { descriere = std::move(d); }
//    string getDescriere() { return descriere; }
    virtual void setNumeUser(string nu) { numeUser = std::move(nu); }
//    string getNumeuser() { return numeUser; }
    virtual void setPrenumeUser(string pu) { prenumeUser = std::move(pu); }
//    string getPrenumeUser() { return prenumeUser; }

    virtual void citire() =0;
    virtual void afisare() = 0;

};



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
        grade = 0;
    }

    friend class Teacher;

    void citire(Teacher& t) {
        setNumeUser(t.getNumeTeacher());
        setPrenumeUser(t.getPrenumeTeacher());
        cout << "Titlul postarii: " << titlu << endl;
        cout << "Descriere postare: " << descriere << endl;
        cout << "Ataseaza te rog fisierul (scrie numele lui):" << file << endl;
        cout << "Pana cand pot studenti sa trimita temele?" << dueDate << endl;   //cred ca ar trb sa fac cumva un vector de teme postate in cls asta
        cout << "Care e maximul de puncte pe care il pot primi studentii pe acesta tema?" << grade << endl;
    }

    void afisare() {
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

#endif //OOP_POST_H
