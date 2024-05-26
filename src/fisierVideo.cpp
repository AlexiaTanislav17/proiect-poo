#include "fisierVideo.h"


template<typename T, typename U>
FisierVideo<T, U>::FisierVideo(const std::string& t, const T& s, const U& nm): Fisier<T>(t, s), nrMin(nm) {}

template<typename T, typename U>
FisierVideo<T, U>::FisierVideo(const FisierVideo &fv): Fisier<T>(fv), nrMin(fv.nrMin) {}

template<typename T, typename U>
FisierVideo<T, U>::~FisierVideo() = default;

//template<typename T, typename U>
//void FisierVideo<T, U>::setNrMin(U nm) { nrMin = nm; }

template<typename T, typename U>
U FisierVideo<T, U>::getNrMin() const { return nrMin; }

template<typename T, typename U>
void FisierVideo<T, U>::citire() {
    std::cout << "Titlul fisierului video: ";
    std::cin >> this->titlu;
    std::cout << "Marimea fisierului video: ";
    std::cin >> this->size;
    std::cout << "Nr de minute: ";
    std::cin >> nrMin;
}


template<typename T, typename U>
void FisierVideo<T, U>::afisare() {
    std::cout << "Titlu: " << this->titlu << ", Marime: " << this->size << ", Nr minute: " << nrMin << std::endl;
}

template<typename T, typename U>
FisierVideo<T, U>& FisierVideo<T, U>::operator=(const FisierVideo<T, U>& fv) {
    if (this != &fv) {
        Fisier<T>::operator=(fv);
        nrMin = fv.nrMin;
    }
    return *this;
}


template class FisierVideo<int, int>;
template class FisierVideo<int, string>;
template class FisierVideo<float, int>;
template class FisierVideo<float, string>;
template class FisierVideo<double, int>;
template class FisierVideo<double, string>;
