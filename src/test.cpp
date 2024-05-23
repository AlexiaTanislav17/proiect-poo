#include "test.h"

Test::Test(const string& t, const string& d, const string& nu,  const string& pu, string f, string dt): Post(t, d, nu, pu) , file(std::move(f)), dueTime(std::move(dt)), grade(0){}

Test::Test(const Test &t): Post(t), file(t.file), dueTime(t.dueTime), grade(t.grade) {}

Test::~Test() {
    titlu.clear();
    descriere.clear();
    numeUser.clear();
    prenumeUser.clear();
    file.clear();
    dueTime.clear();
    grade = 0;
}

//friend class Teacher;


//    void Test::setFile(string f) { file = std::move(f); }
//    string Test::getFile() { return file; }
//    void Test::setGrade(int g) { grade = g; }
//    int Test::getGrade() const { return grade; }
void Test::setDueTime(string dt) { dueTime = std::move(dt); }
//    string Test::getDueTime() { return dueTime; }

void Test::citire(Teacher& t) {
    setNumeUser(t.getNumeTeacher());
    setPrenumeUser(t.getPrenumeTeacher());
    cout << "Titlul postarii: ";
    cin >> titlu;
    cout << endl;
    cout << "Descriere postare: ";
    cin >> descriere;
    cout << endl;
    cout << "Ataseaza te rog fisierul (scrie numele lui):";
    cin >> file;
    cout << endl;
    cout << "Pana la ce ora pot studenti sa trimita rezolvarile testelor?";   //cred ca ar trb sa fac cumva un vector de teme postate in cls asta
    cin >> dueTime;
    cout << endl;
    cout << "Care e maximul de puncte pe care il pot primi studentii pe acest test?";
    cin >> grade;
    cout << endl;
}

void Test::afisare() {
    cout << "Profesor: " << numeUser << " ";
    cout << prenumeUser << endl;
    cout << "Titlu:" << titlu << endl;
    cout << "Descriere: " << descriere << endl;
    cout << file << endl;
    cout << "Due date: " << dueTime << endl;
    cout << "Nota: 0/" << grade << endl;
}

Test& Test::operator=(const Test& a) {
    if (this == &a) {
        return *this;
    }
    this->titlu = a.titlu;
    this->numeUser = a.numeUser;
    this->prenumeUser = a.prenumeUser;
    this->file = a.file;
    this->descriere = a.descriere;
    this->dueTime = a.dueTime;
    this->grade = a.grade;
    return *this;
}