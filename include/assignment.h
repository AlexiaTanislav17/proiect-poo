
#ifndef OOP_ASSIGNMENT_H
#define OOP_ASSIGNMENT_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include "post.h"
#include "teacher.h"


class Assignment: public Post {
private:
    string file;
    string dueDate;
    int grade;

public:

    Assignment(const string& t = "", const string& d = "", const string& nu = "",  const string& pu = "", string f = "", string dd = "");

    Assignment(const Assignment &a);

    ~Assignment();

    friend class Teacher;

//    void setFile(string f);
//    string getFile();
//    void setGrade(int g);
//    int getGrade() const;
    void setDueDate(string dd);
//    string getDueDate();
    void citire(Teacher& t) override;
    void afisare() override;

    Assignment& operator=(const Assignment& a);

};

#endif //OOP_ASSIGNMENT_H
