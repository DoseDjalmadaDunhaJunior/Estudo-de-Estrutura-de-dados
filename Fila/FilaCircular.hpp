//
// Created by djalma cunha on 16/11/18.
//

#ifndef FILA_FILACIRCULAR_HPP
#define FILA_FILACIRCULAR_HPP
#define max 11
#include <iostream>
using namespace std;

class FilaCircular {
private:
    int vet[max];
    int inicio = 0;
    int fim = 0;
public:

    void enfileira(int numero){
            int po = (fim+1)%max;
            if(po == inicio){
                puts("FILA LOTADA");
            }
            else {
                vet[po] = numero;
                fim++;
            }
    }

    void desinfileira(){
        if(inicio != fim){
            inicio++;
        }
        else{
            puts("JA ESTA VAZIA");
        }
    }

    void imprime(){
        for (int i = inicio; i != fim ; i++) {
            cout<<vet[(i+1)%max]<<endl;
        }
    }
};


#endif //FILA_FILACIRCULAR_HPP
