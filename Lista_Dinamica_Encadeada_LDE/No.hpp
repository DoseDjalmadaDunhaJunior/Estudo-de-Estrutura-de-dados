//
// Created by djalma cunha on 10/11/18.
//

#ifndef LISTA_DINAMICA_ENCADEADA_LDE_NO_HPP
#define LISTA_DINAMICA_ENCADEADA_LDE_NO_HPP
#include <iostream>
using namespace std;
class No {
public:
    //para gravar o proximo valor
No* proximo = nullptr;
    //para gravar o numero que vai ter
int valor = 0;
    //para gravar o numero anterior
No* anterior = nullptr;

No(int num){
    valor = num;
}
};


#endif //LISTA_DINAMICA_ENCADEADA_LDE_NO_HPP
