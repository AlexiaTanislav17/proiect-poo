#include "fisierText.h"


template<typename T, typename U>
FisierText<T, U>::FisierText(const std::string& t, const T& s, const U& np): Fisier<T>(t, s), nrPag(np) {}

template<typename T, typename U>
FisierText<T, U>::FisierText(const FisierText &ft): Fisier<T>(ft), nrPag(ft.nrPag) {}

template<typename T, typename U>
FisierText<T, U>::~FisierText() = default;

//template<typename T, typename U>
//void FisierText<T, U>::setNrPag(U np) { nrPag = np; }

template<typename T, typename U>
U FisierText<T, U>::getNrPag() const { return nrPag; }

template<typename T, typename U>
void FisierText<T, U>::citire() {
    std::cout << "Titlul fisierului text: ";
    std::cin >> this->titlu;
    std::cout << "Marimea fisierului text: ";
    std::cin >> this->size;
    std::cout << "Nr de pagini: ";
    std::cin >> nrPag;
}


template<typename T, typename U>
void FisierText<T, U>::afisare() {
    std::cout << "Titlu: " << this->titlu << ", Marime: " << this->size << ", Nr pagini: " << nrPag << std::endl;
}

template<typename T, typename U>
FisierText<T, U>& FisierText<T, U>::operator=(const FisierText<T, U>& ft) {
    if (this != &ft) {
        Fisier<T>::operator=(ft);
        nrPag = ft.nrPag;
    }
    return *this;
}


template class FisierText<int, int>;
template class FisierText<int, string>;
template class FisierText<float, int>;
template class FisierText<float, string>;
template class FisierText<double, int>;
template class FisierText<double, string>;
