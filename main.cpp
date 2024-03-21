#include <iostream>
#include <array>
#include <string>
using namespace std;

// APLICATIE STIL GOOGLE CLASSROOM
// inca nu stiu ce fac exact aici ca s functionalitati


class Student{
private:
    string nume;
    string prenume;
    string email;
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


    void setNumeStudent(string n) { nume = n; }
    string getNumeStudent() { return nume; }
    void setPrenumeStudent(string p) { prenume = p; }
    string getPrenumeStudent() { return prenume; }
    void setEmailStudent(string e) { email = e; }
    string getEmailStudent() { return email; }

};


class Teacher{
private:
    string nume;
    string prenume;
    string email;
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


    void setNumeTeacher(string n) { nume = n; }
    string getNumeTeacher() { return nume; }
    void setPrenumeTeacher(string p) { prenume = p; }
    string getPrenumeTeacher() { return prenume; }
    void setEmailTeacher(string e) { email = e; }
    string getEmailTeacher() { return email; }

};


class Group{
private:
    int codUnic;
    string title;
    string numeProfesor;
    string prenumeProfesor;
    array<string,100> studentiGrupa;
    int nrStudenti;
public:

    Group(int c, string t, string np, string pp) {
        codUnic = c;
        title = t;
        numeProfesor = np;
        prenumeProfesor = pp;
        nrStudenti = 0;
    }

    ~Group() {
        codUnic = 0;
        title.clear();
        numeProfesor.clear();
        prenumeProfesor.clear();
        nrStudenti = 0;
    }


    void setCodUnicGrupa(int c) { codUnic = c; }
    int getCodUnicGrupa() { return codUnic; }
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
//    void studentInscris(string n, string p){
//        //trebuie sa vad cum inscriu un student ca nu stiu cum
//    }

};


int main() {

    string tipCont, Nume, Prenume, Email, r, Titlu;
    int Cod;

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
            //trb sa afisez optiunile pt clase din array nu stiu care
            //si in functie de ce alegi trb sa introduci corect codul clasei
            //si sa fiu adaugat la nr de studenti idn cls
            //si ar trb sa am si un array in care sa arate in ce clase sunt
        } else {
            cout << "Vrei sa iesi dintr-o clasa? Y/N" << endl;
        }
    } else {
        if (tipCont=="P" || tipCont=="p"){
            cout << "Introdu numele: "<< endl;
            cin >> Nume;
            cout << "Introdu prenumele: "<< endl;
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
                Group grupa(0, "titlu", " ", " ");
                grupa.setNumeProfesorGroup(teacher.getNumeTeacher());
                grupa.setPrenumeProfesorGroup(teacher.getPrenumeTeacher());
                cout << "Introdu titlul clasei: "<< endl;
                cin >> Titlu;
                cout << "Introdu codul pt participanti: "<< endl;
                cin >> Cod;
                grupa.setCodUnicGrupa(Cod);
            }
        } else {
            cout << "Se pare ca nu ai introdus datele corect, te rog mai incearca o data!" << endl;
            // trb defapt sa o fac functie ca sa mearga dar vad eu asta cum
            // vreau ma intai sa mearga putin cate putin
        }
    }


    return 0;
}
