#include "Common_Vector.h"
#include "Alhorithms.h"
/*Comment*/
#define NEXT_INDICES(i, j, m) do { if (i == m - 1) i = 0, j += 1; else i += 1; } while (0)
/*Comment*/
#define PREV_INDICES(i, j, m) do { if (i == 0) i = m - 1, j -= 1; else i -= 1; } while (0)
/*Comment
Comment*/
/*
===================================================================
==============================Select2==============================
===================================================================
*/
clock_t select2(int ***Arr3D, int P, int M, int N) {
    int imin, jmin, tmp, Si = 0, Sj = 0;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int k = 0; k < P; k++) {/*comment*/ 
        for(int s = 0; s <= N * M - 1; s++) {/*comment*/ 
            imin = Si;
            jmin = Sj;
            for(int i = imin + 1; i < M; i++) {/*comment*/ 
                if(Arr3D[k][i][jmin] <= Arr3D[k][imin][jmin]) {
                    imin = i;
                }
            }
            for(int j = jmin + 1; j < N; j++) {/*comment*/
                for(int i = 0; i < M; i++) {
                    if(Arr3D[k][i][j] <= Arr3D[k][imin][jmin]) {
                        imin = i;
                        jmin = j;
                    }
                }
            }
            /*comment
            comment*/
            tmp = Arr3D[k][imin][jmin];
            Arr3D[k][imin][jmin] = Arr3D[k][Si][Sj];
            Arr3D[k][Si][Sj] = tmp;
            Si++;
            if(Si == M) {/*comment*/
                Si=0;
                Sj++;
            }
        }
        /*comment*/
        Si = 0;
        Sj = 0;
    }
    time_stop = clock();
    return time_stop - time_start;
}
/*comment*/
clock_t vector_select_2(int *A, int N) {
    int imin, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int s = 0; s< N - 1; s++) {
        imin = s;
        for(int i = s + 1; i < N; i++) {
            if (A[i] < A[imin]) {imin = i;}
        }
            
        tmp = A[imin];
        A[imin] = A[s];
        A[s] = tmp;
    }
    time_stop = clock();
    return time_stop - time_start;
}

/*
===================================================================
==============================Select8==============================
===================================================================
*/
clock_t select8(int ***Arr3D, int P, int M, int N) {
    int imax, imin, jmax, jmin, i, j, k, tmp, l_i, l_j, r_i, r_j;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int k = 0; k < P; ++k) {
        l_i = 0, l_j = 0, r_i = M - 1, r_j = N - 1;

        while (l_j < r_j || l_j == r_j && l_i < r_i) {

            imin = l_i,/*comment*/
            jmin = l_j;/*comment*/

            imax = l_i,/*comment*/
            jmax = l_j;/*comment*/

            i = l_i;/*comment*/
            j = l_j;/*comment*/

            do {
                NEXT_INDICES(i, j, M);/*comment*/
                                      /*comment*/
                if (Arr3D[k][i][j] < Arr3D[k][imin][jmin]) {/*comment*/
                
                    imin = i;
                    jmin = j;
                }
                else {
                    if (Arr3D[k][i][j] > Arr3D[k][imax][jmax]) {/*comment*/
                    
                        imax = i;
                        jmax = j;
                    }
                }
            }while (i != r_i || j != r_j);
            /*comment
            comment*/
            if (imin != l_i || jmin != l_j) {
                tmp = Arr3D[k][imin][jmin];
                Arr3D[k][imin][jmin] = Arr3D[k][l_i][l_j];
                Arr3D[k][l_i][l_j] = tmp;
            }
            if (imax != r_i || jmax != r_j) {
                if (imax == l_i && jmax == l_j) {
                    tmp = Arr3D[k][imin][jmin];
                    Arr3D[k][imin][jmin] = Arr3D[k][r_i][r_j];
                    Arr3D[k][r_i][r_j] = tmp;
                }
                else {
                    tmp = Arr3D[k][imax][jmax];
                    Arr3D[k][imax][jmax] = Arr3D[k][r_i][r_j];
                    Arr3D[k][r_i][r_j] = tmp;
                }
            }
            /*comment*/
            NEXT_INDICES(l_i, l_j, M);/*comment*/
            PREV_INDICES(r_i, r_j, M);/*comment*/
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}
/*comment*/
clock_t vector_select_8(int *A, int N)
{
    int L, R, imin, imax, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    L = 0;
    R = N - 1;
    while (L < R) {
        imin = L;
        imax = L;
        for(int i = L + 1; i < R + 1; i++) {
            if (A[i] < A[imin]) {imin = i;}
            else if (A[i] > A[imax]) {imax = i;}
        }
        if (imin != L) {
            tmp = A[imin];
            A[imin] = A[L];
            A[L] = tmp;
        }
        if (imax != R) {            
            if (imax == L) {
                tmp = A[imin];
                A[imin] = A[R];
                A[R] = tmp;
            }
            else {
                tmp = A[imax];
                A[imax] = A[R];
                A[R] = tmp;
            }
        }
        L = L + 1;
        R = R - 1;
    }
    time_stop = clock();
    return time_stop - time_start;
}

/*
===================================================================
==============================Exchange1==============================
===================================================================
*/
clock_t exchange1(int ***Arr3D, int P, int M, int N) {
    int tmp, i, j, k, limit, Ri, Rj;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int k = 0; k < P; k++) {
        /*comment*/
        for(int Rj = N - 1; Rj >= 0; Rj--) {
            /*comment*/
            for(int R = M; R > 0; R--) {
                /*comment*/
                for(int j = 0; j <= Rj; j++) {
                    /*comment*/
                    limit = M;  /*comment*/
                    if(j == Rj) limit = R;  /*comment*/
                    for(int i = 0; i < limit; i++) {
                        if(i == M - 1 && j + 1 < N) {
                            /*comment*/
                            if(Arr3D[k][i][j] > Arr3D[k][0][j + 1]) {
                                tmp = Arr3D[k][i][j];
                                Arr3D[k][i][j] = Arr3D[k][0][j + 1];
                                Arr3D[k][0][j + 1] = tmp;
                            }
                        }
                        else {
                            if(i != M - 1); {/*comment*/
                                if(Arr3D[k][i][j] > Arr3D[k][i + 1][j]) {
                                    tmp = Arr3D[k][i][j];
                                    Arr3D[k][i][j] = Arr3D[k][i + 1][j];
                                    Arr3D[k][i + 1][j] = tmp;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}

/*comment*/
clock_t vector_exchange_1(int *A, int N)
{
    int tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int R = N - 1; R > 0; R--) {
        for(int i = 0; i < R; i++) {            
            if (A[i] > A[i+1]) {
                tmp = A[i];
                A[i] = A[i+1];
                A[i+1] = tmp;
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}
