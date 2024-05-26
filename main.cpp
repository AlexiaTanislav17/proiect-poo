#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include <set>
#include "student.h"
#include "teacher.h"
#include "group.h"
#include "post.h"
#include "assignment.h"
#include "test.h"
//#include "fisier.h"
#include "fisierText.h"
#include "fisierVideo.h"

using namespace std;


bool operator==(const Group& g1, const Group& g2) {
    if (g1.getCodUnicGrupa()== g2.getCodUnicGrupa()){
        return true;
    }
    return false;
}

bool operator<(const Group& g1, const Group& g2) {
    return g1.getTitleGroup() < g2.getTitleGroup();
}

bool operator<(const FisierText<int, int>& ft1, const FisierText<int, int>& ft2) {
    return ft1.getTitlu() < ft2.getTitlu();
}

bool operator<(const FisierVideo<int, int>& fv1, const FisierVideo<int, int>& fv2) {
    return fv1.getTitlu() < fv2.getTitlu();
}


void addFisierText(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo);

void addFisierVideo(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo);

void createAssignment(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo);

void createTest(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo);

void deletePost(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo);

void modifyDuePost(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo);

void deleteGroup(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo);

void createGroup(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo) {
    Group grupa(0, " ", " ", " ");
    grupa.setNumeProfesorGroup(teacher.getNumeTeacher());
    grupa.setPrenumeProfesorGroup(teacher.getPrenumeTeacher());
    cin >> grupa;
    grupe.push_back(grupa);
    grupe.sort([](const Group & grupa1, const Group & grupa2)
                       {
                           if(grupa1.getTitleGroup() == grupa2.getTitleGroup())
                               return grupa1 < grupa2;        //supraincarc <
                           return grupa1.getTitleGroup() < grupa2.getTitleGroup();
                       });
    Teacher::incrementTotalGroups();
    teacher.afTotalGroups();
    for (auto& f : folderText) {
        cout << f.getTitlu();
        cout << f.getSize();
        cout << f.getNrPag() << "\n";
    }
    for (auto& f : folderVideo) {
        cout << f.getTitlu();
        cout << f.getSize();
        cout << f.getNrMin() << "\n";
    }
    for (Group& g : grupe){
        cout << g << "\n";
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
    cout << "MP pt a modifica timpul unei postari" << "\n";
    cout << "AT pt a aduga un fisier text la folderul tau" << "\n";
    cout << "AV pt a aduga un fisier video la folderul tau" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "mp" || rp =="MP" || rp == "Mp" || rp == "mP") {
        modifyDuePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "at" || rp =="AT" || rp == "At" || rp == "aT") {
        addFisierText(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "av" || rp =="AV" || rp == "Av" || rp == "aV") {
        addFisierVideo(teacher, grupe, folderText, folderVideo);
    } else {
        cout << " ";
    }
}

void addFisierText(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo) {
    FisierText<int, int> ft("", 0,0);
    ft.citire();
    folderText.insert(ft);
    cout << "Folderul tau de documente: "<< "\n";
    for (auto& f : folderText) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrPag() << "\n";
    }
    cout << "Folderul tau de videouri: "<< "\n";
    for (auto& f : folderVideo) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrMin() << "\n";
    }
    for (Group& g : grupe){
        cout << g << "\n";
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
    cout << "MP pt a modifica timpul unei postari" << "\n";
    cout << "AT pt a aduga un fisier text la folderul tau" << "\n";
    cout << "AV pt a aduga un fisier video la folderul tau" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "mp" || rp =="MP" || rp == "Mp" || rp == "mP") {
        modifyDuePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "at" || rp =="AT" || rp == "At" || rp == "aT") {
        addFisierText(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "av" || rp =="AV" || rp == "Av" || rp == "aV") {
        addFisierVideo(teacher, grupe, folderText, folderVideo);
    } else {
        cout << " ";
    }
}

