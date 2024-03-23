#include <iostream>
#include <string>
#include <list>
using namespace std;


class Student{
private:
    string nume;
    string prenume;
    string email;
    //list<Group> grupe;
public:

    Student(string nume=" ", string prenume=" ", string email=" ") {
        this->nume = nume;
        this->prenume = prenume;
        this->email = email;
    }

    ~Student() {
        nume.clear();
        prenume.clear();
        email.clear();
    }

    //friend class Group;

    void setNumeStudent(string n) { nume = n; }
//    string getNumeStudent() { return nume; }
    void setPrenumeStudent(string p) { prenume = p; }
//    string getPrenumeStudent() { return prenume; }
    void setEmailStudent(string e) { email = e; }
//    string getEmailStudent() { return email; }

    friend ostream& operator<<(ostream& out, Student& student){
        out << "Nume si Prenume: " << student.nume << " " << student.prenume << endl;
        out << "Email: " << student.email << endl;
        return out;
    }

    bool operator==(const Student& student){
        if (nume == student.nume && prenume == student.prenume && email == student.email){
            return true;
        }
        return false;
    }

};


class Teacher{
private:
    string nume;
    string prenume;
    string email;
    // list<Group> grupe;
public:

    Teacher(string nume=" ", string prenume=" ", string email=" ") {
        this->nume = nume;
        this->prenume = prenume;
        this->email = email;
    }

    ~Teacher() {
        nume.clear();
        prenume.clear();
        email.clear();
    }

    //friend class Group;

    void setNumeTeacher(string n) { nume = n; }
    string getNumeTeacher() { return nume; }
    void setPrenumeTeacher(string p) { prenume = p; }
    string getPrenumeTeacher() { return prenume; }
    void setEmailTeacher(string e) { email = e; }
//    string getEmailTeacher() { return email; }

};


class Group{
private:
    int codUnic;
    string title;
    string numeProfesor;
    string prenumeProfesor;
    list<Student> studentiGrupa;
    int nrStudenti;
public:

    Group(int c, string t, string np, string pp) {
        codUnic = c;
        title = t;
        numeProfesor = np;
        prenumeProfesor = pp;
        nrStudenti = 0;
    }

    Group(int &c, string &t, string &np, string &pp, list<Student> &ss) {
        codUnic = c;
        title = t;
        numeProfesor = np;
        prenumeProfesor = pp;
        nrStudenti = 0;
        studentiGrupa = ss;
    }

    Group(const Group &g){
        codUnic = g.codUnic;
        title = g.title;
        numeProfesor = g.numeProfesor;
        prenumeProfesor = g.prenumeProfesor;
        nrStudenti = g.nrStudenti;
    }

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
    void setTitleGroup(string t) { title = t; }
    string getTitleGroup() { return title; }
    void setNumeProfesorGroup(string np) { numeProfesor = np; }
    string getNumeProfesorGroup() { return numeProfesor; }
    void setPrenumeProfesorGroup(string pp) { prenumeProfesor = pp; }
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

    friend ostream& operator<<(ostream& out, Group& grupa){
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

    void operator-=(Student& student) {
        this->studentiGrupa.remove(student);
    }
};


void dateTeacher(Teacher t, string n, string p, string e){
    t.setNumeTeacher(n);
    t.setPrenumeTeacher(p);
    t.setEmailTeacher(e);
}

bool operator==(const Group& g1, const Group& g2) {
    if (g1.getCodUnicGrupa()== g2.getCodUnicGrupa()){
        return true;
    }
    return false;
}

void deleteGroup(Teacher teacher, list<Group> grupe);

void createGroup(Teacher teacher, list<Group> grupe) {
    string rp;
    Group grupa(0, " ", " ", " ");
    grupa.setNumeProfesorGroup(teacher.getNumeTeacher());
    grupa.setPrenumeProfesorGroup(teacher.getPrenumeTeacher());
    cin >> grupa;
    grupe.push_back(grupa);
    for (Group g : grupe){
        cout << g;
    }
    cout << endl;
    cout << "Apasa C pt a creea o clasa, D daca vrei sa stergi una sau orice altceva ca sa iesi!" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe);
    } else {
        if (rp == "D" || rp == "d"){
            deleteGroup(teacher, grupe);
        } else {
            cout << "Ai iesit!";
        }
    }
}

void deleteGroup(Teacher teacher, list<Group> grupe){
    int c;
    string titluGrupa, npGrupa,  ppGrupa;
    cout << "Introdu codul clasei pe care vrei sa o stergi: " << endl;
    cin >> c;
    for (Group g : grupe){
        if (c == g.getCodUnicGrupa()){
            titluGrupa = g.getTitleGroup();
            npGrupa = g.getNumeProfesorGroup();
            ppGrupa = g.getPrenumeProfesorGroup();
        }
    }
    Group gt(0, " "," ", " ");
    gt.setNumeProfesorGroup(npGrupa);
    gt.setPrenumeProfesorGroup(ppGrupa);
    gt.setTitleGroup(titluGrupa);
    gt.setCodUnicGrupa(c);
    grupe.remove(gt);
    for (Group g : grupe){
        cout << g;
    }
    string rp;
    cout << "Apasa C pt a creea o clasa, D daca vrei sa stergi una sau orice altceva ca sa iesi!" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe);
    } else {
        if (rp == "D" || rp == "d"){
            deleteGroup(teacher, grupe);
        } else {
            cout << "Ai iesit!";
        }
    }
}

void exitGroup(Student student, list<Group> grupe);

