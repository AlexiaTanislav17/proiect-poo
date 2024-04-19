
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

    //constr cop si op =

    virtual ~Post() {
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


#endif //OOP_POST_H