void addFisierVideo(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo) {
    FisierVideo<int, int> fv("", 0,0);
    fv.citire();
    folderVideo.insert(fv);
    cout << "Folderul tau de documente: "<< "\n";
    for (auto& f : folderText) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrPag() << "\n";
    }
    cout << "Folderul tau de videouri: "<< "\n";
    for (auto& f : folderVideo) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrMin() << "\n";
    }
    for (Group& g : grupe){
        cout << g << "\n";
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
    cout << "MP pt a modifica timpul unei postari" << "\n";
    cout << "AT pt a aduga un fisier text la folderul tau" << "\n";
    cout << "AV pt a aduga un fisier video la folderul tau" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "mp" || rp =="MP" || rp == "Mp" || rp == "mP") {
        modifyDuePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "at" || rp =="AT" || rp == "At" || rp == "aT") {
        addFisierText(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "av" || rp =="AV" || rp == "Av" || rp == "aV") {
        addFisierVideo(teacher, grupe, folderText, folderVideo);
    } else {
        cout << " ";
    }
}

void deleteGroup(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo){
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
    try {
        if (npGrupa == teacher.getNumeTeacher() && ppGrupa == teacher.getPrenumeTeacher()){
            Group gt(0, " "," ", " ");
            gt.setNumeProfesorGroup(npGrupa);
            gt.setPrenumeProfesorGroup(ppGrupa);
            gt.setTitleGroup(titluGrupa);
            gt.setCodUnicGrupa(c);
            grupe.remove(gt);
            grupe.sort([](const Group & grupa1, const Group & grupa2)
                       {
                           if(grupa1.getTitleGroup() == grupa2.getTitleGroup())
                               return grupa1 < grupa2;        //supraincarc <
                           return grupa1.getTitleGroup() < grupa2.getTitleGroup();
                       });
            Teacher::decrementTotalGroups();
            teacher.afTotalGroups();
            cout << "Folderul tau de documente: "<< "\n";
            for (auto& f : folderText) {
                cout << f.getTitlu() << "  size:";
                cout << f.getSize() << "kb  nr pag:";
                cout << f.getNrPag() << "\n";
            }
            cout << "Folderul tau de videouri: "<< "\n";
            for (auto& f : folderVideo) {
                cout << f.getTitlu() << "  size:";
                cout << f.getSize() << "kb  nr pag:";
                cout << f.getNrMin() << "\n";
            }
            for (Group& g : grupe){
                cout << g << "\n";
            }
            string rp;
            cout << endl;
            cout << "Apasa: " << "\n";
            cout << "C pt a creea o clasa" << "\n";
            cout << "D pt a sterge o clasa" << "\n";
            cout << "PA pt a creea o postare de tip assignment" << "\n";
            cout << "PT pt a crea o postare de tip test" << "\n";
            cout << "DP pt a sterge o postare" << "\n";
            cout << "MP pt a modifica timpul unei postari" << "\n";
            cout << "AT pt a aduga un fisier text la folderul tau" << "\n";
            cout << "AV pt a aduga un fisier video la folderul tau" << "\n";
            cout << "orice altceva pt a iesi" << endl;
            cin >> rp;
            if (rp == "C" || rp=="c") {
                createGroup(teacher, grupe, folderText, folderVideo);
            }
            if (rp == "D" || rp == "d"){
                deleteGroup(teacher, grupe, folderText, folderVideo);
            }
            if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
                createAssignment(teacher, grupe, folderText, folderVideo);
            }
            if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
                createTest(teacher, grupe, folderText, folderVideo);
            }
            if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
                deletePost(teacher, grupe, folderText, folderVideo);
            }
            if (rp == "mp" || rp =="MP" || rp == "Mp" || rp == "mP") {
                modifyDuePost(teacher, grupe, folderText, folderVideo);
            }
            if (rp == "at" || rp =="AT" || rp == "At" || rp == "aT") {
                addFisierText(teacher, grupe, folderText, folderVideo);
            }
            if (rp == "av" || rp =="AV" || rp == "Av" || rp == "aV") {
                addFisierVideo(teacher, grupe, folderText, folderVideo);
            } else {
                cout << " ";
            }
        } else {
            cout << endl;
            throw std::runtime_error("Nu ai autorizatie sa stergi aceasta clasa sau nu exista! Te rugam continua cu alta optiune.");
        }
    } catch (const std::runtime_error& e) {
        cerr << "Eroare: " << e.what() << endl;
        string rp;
        cout << endl;
        cout << "Apasa: " << "\n";
        cout << "C pt a creea o clasa" << "\n";
        cout << "D pt a sterge o clasa" << "\n";
        cout << "PA pt a creea o postare de tip assignment" << "\n";
        cout << "PT pt a crea o postare de tip test" << "\n";
        cout << "DP pt a sterge o postare" << "\n";
        cout << "MP pt a modifica timpul unei postari" << "\n";
        cout << "AT pt a aduga un fisier text la folderul tau" << "\n";
        cout << "AV pt a aduga un fisier video la folderul tau" << "\n";
        cout << "orice altceva pt a iesi" << endl;
        cin >> rp;
        if (rp == "C" || rp=="c") {
            createGroup(teacher, grupe, folderText, folderVideo);
        }
        if (rp == "D" || rp == "d"){
            deleteGroup(teacher, grupe, folderText, folderVideo);
        }
        if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
            createAssignment(teacher, grupe, folderText, folderVideo);
        }
        if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
            createTest(teacher, grupe, folderText, folderVideo);
        }
        if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
            deletePost(teacher, grupe, folderText, folderVideo);
        }
        if (rp == "mp" || rp =="MP" || rp == "Mp" || rp == "mP") {
            modifyDuePost(teacher, grupe, folderText, folderVideo);
        }
        if (rp == "at" || rp =="AT" || rp == "At" || rp == "aT") {
            addFisierText(teacher, grupe, folderText, folderVideo);
        }
        if (rp == "av" || rp =="AV" || rp == "Av" || rp == "aV") {
            addFisierVideo(teacher, grupe, folderText, folderVideo);
        } else {
            cout << " ";
        }
    }
}

