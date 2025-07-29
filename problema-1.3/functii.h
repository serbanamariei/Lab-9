#ifndef FUNCTII_H_
#define FUNCTII_H_

int **citire(int n, int m);
void dealocare(int **a, int n, int m);
void afisare(int **a, int n, int m);
void ordonare(int **a, int n, int m);
int maxim(int *a, int m);
void interschimbareLinii(int **a, int n, int m, int x, int y);
void interschimbareCol(int **a, int n, int m, int x, int y);
void primaCol(int **a, int n);
void primaLinie(int **a, int n);
void diagP(int **a, int n, int m);
int **copie(int **a, int n, int m);
void diagS(int **a, int n, int m);
void linieV(int **a, int n, int m);

#endif
