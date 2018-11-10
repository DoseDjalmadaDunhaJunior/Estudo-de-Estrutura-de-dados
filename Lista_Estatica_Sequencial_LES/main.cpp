#include "LES.hpp"

int main() {
    LES<int> oi;
    oi.insere(5);
    oi.imprime();
    oi.insere(4);
    oi.insere(1);
    oi.insere(2);
    oi.insere(3);
    oi.imprime();
    puts("=======================");
    cout<<oi.buscaEndereco(2)<<endl;
    puts("=======================");
    oi.remove(2);
    oi.remove(3);
    oi.imprime();
    return 0;
}