void createAssignment(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo) {
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
    teacher.afTotalGroups();
    cout << "Folderul tau de documente: "<< "\n";
    for (auto& f : folderText) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrPag() << "\n";
    }
    cout << "Folderul tau de videouri: "<< "\n";
    for (auto& f : folderVideo) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrMin() << "\n";
    }
    for (Group& g : grupe){
        cout << g << "\n";
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
    cout << "MP pt a modifica timpul unei postari" << "\n";
    cout << "AT pt a aduga un fisier text la folderul tau" << "\n";
    cout << "AV pt a aduga un fisier video la folderul tau" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "mp" || rp =="MP" || rp == "Mp" || rp == "mP") {
        modifyDuePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "at" || rp =="AT" || rp == "At" || rp == "aT") {
        addFisierText(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "av" || rp =="AV" || rp == "Av" || rp == "aV") {
        addFisierVideo(teacher, grupe, folderText, folderVideo);
    } else {
        cout << " ";
    }
}

void createTest(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo) {
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
    teacher.afTotalGroups();
    cout << "Folderul tau de documente: "<< "\n";
    for (auto& f : folderText) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrPag() << "\n";
    }
    cout << "Folderul tau de videouri: "<< "\n";
    for (auto& f : folderVideo) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrMin() << "\n";
    }
    for (Group& g : grupe){
        cout << g << "\n";
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
    cout << "MP pt a modifica timpul unei postari" << "\n";
    cout << "AT pt a aduga un fisier text la folderul tau" << "\n";
    cout << "AV pt a aduga un fisier video la folderul tau" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "mp" || rp =="MP" || rp == "Mp" || rp == "mP") {
        modifyDuePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "at" || rp =="AT" || rp == "At" || rp == "aT") {
        addFisierText(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "av" || rp =="AV" || rp == "Av" || rp == "aV") {
        addFisierVideo(teacher, grupe, folderText, folderVideo);
    } else {
        cout << " ";
    }
}

void deletePost(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo) {
    int c;
    int k = 0;
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
    teacher.afTotalGroups();
    cout << "Folderul tau de documente: "<< "\n";
    for (auto& f : folderText) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrPag() << "\n";
    }
    cout << "Folderul tau de videouri: "<< "\n";
    for (auto& f : folderVideo) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrMin() << "\n";
    }
    for (Group& g : grupe){
        cout << g << "\n";
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
    cout << "MP pt a modifica timpul unei postari" << "\n";
    cout << "AT pt a aduga un fisier text la folderul tau" << "\n";
    cout << "AV pt a aduga un fisier video la folderul tau" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "mp" || rp =="MP" || rp == "Mp" || rp == "mP") {
        modifyDuePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "at" || rp =="AT" || rp == "At" || rp == "aT") {
        addFisierText(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "av" || rp =="AV" || rp == "Av" || rp == "aV") {
        addFisierVideo(teacher, grupe, folderText, folderVideo);
    } else {
        cout << " ";
    }
}

