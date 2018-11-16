//
// Created by djalma cunha on 10/11/18.
//

#ifndef LISTA_DINAMICA_ENCADEADA_LDE_LDE_HPP
#define LISTA_DINAMICA_ENCADEADA_LDE_LDE_HPP
#include "No.hpp"
class LDE {
private:
    int valor = 0;
    No* primeiro = NULL;
public:
    //a funcao abaixo insere em ordem crescente se nao ele ignora o valor anterior
    void insereOrdenado(int valor){
        No* novo = new No(valor);
        No* anterior = nullptr;
        No* atual = primeiro;
        while(atual && valor > atual->valor){
            anterior = atual;
            atual = atual->proximo;
        }
        atual = novo;
        if(anterior == nullptr){
            primeiro = novo;
        }
        else{
            anterior->proximo = novo;
        }
    }
    //a funcao abaixo apenas imprime
    void imprime(){
        No* anterior = nullptr;
        No* atual = primeiro;
        while(atual && (atual->proximo != primeiro)){
            int ver = atual->valor;
            cout<<atual->valor<<endl;
            anterior = atual;
            atual = atual->proximo;
        }

    }

    ~LDE(){
        No* anterior = nullptr;
        No* atual = primeiro;
        while(atual != primeiro){
            anterior = atual;
            atual = atual->proximo;
            delete(anterior);
        }
        delete(primeiro);
    }
};


#endif //LISTA_DINAMICA_ENCADEADA_LDE_LDE_HPP
