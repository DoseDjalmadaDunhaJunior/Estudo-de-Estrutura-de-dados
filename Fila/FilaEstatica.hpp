//
// Created by djalma cunha on 16/11/18.
//

#ifndef FILA_FILAESTATICA_HPP
#define FILA_FILAESTATICA_HPP
#define max 10
#include <iostream>
using namespace std;
class FilaEstatica {

private:
    int vet[max];
    int inicio = -1;
    int fim = -1;

public:

    void enfileira(int numero){
        if(fim != (max-1)){
            fim++;
            vet[fim] = numero;
            if(inicio == -1){
                inicio++;
            }
        }
    }

    void desinfileira(){
        if(inicio == fim){
            puts("nao da para remover");
        }
        else {
            inicio++;
        }
    }

    void imprime(){
        for (int i = inicio; i < fim; i++) {
            cout<<vet[i]<<endl;
        }
    }

};


#endif //FILA_FILAESTATICA_HPP
