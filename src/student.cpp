#include "student.h"


Student::Student(string n, string p, string e): nume(std::move(n)), prenume(std::move(p)), email(std::move(e)) {}

Student::~Student() {
    nume.clear();
    prenume.clear();
    email.clear();
}

void Student::setNumeStudent(string n) { nume = std::move(n); }
//string Student::getNumeStudent() { return nume; }
void Student::setPrenumeStudent(string p) { prenume = std::move(p); }
//string Student::getPrenumeStudent() { return prenume; }
void Student::setEmailStudent(string e) { email = std::move(e); }
//string Student::getEmailStudent() { return email; }

std::ostream& operator<<(ostream& out, const Student& student){
    out << "Nume si Prenume: " << student.nume << " " << student.prenume << endl;
    out << "Email: " << student.email << endl;
    return out;
}

bool operator==(const Student& student1, const Student& student2) {
    if (student1.nume == student2.nume && student1.prenume == student2.prenume && student1.email == student2.email){
        return true;
    }
    return false;
}
