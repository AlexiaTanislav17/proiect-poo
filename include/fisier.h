#ifndef OOP_FISIER_H
#define OOP_FISIER_H

#include <iostream>

using namespace std;

using namespace std;

template<typename T>
class Fisier {
protected:
    string titlu;
    T size;

public:

    Fisier(string t, T s);

    Fisier(const Fisier &f);

    virtual ~Fisier();

//    virtual void setTitlu(string t);
//    virtual void setSize(T s);
    string getTitlu() const;
    T getSize() const;

    virtual void citire() = 0;
    virtual void afisare() = 0;

    Fisier& operator=(const Fisier& f);

};


#endif //OOP_FISIER_H
