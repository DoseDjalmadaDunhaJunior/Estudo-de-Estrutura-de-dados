//
// Created by djalma cunha on 21/11/18.
//

#ifndef ARVORE_ARVORE_HPP
#define ARVORE_ARVORE_HPP
#include "No.hpp"
class Arvore {
private:
    No* raiz = new No();
public:

    void insere(int n) {
        No *novo = new No();
        novo->num = n;
        bool ok = true;
        if (raiz == nullptr) {
            raiz->num = n;
        } else {
            No *pivo = raiz;
            while (ok) {
                if (n >= pivo->num) {
                    if (pivo->direita == nullptr) {
                        pivo->direita = novo;
                        novo->pai = pivo;
                        ok = false;
                    } else {
                        pivo = pivo->direita;
                    }
                } else if (n < pivo->num) {
                    if (pivo->esquerda == nullptr) {
                        pivo->esquerda = novo;
                        novo->pai = pivo;
                        ok = false;
                    } else {
                        raiz->esquerda = novo;
                    }
                }
            }
        }
    }

    void imprime(){

    }

    ~Arvore(){
        No* pivo = raiz;
            while(raiz->direita != nullptr){
                if(pivo->direita == nullptr){
                    if(pivo->esquerda == nullptr){
                        No* temp = pivo;
                        delete pivo;
                        pivo = raiz;
                        puts("um foi apagado");
                    }
                    else{
                        pivo = pivo->esquerda;
                    }
                }
                else{
                    pivo = pivo->direita;
                }
            }
            while(raiz->esquerda != nullptr){
                if(pivo->esquerda == nullptr){
                    if(pivo->direita == nullptr){
                        No* temp = pivo;
                        pivo = pivo->pai;
                        delete(temp);
                        puts("um foi apagado");
                    }
                    else{
                        pivo = pivo->direita;
                    }
                }
                else{
                    pivo = pivo->esquerda;
                }
            }

    }
};


#endif //ARVORE_ARVORE_HPP