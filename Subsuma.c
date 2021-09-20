#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int sumaSubMax1 (int v[]){
    int i, j;
    int sumaMax = 0;
    int estaSuma;
    for (i = 0; i < N; i++){
        estaSuma = 0;
        for (j = i; j < N; j++){
            estaSuma = estaSuma + v[j];
            if (estaSuma > sumaMax) sumaMax = estaSuma;
        }
    }
    return sumaMax;
}

int sumaSubMax2 (int v[]){
    int i;
    int sumaMax = 0;
    int estaSuma = 0;
    for (i = 0; i < N; i++){
        estaSuma = estaSuma + v[i];
        if (estaSuma > sumaMax){
            sumaMax = estaSuma;
        }
        else if (estaSuma < 0){
            estaSuma = 0;
        }
    }
    return sumaMax;
}void inicializar_semilla(){
    srand(time(NULL));
}

void aleatorio(int v[]){
    int i;
    int m = 2 * N + 1;
    for (i = 0; i < N; i++){
        v[i] = (rand() % m) - N;
    }
    printf("\n");
}

void listar_vector(int v[]){
    int i;
    for (i = 0; i < N; i++){
        printf(" %d ", v[i]);
    }
    printf("\n");
}

void test1(){
    int x, y;
    int v[] = {7, 7, -5, -7, 6};
    printf("\ntest1\n");
    printf("%30s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    listar_vector(v);
    x = sumaSubMax1(v);
    y = sumaSubMax2(v);
    printf("%26s%15d%15d\n", "", x, y);
}

void test2(){
    int i, x, y;
    int v[N];
    printf("\ntest2\n");
    printf("%30s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    for (i = 0; i < N; i++){
        aleatorio(v);
        listar_vector(v);
        x = sumaSubMax1(v);
        y = sumaSubMax2(v);
        printf("%26s%15d%15d\n", "", x, y);
    }
}

int main(){
    
    inicializar_semilla();
    test1();
    test2();

    return 0;
}