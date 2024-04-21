
#ifndef OOP_POST_H
#define OOP_POST_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include "teacher.h"

using namespace std;

// am creat o clasa de baza noua in loc sa derivez deja de la o clasa existenta deoarece asa codul ar fi avut mai multa logica
// si implementarea ar fi avut mai mult sens (si mai usor) decat daca derivam de exemplu GroupMath de la clasa de baza Group

class Post {
protected:
    string titlu;
    string descriere;
    string numeUser;
    string prenumeUser;

public:

    Post(string t = "", string d = "", string nu = "", string pu = ""): titlu(std::move(t)), descriere(std::move(d)), numeUser(std::move(nu)), prenumeUser(std::move(pu)) {}

    Post(const Post &p): titlu(p.titlu), descriere(p.descriere), numeUser(p.numeUser), prenumeUser(p.prenumeUser) {}

    virtual ~Post() {
        titlu.clear();
        descriere.clear();
        numeUser.clear();
        prenumeUser.clear();
    }

    void setTitlu(string t) { titlu = std::move(t); }
    string getTitlu() { return titlu; }
    void setDescriere(string d) { descriere = std::move(d); }
    string getDescriere() { return descriere; }
    virtual void setNumeUser(string nu) { numeUser = std::move(nu); }
    string getNumeUser() { return numeUser; }
    virtual void setPrenumeUser(string pu) { prenumeUser = std::move(pu); }
    string getPrenumeUser() { return prenumeUser; }

    virtual void citire(Teacher& t) =0;
    virtual void afisare() = 0;

    Post& operator=(const Post& p) {
        if (this == &p) {
            return *this;
        }
        this->titlu = p.titlu;
        this->numeUser = p.numeUser;
        this->prenumeUser = p.prenumeUser;
        this->descriere = p.descriere;
        return *this;
    }

};


#endif //OOP_POST_H
