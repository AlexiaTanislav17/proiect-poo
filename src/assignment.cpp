#include "assignment.h"


Assignment::Assignment(const string& t, const string& d, const string& nu,  const string& pu, string f, string dd): Post(t, d, nu, pu) , file(std::move(f)), dueDate(std::move(dd)), grade(0){}

Assignment::Assignment(const Assignment &a): Post(a), file(a.file), dueDate(a.dueDate), grade(a.grade) {}

Assignment::~Assignment() {
    titlu.clear();
    descriere.clear();
    numeUser.clear();
    prenumeUser.clear();
    file.clear();
    dueDate.clear();
    grade = 0;
}

//friend class Teacher;

//void Assignment::setFile(string f) { file = std::move(f); }
//string Assignment::getFile() { return file; }
//void Assignment::setGrade(int g) { grade = g; }
//int Assignment::getGrade() const { return grade; }
void Assignment::setDueDate(string dd) { dueDate = std::move(dd); }
//string Assignment::getDueDate() { return dueDate; }

void Assignment::citire(Teacher& t) {
    setNumeUser(t.getNumeTeacher());
    setPrenumeUser(t.getPrenumeTeacher());
    cout << "Titlul postarii: ";
    cin >> titlu;
    cout << endl;
    cout << "Descriere postare: ";
    //la descriere trb sa fac cumva sa pot sa intoduc propozitii ca altfel e horror
    cin >> descriere;
    cout << endl;
    cout << "Ataseaza te rog fisierul (scrie numele lui):";
    cin >> file;
    cout << endl;
    cout << "Pana cand pot studenti sa trimita temele?";   //cred ca ar trb sa fac cumva un vector de teme postate in cls asta
    cin >> dueDate;
    cout << endl;
    cout << "Care e maximul de puncte pe care il pot primi studentii pe acesta tema?";
    cin >> grade;
    cout << endl;
}

void Assignment::afisare() {
    cout << "Profesor: " << numeUser << " ";
    cout << prenumeUser << endl;
    cout << "Titlu:" << titlu << endl;
    cout << "Descriere: " << descriere << endl;
    cout << file << endl;
    cout << "Due date: " << dueDate << endl;
    cout << "Nota: 0/" << grade << endl;
}

Assignment& Assignment::operator=(const Assignment& a) {
    if (this == &a) {
        return *this;
    }
    this->titlu = a.titlu;
    this->numeUser = a.numeUser;
    this->prenumeUser = a.prenumeUser;
    this->file = a.file;
    this->descriere = a.descriere;
    this->dueDate = a.dueDate;
    this->grade = a.grade;
    return *this;
}