//
// Created by djalma cunha on 17/11/18.
//

#ifndef FILA_DINAMICA_FILA_HPP
#define FILA_DINAMICA_FILA_HPP
#include "No.hpp"
class Fila {
private:
    No* atual;
    No* primeiro;
    No* fim;


public:

    void inserir(int num) {
        atual = primeiro;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        if (fim->proximo == nullptr && atual->proximo == nullptr) {
            atual->valor = num;
            primeiro = atual;
            fim = atual;
        } else if (fim == primeiro) {
            atual->valor = num;
            primeiro->proximo = atual;
            fim = atual;
        }
    }

    void imprime(){
        int ver,cont = 0;
        atual = primeiro;
        while(atual){
            ver = atual->valor;
            cout<<atual->valor<<endl;
            atual = atual->proximo;
            cont++;
        }
        cout<<atual->valor<<endl;
    }

    ~Fila(){
        No* temp;
        while(atual){
            temp = atual;
            atual->proximo;
            delete(temp);
            cout<<"DELETADO"<<endl;
        }
        //delete(fim);
    }
};


#endif //FILA_DINAMICA_FILA_HPP
