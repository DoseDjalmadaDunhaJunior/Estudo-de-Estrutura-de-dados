//
// Created by djalma cunha on 25/11/18.
//

#ifndef AVL_MESMO_NO_HPP
#define AVL_MESMO_NO_HPP

#include <iostream>
using namespace std;
template <typename T>
class No{
public:
    T val;
    No* esq;
    No* dir;
    T altura;
};




#endif //AVL_MESMO_NO_HPP
