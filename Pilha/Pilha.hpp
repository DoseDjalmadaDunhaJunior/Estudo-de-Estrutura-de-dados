//
// Created by djalma cunha on 21/11/18.
//

#ifndef PILHA_PILHA_HPP
#define PILHA_PILHA_HPP
#include <iostream>
#define max 10
using namespace std;

class Pilha {
private:
    int vetor[max];
    int topo = -1;

public:

    void emplilha(int n){
        topo++;
        if(topo < max) {
            vetor[topo] = n;
        }
        else{
            topo--;
            puts("vetor esta cheio");
        }
    }

    void desempilha(){
        topo--;
        if(topo < -1){
            topo++;
            puts("vetor esta vazio");
        }
    }

    void imprime(){
        if(topo == -1){
            puts("impossivel imprimir");
        }
        for (int i = 0; i <= topo; i++) {
            cout<<vetor[i]<<endl;
        }
    }

};


#endif //PILHA_PILHA_HPP