void enterGroup(Student student, list<Group> grupe) {
    int c;
    string rp, titluGrupa, npGrupa, ppGrupa;
    Group gt(0, " ", " ", "");
    for (Group grupa : grupe){
        cout << grupa;
    }
    cout << "In ce clasa vrei sa te inscrii? Scrie codul acesteia!" << endl;
    cin >> c;
    for (Group grupa : grupe){
        if (grupa.getCodUnicGrupa() == c){
            titluGrupa = grupa.getTitleGroup();
            npGrupa = grupa.getNumeProfesorGroup();
            ppGrupa = grupa.getPrenumeProfesorGroup();
        }
    }
    gt.setNumeProfesorGroup(npGrupa);
    gt.setPrenumeProfesorGroup(ppGrupa);
    gt.setTitleGroup(titluGrupa);
    gt.setCodUnicGrupa(c);
    grupe.remove(gt);

    gt += student;
    gt.intratInGrupa();
    grupe.push_back(gt);
    for (Group grupa : grupe){
        cout << grupa;
    }
    cout << endl;
    cout << "Apasa I pt a intra intr-o clasa, E daca vrei sa iesi din una sau orice altceva ca sa iesi!" << endl;
    cin >> rp;
    if (rp == "I" || rp=="i") {
        enterGroup(student, grupe);
    } else {
        if (rp == "E" || rp == "e"){
            exitGroup(student, grupe);
        } else {
            cout << "Ai iesit!";
        }
    }
}

void exitGroup(Student student, list<Group> grupe) {
    int c;
    string rp, titluGrupa, npGrupa, ppGrupa;
    Group gt(0, " ", " ", "");
    for (Group grupa : grupe){
        cout << grupa;
    }
    cout << "Din ce clasa vrei sa iesi? Scrie codul acesteia!" << endl;
    cin >> c;
    for (Group grupa : grupe){
        if (grupa.getCodUnicGrupa() == c){
            titluGrupa = grupa.getTitleGroup();
            npGrupa = grupa.getNumeProfesorGroup();
            ppGrupa = grupa.getPrenumeProfesorGroup();
        }
    }
    gt.setNumeProfesorGroup(npGrupa);
    gt.setPrenumeProfesorGroup(ppGrupa);
    gt.setTitleGroup(titluGrupa);
    gt.setCodUnicGrupa(c);
    grupe.remove(gt);

    gt -= student;
    gt.iesitDinGrupa();
    grupe.push_back(gt);

    for (Group grupa : grupe){
        cout << grupa;
    }
    cout << endl;
    cout << "Apasa I pt a intra intr-o clasa, E daca vrei sa iesi din una sau orice altceva ca sa iesi!" << endl;
    cin >> rp;
    if (rp == "I" || rp=="i") {
        enterGroup(student, grupe);
    } else {
        if (rp == "E" || rp == "e"){
            exitGroup(student, grupe);
        } else {
            cout << "Ai iesit!";
        }
    }
}

void menu() {
    string tipCont, Nume, Prenume, Email, r, Titlu;
    string titluGrupa, npGrupa, ppGrupa;

    Teacher teacher1;
    dateTeacher(teacher1, "Marin", "Maricica", "m.m@gmail.com");

    Teacher teacher2;
    dateTeacher(teacher2, "Popescu", "Stefan", "p.s@gmail.com");

    Teacher teacher3;
    dateTeacher(teacher3, "Ion", "Cornela", "i.c@gmail.com");

    Group grupa1(2345, "POO", "Marin", "Maricica");
    Group grupa2(3456, "Python", "Popescu", "Stefan");
    Group grupa3(4567, "C++", "Ion", "Cornela");
    Group grupaTemporara(0, " ", " ", " ");

    list<Group> grupe = {grupa1, grupa2, grupa3};

    cout << "Student sau profesor? Scrie S pt student sau P pt profesor" << endl;
    cin >> tipCont;
    if (tipCont=="S" || tipCont=="s"){
        cout << "Introdu numele: "<< endl;
        cin >> Nume;
        cout << "Introdu prenumele: "<< endl;
        cin >> Prenume;
        cout << "Introdu email-ul: "<< endl;
        cin >> Email;
        Student student;
        student.setNumeStudent(Nume);
        student.setPrenumeStudent(Prenume);
        student.setEmailStudent(Email);

        cout << "Vrei sa intrii intr-o clasa? Y/N (daca scrii nu sau altceva ati iesit)" << endl;
        cin >> r;
        if (r=="Y" || r=="y"){
            enterGroup(student, grupe);
        } else {
            cout << "Ai iesit!";
        }
    } else {
        if (tipCont=="P" || tipCont=="p"){
            cout << "Introdu numele: "<< endl;
            cin >> Nume;
            cout << "Introdu prenumele: " << endl;
            cin >> Prenume;
            cout << "Introdu email-ul: "<< endl;
            cin >> Email;
            Teacher teacher;
            teacher.setNumeTeacher(Nume);
            teacher.setPrenumeTeacher(Prenume);
            teacher.setEmailTeacher(Email);

            cout << "Vrei sa creezi o clasa? Y/N" << endl;
            cin >> r;
            if (r=="Y" || r=="y"){
                createGroup(teacher, grupe);
            } else {
                cout << "Din pacate nu aveti ce sa faceti mai mult de atat, aplicatia e inca in progres. Va astept la urmatorul update!";
            }
        } else {
            cout << "Se pare ca nu ai introdus datele corect, te rog mai incearca o data!" << endl;
            //menu(f);
        }
    }
}

int main() {

    while(true) {
        cout << endl;
        cout << "1 intra, 0 iese: " << endl;
        int x;
        cin >> x;
        if (x == 1){
            menu();
        } else {
            break;
        }
    }
    return 0;
}
