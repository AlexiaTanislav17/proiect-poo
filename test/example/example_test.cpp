#include <gtest/gtest.h>
#include "example.h"
#include "student.h"
#include "teacher.h"
#include "group.h"
#include "post.h"
#include "assignment.h"
//#include "test.h"

TEST(SuiteName, TestName) {
    EXPECT_EQ(doSomething(20), 20);
    // Other assertions: https://google.github.io/googletest/reference/assertions.html#boolean
}

TEST(StudentTest, DefaultConstructor) {
    Student s;
    EXPECT_EQ(s.getNumeStudent(), "");
    EXPECT_EQ(s.getPrenumeStudent(), "");
    EXPECT_EQ(s.getEmailStudent(), "");
}

TEST(StudentTest, ParameterizedConstructor) {
    Student s("John", "Doe", "john.doe@example.com");
    EXPECT_EQ(s.getNumeStudent(), "John");
    EXPECT_EQ(s.getPrenumeStudent(), "Doe");
    EXPECT_EQ(s.getEmailStudent(), "john.doe@example.com");
}

TEST(StudentTest, SettersAndGetters) {
    Student s;
    s.setNumeStudent("Jane");
    s.setPrenumeStudent("Smith");
    s.setEmailStudent("jane.smith@example.com");
    EXPECT_EQ(s.getNumeStudent(), "Jane");
    EXPECT_EQ(s.getPrenumeStudent(), "Smith");
    EXPECT_EQ(s.getEmailStudent(), "jane.smith@example.com");
}

TEST(StudentTest, EqualityOperator) {
    Student s1("John", "Doe", "john.doe@example.com");
    Student s2("John", "Doe", "john.doe@example.com");
    Student s3("Jane", "Smith", "jane.smith@example.com");
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
}

TEST(StudentTest, OutputOperator) {
    Student s("John", "Doe", "john.doe@example.com");
    std::ostringstream oss;
    oss << s;
    std::string expectedOutput = "Nume si Prenume: John Doe\nEmail: john.doe@example.com\n";
    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST(TeacherTest, DefaultConstructor) {
    Teacher t;
    EXPECT_EQ(t.getNumeTeacher(), "");
    EXPECT_EQ(t.getPrenumeTeacher(), "");
    EXPECT_EQ(t.getEmailTeacher(), "");
    EXPECT_EQ(Teacher::getTotalGroups(), 0);
}

TEST(TeacherTest, ParameterizedConstructor) {
    Teacher t("John", "Doe", "john.doe@example.com");
    EXPECT_EQ(t.getNumeTeacher(), "John");
    EXPECT_EQ(t.getPrenumeTeacher(), "Doe");
    EXPECT_EQ(t.getEmailTeacher(), "john.doe@example.com");
    EXPECT_EQ(Teacher::getTotalGroups(), 0);
}

TEST(TeacherTest, SettersAndGetters) {
    Teacher t;
    t.setNumeTeacher("Jane");
    t.setPrenumeTeacher("Smith");
    t.setEmailTeacher("jane.smith@example.com");
    EXPECT_EQ(t.getNumeTeacher(), "Jane");
    EXPECT_EQ(t.getPrenumeTeacher(), "Smith");
    EXPECT_EQ(t.getEmailTeacher(), "jane.smith@example.com");
}

TEST(TeacherTest, TotalGroups) {
    Teacher t;
    EXPECT_EQ(Teacher::getTotalGroups(), 0);
    Teacher::incrementTotalGroups();
    EXPECT_EQ(Teacher::getTotalGroups(), 1);
    Teacher::decrementTotalGroups();
    EXPECT_EQ(Teacher::getTotalGroups(), 0);
    Teacher::decrementTotalGroups(); // decrementTotalGroups() nu ar trebui să scadă sub 0
    EXPECT_EQ(Teacher::getTotalGroups(), 0);
}

TEST(GroupTest, DefaultConstructor) {
    Group g(123, "Title", "TeacherName", "TeacherSurname");
    EXPECT_EQ(g.getCodUnicGrupa(), 123);
    EXPECT_EQ(g.getTitleGroup(), "Title");
    EXPECT_EQ(g.getNumeProfesorGroup(), "TeacherName");
    EXPECT_EQ(g.getPrenumeProfesorGroup(), "TeacherSurname");
    EXPECT_EQ(g.getPosts().size(), 0);
}

TEST(GroupTest, IncrementAndDecrementStudents) {
    Group g(123, "Title", "TeacherName", "TeacherSurname");
    EXPECT_EQ(g.getNrStudenti(), 0);
    g.intratInGrupa();
    EXPECT_EQ(g.getNrStudenti(), 1);
    g.iesitDinGrupa();
    EXPECT_EQ(g.getNrStudenti(), 0);
}

TEST(GroupTest, OutputOperator) {
    Group g(123, "Title", "TeacherName", "TeacherSurname");
    std::ostringstream oss;
    oss << g;
    std::string expectedOutput = "Clasa: Title\nProfesorul: TeacherName TeacherSurname\nCodul: 123\nNr elevi inscrisi: 0\n";
    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST(PostTest, DefaultConstructor) {
    Post* post = new Assignment();
    EXPECT_EQ(post->getTitlu(), "");
    delete post;
}

TEST(PostTest, ParameterizedConstructor) {
    Post* post = new Assignment("Assignment1", "Description1", "John", "Doe");
    EXPECT_EQ(post->getTitlu(), "Assignment1");
    EXPECT_EQ(post->getDescriere(), "Description1");
    delete post;
}

TEST(PostTest, SettersAndGetters) {
    Post* post = new Assignment();
    post->setTitlu("Assignment1");
    post->setDescriere("Description1");
    EXPECT_EQ(post->getTitlu(), "Assignment1");
    EXPECT_EQ(post->getDescriere(), "Description1");
    delete post;
}

TEST(PostTest, AssignmentOperator) {
    Post* post1 = new Assignment("Assignment1", "Description1", "John", "Doe");
    Post* post2 = new Assignment();
    *post2 = *post1;
    EXPECT_EQ(post2->getTitlu(), "Assignment1");
    EXPECT_EQ(post2->getDescriere(), "Description1");
    EXPECT_EQ(post2->getNumeUser(), "John");
    EXPECT_EQ(post2->getPrenumeUser(), "Doe");
    delete post1;
    delete post2;
}





