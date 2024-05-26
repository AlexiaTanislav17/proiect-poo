
#ifndef OOP_GROUP_H
#define OOP_GROUP_H

#include <iostream>
#include <string>
#include <list>
//#include <set>
#include <utility>
#include "student.h"
#include "post.h"
#include "assignment.h"
#include "test.h"
//#include "fisier.h"
//#include "fisierText.h"
//#include "fisierVideo.h"

using namespace std;


class Group{
private:
    int codUnic;
    string title;
    string numeProfesor;
    string prenumeProfesor;
    list<Student> studentiGrupa;
    list<Post*> posts;
//    set<FisierText<int, int>> folderText;
//    set<FisierVideo<int, int>> folderVideo;
    int nrStudenti;

public:

    Group(int c, string t, string np, string pp);

    Group(const int &c, string t, string np, string pp, const list<Student> &ss, const list<Post*> &p);

    Group(const Group &g);

    ~Group();

    friend class Student;
    friend class Teacher;
    friend class Post;
    friend class Assignment;
    friend class Test;

    void setCodUnicGrupa(int c);
    int getCodUnicGrupa() const;
    void setTitleGroup(string t);
    string getTitleGroup() const;
    void setNumeProfesorGroup(string np);
    string getNumeProfesorGroup();
    void setPrenumeProfesorGroup(string pp);
    string getPrenumeProfesorGroup();
//    int getNrStudenti() const;
    list<Post *> getPosts();
    void intratInGrupa();
    void iesitDinGrupa();
    void adaugarePostare(Post* post);
    void stergerePostare(Post* post);

    friend istream& operator>>(istream& in, Group& grupa);
    friend ostream& operator<<(ostream& out, const Group& grupa);

    Group& operator=(const Group& grupa);

    void operator+=(Student& student);
    void operator-=(const Student& student);
};

#endif //OOP_GROUP_H
