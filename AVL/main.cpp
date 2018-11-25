#include"AVL.hpp"
int main()
{
    AVL<int> oi;
    oi.adciona(1);
    oi.adciona(99);
    oi.adciona(88);
    oi.adciona(-5);
    oi.adciona(0);
    oi.adciona(-7);
    cout<<"ERD"<<endl;
    oi.ERD();
    cout<<"RED"<<endl;
    oi.RED();

    puts("tira 0");
    oi.remove(0);
    oi.ERD();
    oi.RED();
    return 0;
}