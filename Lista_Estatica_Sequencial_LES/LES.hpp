//
// Created by djalma cunha on 10/11/18.
//

#ifndef LISTA_ESTATICA_SEQUENCIAL_LES_LES_HPP
#define LISTA_ESTATICA_SEQUENCIAL_LES_LES_HPP
#include <iostream>
using namespace std;

template <typename T>
class LES {
private:
    //vetor
    T vet[11];
    //po == ate qual posicao o vetor esta sendo usado
    int po = 0;
    //size == tamanho maximo do vetor
    int size = 10;

    //funcao abaixo forca a insercao ser em ordem
    void posicaoCerta(T val){
        bool ok = false;
            int i = 0;
            int b;
            T ver = vet[i];
            while(i < po){
                if(vet[i] > val){
                    ok = true;
                    i++;
                    break;
                }
                else{
                    i++;
                }
            }
            if(ok){
                for (int j = po; j >= i; j--) {
                    vet[j] = vet[j-1];
                    vet[j-1] = val;
            }
        }
    }
public:

    //insere pensando em poucas regras
    void insere(T val){
        if(po < size && po != 0) {
            posicaoCerta(val);
            po++;
        }
        else if(po == 0){
            vet[po] = val;
            po++;
        }
        else{
            puts("JA ESTA CHEIO");
        }
    }

    //busca um indereco de memoria a partir de um valor
    T* buscaEndereco(T val){
        for (int i = 0; i < po; i++) {
            if(val == vet[i]){
                return &vet[i];
            }
        }
        return nullptr;
    }

    //busca a posicao do vetor que tal valor foi inserido
    int buscaIndice(T val){
        for (int i = 0; i < po; i++) {
            if(val == vet[i]){
                return i;
            }
        }
        return NULL;
    }

    //apaga valor escolhido
    void remove(T val){
        if(po == 0){
            puts("ESTA VAZIO O VETOR");
        }
        else{
            bool ok = false;
            int temp = po;
            for (int i = 0; i <= temp; i++) {
                if(vet[i] == val){
                    ok = true;
                    po--;
                }
                else if(ok){
                    vet[i-1] = vet[i];
                }
            }
        }
    }

    void imprime(){
        if(po == 0){
            puts("vetor vazio");
        }
        for (int i = 0; i < po; i++) {
            cout<<vet[i]<<endl;
        }
    }

};


#endif //LISTA_ESTATICA_SEQUENCIAL_LES_LES_HPP
