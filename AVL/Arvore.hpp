//
// Created by djalma cunha on 24/11/18.
//

#ifndef AVL_ARVORE_HPP
#define AVL_ARVORE_HPP
#include "No.hpp"
class Arvore {
private:
    No *raiz = new No();

    void leftRotate(No* aux){
        No* pai = aux;
        No* dir = aux->direita;
        No* esq = aux->esquerda;

        aux->esquerda = pai;
        aux->direita = esq;
        aux = dir;
    }

    void rightRotate(No* aux){
        No* pai = aux;
        No* dir = aux->direita;
        No* esq = aux->esquerda;

        aux->esquerda = pai;
        aux->direita = esq;
        aux = dir;
    }

    No* balanceia(No* pai){
        if(pai->tam > 1){
            leftRotate(pai);
        }
        else if(pai->tam < -1){
            rightRotate(pai);
        }
    }

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
                int ver = pivo->num;
                if (n >= pivo->num) {
                    if (pivo->direita == nullptr) {
                        novo->tam = 1;
                        pivo->direita = novo;
                        novo->pai = pivo;
                        ok = false;
                    } else {
                        pivo = pivo->direita;
                    }
                } else if (n < pivo->num) {
                    if (pivo->esquerda == nullptr) {
                        novo->tam = 1;
                        pivo->esquerda = novo;
                        novo->pai = pivo;
                        ok = false;
                    } else {
                        pivo = pivo->esquerda;
                    }
                }
                balanceia(pivo);
            }
        }
    }

    void imprime() {
        No *atual;
        No *pai = new No();
        atual = raiz;
        while (raiz->direita != nullptr && !raiz->direita->lido) {
            if ((atual->direita == nullptr) || (atual->direita->lido)) {
                if ((atual->esquerda == nullptr) || (atual->esquerda->lido)) {
                    cout << atual->num << endl;
                    atual->lido = true;
                    atual = atual->pai;
                } else {
                    atual = atual->esquerda;
                }
            } else {
                atual = atual->direita;
            }

        }
        while (raiz->esquerda != nullptr && !raiz->esquerda->lido) {
            if ((atual->esquerda == nullptr) || (atual->esquerda->lido)) {
                if ((atual->direita == nullptr) || (atual->direita->lido)) {
                    cout << atual->num << endl;
                    atual->lido = true;
                    atual = atual->pai;
                } else {
                    atual = atual->direita;
                }
            } else {
                atual = atual->esquerda;
            }
        }
    }

};


#endif //AVL_ARVORE_HPP
