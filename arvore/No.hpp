//
// Created by djalma cunha on 21/11/18.
//

#ifndef ARVORE_NO_HPP
#define ARVORE_NO_HPP
#include <iostream>
using namespace std;
class No {
public:
    int num = NULL;
    No* pai = nullptr;
    No* direita = nullptr;
    No* esquerda = nullptr;
    bool lido = false;

};


#endif //ARVORE_NO_HPP
