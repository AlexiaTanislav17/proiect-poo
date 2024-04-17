
#ifndef OOP_GROUP_H
#define OOP_GROUP_H

#include <iostream>
#include <string>
#include <list>
#include <utility>

using namespace std;


class Group{
private:
    int codUnic;
    string title;
    string numeProfesor;
    string prenumeProfesor;
    list<Student> studentiGrupa;
    int nrStudenti;
public:

    Group(int c, string t, string np, string pp): codUnic(c), title(std::move(t)), numeProfesor(std::move(np)), prenumeProfesor(std::move(pp)), nrStudenti(0) {}

    Group(const int &c, string t, string np, string pp, const list<Student> &ss):
            codUnic(c), title(std::move(t)), numeProfesor(std::move(np)), prenumeProfesor(std::move(pp)), studentiGrupa(ss), nrStudenti(0){}

    Group(const Group &g): codUnic(g.codUnic), title(g.title), numeProfesor(g.numeProfesor), prenumeProfesor(g.prenumeProfesor), nrStudenti(g.nrStudenti) {}

    ~Group() {
        codUnic = 0;
        title.clear();
        numeProfesor.clear();
        prenumeProfesor.clear();
        nrStudenti = 0;
        studentiGrupa.clear();
    }

    friend class Student;
    friend class Teacher;

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
