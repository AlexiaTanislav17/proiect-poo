#include <iostream>
#include <string>
#include <list>
using namespace std;

// APLICATIE STIL GOOGLE CLASSROOM
// inca nu stiu ce fac exact aici ca s functionalitati


class Student{
private:
    string nume;
    string prenume;
    string email;
    //list<Group> grupe;
public:

    Student(string n=" ", string p=" ", string e=" ") {
        nume = n;
        prenume = p;
        email = e;
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

    Teacher(string n=" ", string p=" ", string e=" ") {
        nume = n;
        prenume = p;
        email = e;
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
//    void iesitDinGrupa(){
//        if (nrStudenti>0){
//            nrStudenti--;
//        }
//    }

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

void dateTeacher(Teacher t){
    t.setNumeTeacher("Marin");
    t.setPrenumeTeacher("Maricica");
    t.setEmailTeacher("m.m@gmail.com");
}

bool operator==(const Group& g1, const Group& g2) {
    if (g1.getCodUnicGrupa()== g2.getCodUnicGrupa()){
        return true;
    }
    return false;
}

int main() {

    string tipCont, Nume, Prenume, Email, r, Titlu;
    string titluGrupa, npGrupa, ppGrupa;
    int Cod;

    Teacher teacher1;
    teacher1.setNumeTeacher("Marin");
    teacher1.setPrenumeTeacher("Maricica");
    teacher1.setEmailTeacher("m.m@gmail.com");

    Teacher teacher2;
    teacher2.setNumeTeacher("Popescu");
    teacher2.setPrenumeTeacher("Stefan");
    teacher2.setEmailTeacher("p.s@gmail.com");

    Teacher teacher3;
    teacher3.setNumeTeacher("Ion");
    teacher3.setPrenumeTeacher("Cornela");
    teacher3.setEmailTeacher("i.c@gmail.com");

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

        cout << "Vrei sa intrii intr-o clasa? Y/N" << endl;
        cin >> r;
        if (r=="Y" || r=="y"){
            for (Group grupa : grupe){
                cout << grupa;
            }
            //ar trb sa am si un array in care sa arate in ce clase sunt doar ca nu merge ca
            //conteaza ordinea in care sunt definite clasele
            cout << "In ce clasa vrei sa te inscrii? Scrie codul acesteia!" << endl;
            cin >> Cod;
            for (Group grupa : grupe){
                if (grupa.getCodUnicGrupa() == Cod){
                    titluGrupa = grupa.getTitleGroup();
                    npGrupa = grupa.getNumeProfesorGroup();
                    ppGrupa = grupa.getPrenumeProfesorGroup();
                }
            }
            grupaTemporara.setNumeProfesorGroup(npGrupa);
            grupaTemporara.setPrenumeProfesorGroup(ppGrupa);
            grupaTemporara.setTitleGroup(titluGrupa);
            grupaTemporara.setCodUnicGrupa(Cod);
            grupe.remove(grupaTemporara);

            grupaTemporara += student;
            grupaTemporara.intratInGrupa();
            grupe.push_back(grupaTemporara);
            for (Group grupa : grupe){
                cout << grupa;
            }
        } else {
            cout << "Vrei sa iesi dintr-o clasa? Y/N" << endl;
            //aici ar trb defapt mai multe optiuni, sa iti afiseze optiuni
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
                Group grupa(0, " ", " ", " ");
                grupa.setNumeProfesorGroup(teacher.getNumeTeacher());
                grupa.setPrenumeProfesorGroup(teacher.getPrenumeTeacher());
                cin >> grupa;
                cout << grupa;

                //aici trb din nou sa intreb daca vrea sa mai creeze o clasa cred :')

            } else {
                cout << "Din pacate nu aveti ce sa faceti mai mult de atat, aplicatia e inca in progres. Va astept la urmatorul update!";
            }
        } else {
            cout << "Se pare ca nu ai introdus datele corect, te rog mai incearca o data!" << endl;
            // trb defapt sa o fac functie ca sa mearga dar vad eu asta cum
            // vreau ma intai sa mearga putin cate putin
        }
    }


    return 0;
}
