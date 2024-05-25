
#ifndef OOP_TEST_H
#define OOP_TEST_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include "post.h"
#include "teacher.h"
//#pragma once   //am vzt asta undeva ca sa nu iti repete fisierul?

class Test: public Post {
private:
    string file;
    string dueTime;
    int grade;

public:
    Test(const string& t = "", const string& d = "", const string& nu = "",  const string& pu = "", string f = "", string dt = "");

    Test(const Test &t);

    ~Test();

    friend class Teacher;

//    void setFile(string f);
//    string getFile();
//    void setGrade(int g);
//    int getGrade() const;
    void setDueTime(string dt);
//    string getDueTime();

    void citire(Teacher& t) override;
    void afisare() override;

    Test& operator=(const Test& a);
};

#endif //OOP_TEST_H
