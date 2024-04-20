#include <iostream>
#include <string>
#include <list>
#include "student.h"
#include "teacher.h"
#include "group.h"
#include "post.h"
#include "assignment.h"

using namespace std;


bool operator==(const Group& g1, const Group& g2) {
    if (g1.getCodUnicGrupa()== g2.getCodUnicGrupa()){
        return true;
    }
    return false;
}

void createAssignment(Teacher& teacher, list<Group>& grupe);

void createTest(Teacher& teacher, list<Group>& grupe);

void deletePost(Teacher& teacher, list<Group>& grupe);

void deleteGroup(Teacher& teacher, list<Group> grupe);

void createGroup(Teacher& teacher, list<Group> grupe) {
    Group grupa(0, " ", " ", " ");
    grupa.setNumeProfesorGroup(teacher.getNumeTeacher());
    grupa.setPrenumeProfesorGroup(teacher.getPrenumeTeacher());
    cin >> grupa;
    grupe.push_back(grupa);
    for (Group& g : grupe){
        cout << g;
    }
    cout << endl;
    string rp;
    cout << endl;
    cout << "Apasa: " << "\n";
    cout << "C pt a creea o clasa" << "\n";
    cout << "D pt a sterge o clasa" << "\n";
    cout << "PA pt a creea o postare de tip assignment" << "\n";
    cout << "PT pt a crea o postare de tip test" << "\n";
    cout << "DP pt a sterge o postare" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe);
    } else {
        cout << "Ai iesit!";
    }
}

void deleteGroup(Teacher& teacher, list<Group> grupe){
    int c;
    string titluGrupa, npGrupa,  ppGrupa;
    cout << "Introdu codul clasei pe care vrei sa o stergi: " << endl;
    cin >> c;
    for (Group& g : grupe){
        if (c == g.getCodUnicGrupa()){
            titluGrupa = g.getTitleGroup();
            npGrupa = g.getNumeProfesorGroup();
            ppGrupa = g.getPrenumeProfesorGroup();
        }
    }
    if (npGrupa == teacher.getNumeTeacher() && ppGrupa == teacher.getPrenumeTeacher()){
        Group gt(0, " "," ", " ");
        gt.setNumeProfesorGroup(npGrupa);
        gt.setPrenumeProfesorGroup(ppGrupa);
        gt.setTitleGroup(titluGrupa);
        gt.setCodUnicGrupa(c);
        grupe.remove(gt);
        for (Group& g : grupe){
            cout << g;
        }
    } else {
        cout << endl;
        cout << "Nu ai autorizatie sa stergi aceasta clasa, nu esti profesor! Te rugam continua cu alta optiune." << endl;
    }
    string rp;
    cout << endl;
    cout << "Apasa: " << "\n";
    cout << "C pt a creea o clasa" << "\n";
    cout << "D pt a sterge o clasa" << "\n";
    cout << "PA pt a creea o postare de tip assignment" << "\n";
    cout << "PT pt a crea o postare de tip test" << "\n";
    cout << "DP pt a sterge o postare" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe);
    } else {
        cout << "Ai iesit!";
    }
}

void createAssignment(Teacher& teacher, list<Group>& grupe) {
    int c;
    int k = 0;
    Assignment a;
    Post *p = &a;
    p->citire(teacher);
    cout << "Introdu codul clasei careia vrei sa ii adaugi postarea: " << endl;
    cin >> c;
    for (Group& g : grupe){
        if (c == g.getCodUnicGrupa() && teacher.getNumeTeacher() == g.getNumeProfesorGroup() && g.getPrenumeProfesorGroup() == teacher.getPrenumeTeacher()){
            g.adaugarePostare(p);
            k = 1;
        }
    }
    for (Group& g : grupe){
        cout << g;
    }
    if (k != 1) {
        cout << "Nu ai autorizatie la aceasat clasa sau nu exista! Te rugam incearca alte optiuni" << endl;
    }
    string rp;
    cout << endl;
    cout << "Apasa: " << "\n";
    cout << "C pt a creea o clasa" << "\n";
    cout << "D pt a sterge o clasa" << "\n";
    cout << "PA pt a creea o postare de tip assignment" << "\n";
    cout << "PT pt a crea o postare de tip test" << "\n";
    cout << "DP pt a sterge o postare" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe);
    } else {
        cout << "Ai iesit!";
    }
}

