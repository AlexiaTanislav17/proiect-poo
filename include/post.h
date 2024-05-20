
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

    Post(string t = "", string d = "", string nu = "", string pu = "");

    Post(const Post &p);

    virtual ~Post();

    void setTitlu(string t);
    string getTitlu();
    void setDescriere(string d);
    string getDescriere();
    virtual void setNumeUser(string nu);
    string getNumeUser();
    virtual void setPrenumeUser(string pu);
    string getPrenumeUser();

    virtual void citire(Teacher& t) = 0;
    virtual void afisare() = 0;

    Post& operator=(const Post& p);

};


#endif //OOP_POST_H
