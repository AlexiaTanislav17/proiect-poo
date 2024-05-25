#include "group.h"


Group::Group(int c, string t, string np, string pp): codUnic(c), title(std::move(t)), numeProfesor(std::move(np)), prenumeProfesor(std::move(pp)), nrStudenti(0) {}

Group::Group(const int &c, string t, string np, string pp, const list<Student> &ss, const list<Post*> &p):
        codUnic(c), title(std::move(t)), numeProfesor(std::move(np)), prenumeProfesor(std::move(pp)), studentiGrupa(ss), posts(p), nrStudenti(0) {}

Group::Group(const Group &g): codUnic(g.codUnic), title(g.title), numeProfesor(g.numeProfesor), prenumeProfesor(g.prenumeProfesor), nrStudenti(g.nrStudenti) {}

Group::~Group() {
    codUnic = 0;
    title.clear();
    numeProfesor.clear();
    prenumeProfesor.clear();
    nrStudenti = 0;
    studentiGrupa.clear();
    posts.clear();
}

//friend class Student;
//friend class Teacher;
//friend class Post;
//friend class Assignment;
//friend class Test;

void Group::setCodUnicGrupa(int c) { codUnic = c; }
int Group::getCodUnicGrupa() const{ return codUnic; }
void Group::setTitleGroup(string t) { title = std::move(t); }
string Group::getTitleGroup() { return title; }
void Group::setNumeProfesorGroup(string np) { numeProfesor = std::move(np); }
string Group::getNumeProfesorGroup() { return numeProfesor; }
void Group::setPrenumeProfesorGroup(string pp) { prenumeProfesor = std::move(pp); }
string Group::getPrenumeProfesorGroup() { return prenumeProfesor; }
//int Group::getNrStudenti() const{ return nrStudenti;}
list<Post *> Group::getPosts() { return posts; }
void Group::intratInGrupa(){ nrStudenti++; }
void Group::iesitDinGrupa(){
    if (nrStudenti>0){
        nrStudenti--;
    }
}

void Group::adaugarePostare(Post* post) {
    posts.push_back(post);
}

void Group::stergerePostare(Post* post) {
    posts.remove(post);
}

std::istream& operator>>(istream& in, Group& grupa){
    cout << "Titlu: ";
    in >>  grupa.title;
    cout << "Cod: ";
    in >> grupa.codUnic;
    return in;
}

std::ostream& operator<<(ostream& out, const Group& grupa){
    out << "Clasa: " << grupa.title << endl;
    out << "Profesorul: " << grupa.numeProfesor << " " << grupa.prenumeProfesor << endl;
    out << "Codul: " << grupa.codUnic << endl;
    out << "Nr elevi inscrisi: " << grupa.nrStudenti << endl;
    for (Post* p: grupa.posts) {
        p->afisare();
    }
    return out;
}

Group& Group::operator=(const Group& grupa) {
    if (this != &grupa) {
        this->title = grupa.title;
        this->numeProfesor = grupa.numeProfesor;
        this->prenumeProfesor = grupa.prenumeProfesor;
        this->codUnic = grupa.codUnic;
        this->nrStudenti = grupa.nrStudenti;
        this->studentiGrupa = grupa.studentiGrupa;
        this->posts = grupa.posts;
    }
    return *this;
}

void Group::operator+=(Student& student){
    this->studentiGrupa.push_back(student);
}

void Group::operator-=(const Student& student) {
    this->studentiGrupa.remove(student);
}