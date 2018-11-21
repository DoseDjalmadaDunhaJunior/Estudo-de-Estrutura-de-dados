#include "Pilha.hpp"
int main() {
    Pilha oi;
    oi.emplilha(1);
    oi.emplilha(2);
    oi.emplilha(3);
    oi.emplilha(4);
    oi.emplilha(5);
    oi.emplilha(4);
    oi.emplilha(5);
    oi.emplilha(4);
    oi.emplilha(5);
    oi.emplilha(4);
    oi.emplilha(5);
    oi.imprime();
    puts("================");
    oi.desempilha();
    oi.desempilha();
    oi.desempilha();
    oi.desempilha();
    oi.desempilha();
    oi.desempilha();
    oi.imprime();
    return 0;
}