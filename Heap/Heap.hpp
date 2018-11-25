//
// Created by djalma cunha on 25/11/18.
//

#ifndef HEAP_HEAP_HPP
#define HEAP_HEAP_HPP
#define max 10
#include "No.hpp"

class Heap {
private:
    No* heap;

    int pai(int filho){
        return (int)(filho-1)/2;
    }

    int ultimoPP(No* h){
        return (h->quantidade/2) -1;
    }

    int filhoE(int p){
        return 2*p+1;
    }

    int filhoD(int p){
        return 2*p+2;
    }

    void peneira(No* heap, int pai) {
        int fesq = filhoE(pai), fd = filhoD(pai),maior,aux;
        if(fesq < heap->quantidade && heap->itens[fesq]>heap->itens[pai]){
            maior = fesq;
        }
        else{
            maior = pai;
        }
        if(fd < heap->quantidade && heap->itens[fd] > heap->itens[maior]){
            maior = fd;
        }
        if(maior!=pai){
            aux = heap->itens[pai];
            heap->itens[pai] = heap->itens[maior];
            heap->itens[maior] = aux;
            peneira(heap,maior);
        }
    }

    void construir(No* heap){
        for (int i = ultimoPP(heap); i >= 0 ; i--) {
            peneira(heap,i);
        }
    }
public:
    void inserir(int valor){
        int novo;
        int novol = heap->quantidade;
        if(heap->quantidade != max){
            int ver = heap->itens[(novol-1)];
            heap->itens[novol] = novo;
            heap->quantidade++;
            if(heap->quantidade != 1){
                if(heap->itens[pai(novol)] < heap->itens[novol]){
                    construir(heap);
                }
            }
        }
        else{
            puts("cheio");
        }
    }
/*
    void vetor(int* vet){
        No* oi;
        oi->vetor = vet;

    }
*/
/*
    void apaga(int* vet){
        int aux;

    }
*/
    void apaga(No* heap){
        int aux;
        if(heap->quantidade > 0){
            aux = heap->itens[0];
            heap->itens[0] = heap->itens[heap->quantidade-1];
            heap->itens[heap->quantidade-1] = aux;
            heap->quantidade--;
            construir(heap);
            cout<<"\nItem MAximo Removido: "<<aux<<endl;
        }
        else{
            puts("vazio");
        }
    }
};


#endif //HEAP_HEAP_HPP
