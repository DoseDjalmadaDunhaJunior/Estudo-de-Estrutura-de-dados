//
// Created by djalma cunha on 21/11/18.
//

#ifndef ARVORE_ARVORE_HPP
#define ARVORE_ARVORE_HPP
#include "No.hpp"
class Arvore {
private:
    No *raiz = new No();
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
                        pivo = pivo->esquerda;
                    }
                }
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


#endif //ARVORE_ARVORE_HPP
