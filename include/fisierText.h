#ifndef OOP_FISIERTEXT_H
#define OOP_FISIERTEXT_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include "fisier.h"

template<typename T, typename U>
class FisierText: public Fisier<T> {
private:
    U nrPag;

public:

    FisierText(const string& t, const T& s, const U& np);

    FisierText(const FisierText &ft);

    ~FisierText();

    //void setNrPag(U np);
    U getNrPag() const;
    void citire() override;
    void afisare() override;

    FisierText& operator=(const FisierText& ft);

};

#endif //OOP_FISIERTEXT_H