void createTest(Teacher& teacher, list<Group>& grupe) {
    int c;
    int k = 0;
    Test t;
    Post *p = &t;
    p->citire(teacher);
    cout << "Introdu codul clasei careia vrei sa ii adaugi postarea: " << endl;
    cin >> c;
    for (Group& g : grupe){
        if (c == g.getCodUnicGrupa() && teacher.getNumeTeacher() == g.getNumeProfesorGroup() && g.getPrenumeProfesorGroup() == teacher.getPrenumeTeacher()){
            g.adaugarePostare(p);
            k = 1;
        }
    }
    for (Group& g : grupe){
        cout << g;
    }
    if (k != 1) {
        cout << "Nu ai autorizatie la aceasat clasa sau nu exista! Te rugam incearca alte optiuni" << endl;
    }
    string rp;
    cout << endl;
    cout << "Apasa: " << "\n";
    cout << "C pt a creea o clasa" << "\n";
    cout << "D pt a sterge o clasa" << "\n";
    cout << "PA pt a creea o postare de tip assignment" << "\n";
    cout << "PT pt a crea o postare de tip test" << "\n";
    cout << "DP pt a sterge o postare" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe);
    } else {
        cout << "Ai iesit!";
    }
}

void deletePost(Teacher& teacher, list<Group>& grupe) {
    int c;
    int k = 0;
    //Post p; //stiu ca e abstracta, let me cook
    cout << "Introdu codul clasei din care vrei sa stergi postarea: " << endl;
    cin >> c;
    for (Group& g : grupe){
        if (c == g.getCodUnicGrupa() && teacher.getNumeTeacher() == g.getNumeProfesorGroup() && g.getPrenumeProfesorGroup() == teacher.getPrenumeTeacher()){
            cout << "Introdu titlul postarii pe care vrei sa il stergi: " << endl;
            string titluPostare;
            cin >> titluPostare;
            for (auto post : g.getPosts()) {
                if (post->getTitlu() == titluPostare) {
                    k = 1;
                    g.stergerePostare(post);
                }
            }
        }
    }
    for (Group& g : grupe){
        cout << g;
    }
    if (k != 1) {
        cout << "Nu ai autorizatie la aceasat clasa, nu exista clasa sau nu exista postarea! Te rugam incearca alte optiuni" << endl;
    }
    string rp;
    cout << endl;
    cout << "Apasa: " << "\n";
    cout << "C pt a creea o clasa" << "\n";
    cout << "D pt a sterge o clasa" << "\n";
    cout << "PA pt a creea o postare de tip assignment" << "\n";
    cout << "PT pt a crea o postare de tip test" << "\n";
    cout << "DP pt a sterge o postare" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe);
    } else {
        cout << "Ai iesit!";
    }
}

void exitGroup(Student& student, list<Group> grupe);

void enterGroup(Student& student, list<Group> grupe) {
    int c;
    string rp, titluGrupa, npGrupa, ppGrupa;
    Group gt(0, " ", " ", "");
    for (Group& grupa : grupe){
        cout << grupa;
    }
    cout << "In ce clasa vrei sa te inscrii? Scrie codul acesteia!" << endl;
    cin >> c;
    for (Group& grupa : grupe){
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
    for (Group& grupa : grupe){
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

void exitGroup(Student& student, list<Group> grupe) {
    int c;
    string rp, titluGrupa, npGrupa, ppGrupa;
    Group gt(0, " ", " ", "");
    for (Group& grupa : grupe){
        cout << grupa;
    }
    cout << "Din ce clasa vrei sa iesi? Scrie codul acesteia!" << endl;
    cin >> c;
    for (Group& grupa : grupe){
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

    for (Group& grupa : grupe){
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

void menu(const list<Group> &grupe) {
    string tipCont, Nume, Prenume, Email, r;
//
//    Teacher teacher1("Marin", "Maricica", "m.m@gmail.com");
//    Teacher teacher2("Popescu", "Stefan", "p.s@gmail.com");
//    Teacher teacher3("Ion", "Cornela", "i.c@gmail.com");
//
//    Group grupa1(2345, "POO", "Marin", "Maricica");
//    Group grupa2(3456, "Python", "Popescu", "Stefan");
//    Group grupa3(4567, "C++", "Ion", "Cornela");
//    Group grupaTemporara(0, " ", " ", " ");
//
//    list<Group> grupe = {grupa1, grupa2, grupa3};

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
            menu(grupe);
        }
    }
}

int main() {

//    string tipCont, Nume, Prenume, Email, r;

    Teacher teacher1("Marin", "Maricica", "m.m@gmail.com");
    Teacher teacher2("Popescu", "Stefan", "p.s@gmail.com");
    Teacher teacher3("Ion", "Cornela", "i.c@gmail.com");

    Group grupa1(2345, "POO", "Marin", "Maricica");
    Group grupa2(3456, "Python", "Popescu", "Stefan");
    Group grupa3(4567, "C++", "Ion", "Cornela");
    Group grupaTemporara(0, " ", " ", " ");

    list<Group> grupe = {grupa1, grupa2, grupa3};

    while(true) {
        cout << endl;
        cout << "Apasa 1 ca sa intri in program, 0 ca sa iesi: " << endl;
        int x;
        cin >> x;
        if (x == 1){
            menu(grupe);
        } else {
            break;
        }
    }
    return 0;
}
