#include "post.h"
//#include "assignment.h"
//#include "test.h"


Post::Post(string t, string d, string nu, string pu): titlu(std::move(t)), descriere(std::move(d)), numeUser(std::move(nu)), prenumeUser(std::move(pu)) {}

Post::Post(const Post &p): titlu(p.titlu), descriere(p.descriere), numeUser(p.numeUser), prenumeUser(p.prenumeUser) {}

Post::~Post() {                    //virtual
    titlu.clear();
    descriere.clear();
    numeUser.clear();
    prenumeUser.clear();
}

void Post::setTitlu(string t) { titlu = std::move(t); }
string Post::getTitlu() { return titlu; }
void Post::setDescriere(string d) { descriere = std::move(d); }
string Post::getDescriere() { return descriere; }
void Post::setNumeUser(string nu) { numeUser = std::move(nu); }            //virtual
string Post::getNumeUser() { return numeUser; }
void Post::setPrenumeUser(string pu) { prenumeUser = std::move(pu); }     //virtual
string Post::getPrenumeUser() { return prenumeUser; }

void Post::citire(Teacher& t) {};          //virtual
void Post::afisare() {};                  //virtual

Post&Post:: operator=(const Post& p) {
    if (this == &p) {
        return *this;
    }
    this->titlu = p.titlu;
    this->numeUser = p.numeUser;
    this->prenumeUser = p.prenumeUser;
    this->descriere = p.descriere;
    return *this;
}