//
// Created by Usuario on 21/04/2021.
//

#ifndef BOOTH_ALGORITHM_BOOTH_ALGORITHM_H
#define BOOTH_ALGORITHM_BOOTH_ALGORITHM_H


class booth_algorithm{
public:
    booth_algorithm();
    int modulo(int a, int n);
    int entrada(int a);
    void suma(int *a, int *b);
    void binario(int x, int *arreglo);
    void cambiuo(int posX, int *posY);
    void tabla(int a, int b, int  Q[4], int M[4]);
    ~booth_algorithm();
};

#endif //BOOTH_ALGORITHM_BOOTH_ALGORITHM_H
