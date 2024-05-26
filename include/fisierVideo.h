#ifndef OOP_FISIERVIDEO_H
#define OOP_FISIERVIDEO_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include "fisier.h"

template<typename T, typename U>
class FisierVideo: public Fisier<T> {
private:
    U nrMin;

public:

    FisierVideo(const string& t, const T& s, const U& nm);

    FisierVideo(const FisierVideo &fv);

    ~FisierVideo();

    //void setNrMin(U nm);
    U getNrMin() const;
    void citire() override;
    void afisare() override;

    FisierVideo& operator=(const FisierVideo& fv);

};

#endif //OOP_FISIERVIDEO_H
