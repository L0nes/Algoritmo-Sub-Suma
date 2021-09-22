#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>


double microsegundos() { /* obtiene la hora del sistema en microsegundos */
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

int sumaSubMax1 (int v[], int N){
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

int sumaSubMax2 (int v[], int N){
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

void aleatorio(int v[], int N){
    int i;
    int m = 2 * N + 1;
    for (i = 0; i < N; i++){
        v[i] = (rand() % m) - N;
    }
    printf("\n");
}

void listar_vector(int v[], int N){
    int i;
    for (i = 0; i < N; i++){
        printf(" %d ", v[i]);
    }
    printf("\t");
}

void test1(){
    int x, y,k;
    int v[] = {7, 7, -5, -7, 6};
    printf("\ntest1\n");
    printf("%30s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    k= sizeof(v)/ sizeof(int);
    listar_vector(v,k);
    x = sumaSubMax1(v,k);
    y = sumaSubMax2(v,k);
    printf("%15d%15d\n\n", x, y);
}

void test2(){
    int i, x, y,N=5;
    int v[N];
    printf("test2\n");
    printf("%30s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    for (i = 0; i < N; i++){
        aleatorio(v,N);
        listar_vector(v,N);
        x = sumaSubMax1(v,N);
        y = sumaSubMax2(v,N);
        printf("%15d%15d\n", x, y);
    }
}
void test_propio(){
    int x, y,k,v[5],w[30]={-9,2,-5,-4,6,4,0,9,2,5,-2,-1,-9,-7,-1,9,-2,1,-7,-8,15,-2,-5,-4,16,7,-5,6,7,-7},cont=0,cont2=0;
    printf("\ntest2\n");
    printf("%30s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");

    while(cont>=0 && cont<30){
        while(cont2<5) {
            v[cont2]=w[cont];
            cont2++;
            cont++;
        }
        cont2=0;
        k= sizeof(v)/ sizeof(int);
        listar_vector(v,k);
        x = sumaSubMax1(v,k);
        y = sumaSubMax2(v,k);
        printf("%15d%15d\n", x, y);

    }
}
void test_recursivo_n(){
    int v[32000],c[7]={500,1000,2000,4000,8000,16000,32000},i,j,var;
    double a,b;
    for(i=0;i<7;i++) {
        for (j = 0; j < 6; j++) {
            if(c[i]>510) {
                printf("sec %d %d\t", j, c[i]);
                aleatorio(v, c[i]);
                a = microsegundos();
                //printf("%f\t", a = microsegundos());
                var = sumaSubMax1(v, c[i]);
                b = microsegundos();
                //printf("%f\t", b = microsegundos());
                printf("%f\t", b - a);
                printf("%d\n", var);
            }
            else{
                printf("sec %d %d\t", j, c[i]);
                a = microsegundos();
                //printf("%f\t", a = microsegundos());
                for (int i = 0; i < 10; ++i) {
                    aleatorio(v,c[i]);
                    var = sumaSubMax1(v, c[i]);
                }
                b = microsegundos();
                printf("%f\t", (b - a));
                printf("%d\n", var);
            }
        }
    }
}
int main(){

    inicializar_semilla();
/*    test1();
    test2();
    test_propio();*/
    test_recursivo_n();

    return 0;
}





 //*/
 /*
int sumaSubMax1 (int v[]){
    int i, j,N=sizeof(v)/ sizeof(int);
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
    int i, sumaMax = 0, estaSuma = 0,N=sizeof(v)/ sizeof(int);
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
    int i,N=sizeof(v)/ sizeof(int), m = 2 * N + 1;
    for (i = 0; i < N; i++){
        v[i] = (rand() % m) - N;
    }
    printf("\n");
}

void listar_vector(int v[]){
    int i,N= strlen(v),K= sizeof(v)/sizeof (int);
    for (i = 0; i < N; i++){
        printf(" %d ", v[i]);
    }
    printf("\t");
}

void test1(){
    int x, y;
    int v[] = {7, 7, -5, -7, 6};
    int k= sizeof(v)/ sizeof(int);
    printf("\ntest1\n");
    printf("%30s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    listar_vector(v);
    x = sumaSubMax1(v);
    y = sumaSubMax2(v);
    printf("%15d%15d\n\n", x, y);
}

void test2(){
    int i, x, y,N=5;
    int v[N];
    printf("test2\n");
    printf("%30s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    for (i = 0; i < N; i++){
        aleatorio(v);
        listar_vector(v);
        x = sumaSubMax1(v);
        y = sumaSubMax2(v);
        printf("%15d%15d\n", x, y);
    }
}
void test_propio(){
    int i, x, y,v[5],w[30]={-9,2,-5,-4,6,4,0,9,2,5,-2,-1,-9,-7,-1,9,-2,1,-7,-8,15,-2,-5,-4,16,7,-5,6,7,-7},cont=0,cont2=0;
    printf("\ntest2\n");
    printf("%30s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");

    while(cont>=0 && cont<30){
        while(cont2<5) {
            v[cont2]=w[cont];
            cont2++;
            cont++;
        }
        cont2=0;
        listar_vector(v);
        x = sumaSubMax1(v);
        y = sumaSubMax2(v);
        printf("%15d%15d\n", x, y);

    }
}
//*/
