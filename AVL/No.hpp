//
// Created by djalma cunha on 24/11/18.
//

#ifndef AVL_NO_HPP
#define AVL_NO_HPP
#include <iostream>
using namespace std;
class No {
public:
    int num = NULL;
    No* pai = nullptr;
    No* direita = nullptr;
    No* esquerda = nullptr;
    int tam = 0;
    bool lido = false;
};


#endif //AVL_NO_HPP
