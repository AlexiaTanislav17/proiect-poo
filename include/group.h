
#ifndef OOP_GROUP_H
#define OOP_GROUP_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include "post.h"
#include "assignment.h"
#include "test.h"

using namespace std;


class Group{
private:
    int codUnic;
    string title;
    string numeProfesor;
    string prenumeProfesor;
    list<Student> studentiGrupa;
    list<Post*> posts;
    int nrStudenti;
public:

    Group(int c, string t, string np, string pp): codUnic(c), title(std::move(t)), numeProfesor(std::move(np)), prenumeProfesor(std::move(pp)), nrStudenti(0) {}

    Group(const int &c, string t, string np, string pp, const list<Student> &ss, const list<Post*> &p):
            codUnic(c), title(std::move(t)), numeProfesor(std::move(np)), prenumeProfesor(std::move(pp)), studentiGrupa(ss), posts(p), nrStudenti(0){}

    Group(const Group &g): codUnic(g.codUnic), title(g.title), numeProfesor(g.numeProfesor), prenumeProfesor(g.prenumeProfesor), nrStudenti(g.nrStudenti) {}

    ~Group() {
        codUnic = 0;
        title.clear();
        numeProfesor.clear();
        prenumeProfesor.clear();
        nrStudenti = 0;
        studentiGrupa.clear();
        posts.clear();
    }

    friend class Student;
    friend class Teacher;
    friend class Post;
    friend class Assignment;
    friend class Test;

    void setCodUnicGrupa(int c) { codUnic = c; }
    int getCodUnicGrupa() const{ return codUnic; }
    void setTitleGroup(string t) { title = std::move(t); }
    string getTitleGroup() { return title; }
    void setNumeProfesorGroup(string np) { numeProfesor = std::move(np); }
    string getNumeProfesorGroup() { return numeProfesor; }
    void setPrenumeProfesorGroup(string pp) { prenumeProfesor = std::move(pp); }
    string getPrenumeProfesorGroup() { return prenumeProfesor; }
    void intratInGrupa(){ nrStudenti++; }
    void iesitDinGrupa(){
        if (nrStudenti>0){
            nrStudenti--;
        }
    }

    void adaugarePostare(Post* post) {
        //ar trb si efectiv sa adaug/introduc datele postarii cred
        //gen de creare postare
        posts.push_back(post);
    }

    void stergerePostare(Post* post) {
        //trb sa fac cv cod cred sa pot sa identific postarea pe care sa o sterg
        posts.remove(post);
    }

    friend istream& operator>>(istream& in, Group& grupa){
        cout << "Titlu: ";
        in >>  grupa.title;
        cout << "Cod: ";
        in >> grupa.codUnic;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Group& grupa){
        out << "Clasa: " << grupa.title << endl;
        out << "Profesorul: " << grupa.numeProfesor << " " << grupa.prenumeProfesor << endl;
        out << "Codul: " << grupa.codUnic << endl;
        out << "Nr elevi inscrisi: " << grupa.nrStudenti << endl;
        for (Post* p: grupa.posts) {
            p->afisare();
        }
        return out;
    }

    Group& operator=(const Group& grupa) {    //am pus const ca sa nu mai dea warning, sa asigur ca nu si schimba parametrul random
        if (this == &grupa) {
            return *this;
        }
        this->title = grupa.title;
        this->numeProfesor = grupa.numeProfesor;
        this->prenumeProfesor = grupa.prenumeProfesor;
        this->codUnic = grupa.codUnic;
        this->nrStudenti = grupa.nrStudenti;
        this->studentiGrupa = grupa.studentiGrupa;
        this->posts = grupa.posts;
        return *this;
    }

    void operator+=(Student& student){
        this->studentiGrupa.push_back(student);
    }

    void operator-=(const Student& student) {
        this->studentiGrupa.remove(student);
    }
};

#endif //OOP_GROUP_H
