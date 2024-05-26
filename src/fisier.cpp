#include "fisier.h"

template<typename T>
Fisier<T>::Fisier(string t, T s) : titlu(std::move(t)), size(s) {}

template<typename T>
Fisier<T>::Fisier(const Fisier &f) : titlu(f.titlu), size(f.size) {}

template<typename T>
Fisier<T>::~Fisier() = default;

template<typename T>
string Fisier<T>::getTitlu() const{ return titlu; }

template<typename T>
T Fisier<T>::getSize() const{ return size; }

//template<typename T>
//void Fisier<T>::setTitlu(string t) { titlu = std::move(t); }            //virtual
//
//template<typename T>
//void Fisier<T>::setSize(T s) { size = std::move(s); }            //virtual

template<typename T>
Fisier<T>& Fisier<T>::operator=(const Fisier<T>& f) {
    if (this != &f) {
        titlu = f.titlu;
        size = f.size;
    }
    return *this;
}

template class Fisier<int>;
template class Fisier<float>;
template class Fisier<double>;
template class Fisier<long>;
