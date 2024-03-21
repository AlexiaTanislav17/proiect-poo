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


    void setNumeStudent(string nume) { this->nume = nume; }
    string getNumeStudent() { return nume; }
    void setPrenumeStudent(string prenume) { this->prenume = prenume; }
    string getPrenumeStudent() { return prenume; }
    void setEmailStudent(string email) { this->email = email; }
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


    void setNumeTeacher(string nume) { this->nume = nume; }
    string getNumeTeacher() { return nume; }
    void setPrenumeTeacher(string prenume) { this->prenume = prenume; }
    string getPrenumeTeacher() { return prenume; }
    void setEmailTeacher(string email) { this->email = email; }
    string getEmailTeacher() { return email; }

};



int main() {

    string tipCont, Nume, Prenume, Email;

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
        } else {
            cout << "Se pare ca nu ai introdus datele corect, te rog mai incearca o data!" << endl;
        }
    }


    return 0;
}
