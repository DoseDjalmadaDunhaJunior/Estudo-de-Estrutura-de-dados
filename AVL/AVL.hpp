//
// Created by djalma cunha on 25/11/18.
//

#ifndef AVL_MESMO_AVL_HPP
#define AVL_MESMO_AVL_HPP
#include "No.hpp"

template <typename T>
class AVL : public No<T>{
private:
    No<T>* pai;
    void mover(No<T>* oi) {
        if(oi == NULL)
            return;
        mover(oi->esq);
        mover(oi->dir);
        delete oi;
    }

    No<T>* adciona(int x, No<T>* oi)
    {
        if(oi == NULL) {
            oi = new No<T>;
            oi->val = x;
            oi->altura = 0;
            oi->esq = oi->dir = NULL;
        }
        else if(x < oi->val)
        {
            oi->esq = adciona(x, oi->esq);
            if(altura(oi->esq) - altura(oi->dir) == 2)
            {
                if(x < oi->esq->val)
                    oi = RightRotate(oi);
                else
                    oi = doisRightRotate(oi);
            }
        }
        else if(x > oi->val)
        {
            oi->dir = adciona(x, oi->dir);
            if(altura(oi->dir) - altura(oi->esq) == 2)
            {
                if(x > oi->dir->val)
                    oi = LeftRotate(oi);
                else
                    oi = doisLeftRotate(oi);
            }
        }

        oi->altura = max(altura(oi->esq), altura(oi->dir))+1;
        return oi;
    }

    No<T>* RightRotate(No<T>* &oi)
    {
        No<T>* u = oi->esq;
        oi->esq = u->dir;
        u->dir = oi;
        oi->altura = max(altura(oi->esq), altura(oi->dir))+1;
        u->altura = max(altura(u->esq), oi->altura)+1;
        return u;
    }

    No<T>* LeftRotate(No<T>* &oi)
    {
        No<T>* u = oi->dir;
        oi->dir = u->esq;
        u->esq = oi;
        oi->altura = max(altura(oi->esq), altura(oi->dir))+1;
        u->altura = max(altura(oi->dir), oi->altura)+1 ;
        return u;
    }

    No<T>* doisLeftRotate(No<T>* &oi)
    {
        oi->dir = RightRotate(oi->dir);
        return LeftRotate(oi);
    }

    No<T>* doisRightRotate(No<T>* &oi)
    {
        oi->esq = LeftRotate(oi->esq);
        return RightRotate(oi);
    }

    No<T>* menor(No<T>* oi)
    {
        if(oi == NULL)
            return NULL;
        else if(oi->esq == NULL)
            return oi;
        else
            return menor(oi->esq);
    }

    No<T>* maior(No<T>* oi)
    {
        if(oi == NULL)
            return NULL;
        else if(oi->dir == NULL)
            return oi;
        else
            return maior(oi->dir);
    }

    No<T>* remove(int x, No<T>* oi)
    {
        No<T>* temp;
        if(oi == NULL)
            return NULL;
        else if(x < oi->val)
            oi->esq = remove(x, oi->esq);
        else if(x > oi->val)
            oi->dir = remove(x, oi->dir);
        else if(oi->esq && oi->dir)
        {
            temp = menor(oi->dir);
            oi->val = temp->val;
            oi->dir = remove(oi->val, oi->dir);
        }

        else
        {
            temp = oi;
            if(oi->esq == NULL)
                oi = oi->dir;
            else if(oi->dir == NULL)
                oi = oi->esq;
            delete temp;
        }
        if(oi == NULL)
            return oi;

        oi->altura = max(altura(oi->esq), altura(oi->dir))+1;
        if(altura(oi->esq) - altura(oi->dir) == 2)
        {
            if(altura(oi->esq->esq) - altura(oi->esq->dir) == 1)
                return LeftRotate(oi);
            else
                return doisLeftRotate(oi);
        }
        else if(altura(oi->dir) - altura(oi->esq) == 2)
        {
            if(altura(oi->dir->dir) - altura(oi->dir->esq) == 1)
                return RightRotate(oi);
            else
                return doisRightRotate(oi);
        }
        return oi;
    }

    int altura(No<T>* oi)
    {
        if(oi == NULL){
            return -1;
        }
        else{
            return oi->altura;
        }

    }

    void RED(No<T>* oi){
        if(oi == NULL)
            return;
        cout << oi->val << " ";
        RED(oi->esq);
        RED(oi->dir);
    }
    void ERD(No<T>* oi)
    {
        if(oi == NULL)
            return;
        ERD(oi->esq);
        cout << oi->val << " ";
        ERD(oi->dir);
    }

public:
    AVL()
    {
        pai = NULL;
    }

    void adciona(int x)
    {
        pai = adciona(x, pai);
    }

    void remove(int x)
    {
        pai = remove(x, pai);
    }

    void ERD()
    {
        ERD(pai);
        puts("");
    }

    void RED(){
        RED(pai);
        puts("");
    }
};


#endif //AVL_MESMO_AVL_HPP