void modifyDuePost(Teacher& teacher, list<Group>& grupe, set<FisierText<int, int>> &folderText, set<FisierVideo<int, int>> &folderVideo) {
    int c;
    int k = 0;
    cout << "Introdu codul clasei din care vrei sa modifici postarea: " << endl;
    cin >> c;
    for (Group& g : grupe){
        if (c == g.getCodUnicGrupa() && teacher.getNumeTeacher() == g.getNumeProfesorGroup() && g.getPrenumeProfesorGroup() == teacher.getPrenumeTeacher()){
            cout << "Introdu titlul postarii la care vrei sa modifici: " << endl;
            string titluPostare;
            cin >> titluPostare;
            for (auto post : g.getPosts()) {
                if (post->getTitlu() == titluPostare) {
                    k = 1;
                    if (auto* a = dynamic_cast<Assignment*>(post)) {
                        string newDueDate;
                        cout << "Introdu noul termen de predare: ";
                        cin >> newDueDate;
                        a->setDueDate(newDueDate);
                    }
                    if (Test* t = dynamic_cast<Test*>(post)) {
                        string newDueTime;
                        cout << "Introdu noul termen de predare: ";
                        cin >> newDueTime;
                        t->setDueTime(newDueTime);
                    }
                }
            }
        }
    }
    teacher.afTotalGroups();
    cout << "Folderul tau de documente: " << "\n";
    for (auto& f : folderText) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrPag() << "\n";
    }
    cout << "Folderul tau de videouri: "<< "\n";
    for (auto& f : folderVideo) {
        cout << f.getTitlu() << "  size:";
        cout << f.getSize() << "kb  nr pag:";
        cout << f.getNrMin() << "\n";
    }
    for (Group& g : grupe){
        cout << g << "\n";
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
    cout << "MP pt a modifica timpul unei postari" << "\n";
    cout << "AT pt a aduga un fisier text la folderul tau" << "\n";
    cout << "AV pt a aduga un fisier video la folderul tau" << "\n";
    cout << "orice altceva pt a iesi" << endl;
    cin >> rp;
    if (rp == "C" || rp=="c") {
        createGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "D" || rp == "d"){
        deleteGroup(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pa" || rp =="PA" || rp == "Pa" || rp == "pA") {
        createAssignment(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "pt" || rp =="PT" || rp == "Pt" || rp == "pT") {
        createTest(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "dp" || rp =="DP" || rp == "Dp" || rp == "dP") {
        deletePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "mp" || rp =="MP" || rp == "Mp" || rp == "mP") {
        modifyDuePost(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "at" || rp =="AT" || rp == "At" || rp == "aT") {
        addFisierText(teacher, grupe, folderText, folderVideo);
    }
    if (rp == "av" || rp =="AV" || rp == "Av" || rp == "aV") {
        addFisierVideo(teacher, grupe, folderText, folderVideo);
    } else {
        cout << " ";
    }
}

void exitGroup(Student& student, list<Group> grupe);

void enterGroup(Student& student, list<Group> grupe) {
    int c;
    string rp, titluGrupa, npGrupa, ppGrupa;
    Group gt(0, " ", " ", "");
    for (Group& grupa : grupe){
        cout << grupa << "\n";
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
            cout << " ";
        }
    }
}

void exitGroup(Student& student, list<Group> grupe) {
    int c;
    string rp, titluGrupa, npGrupa, ppGrupa;
    Group gt(0, " ", " ", "");
    for (Group& grupa : grupe){
        cout << grupa << "\n";
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
        cout << grupa << "\n";
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
            cout << " ";
        }
    }
}

void menu(list<Group> &grupe) {
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

            set<FisierText<int, int>> folderText;
            set<FisierVideo<int, int>> folderVideo;

            FisierText<int, int> ft("readMe", 0,1);
            folderText.insert(ft);

            FisierVideo<int, int> fv("watchMe", 0,1);
            folderVideo.insert(fv);

            cout << "Vrei sa creezi o clasa? Y/N" << endl;
            cin >> r;
            if (r=="Y" || r=="y"){
                createGroup(teacher, grupe, folderText, folderVideo);
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
