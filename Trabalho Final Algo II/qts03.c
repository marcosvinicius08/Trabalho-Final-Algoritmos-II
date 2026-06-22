#include <stdio.h>

int contaDigitos(int n){
    int cont = 0;

    if(n == 0)
        return 1;

    while(n > 0){
        cont++;
        n = n / 10;
    }

    return cont;
}

void numeroParaVetor(int v[], int tam, int n){
    int i;

    for(i = tam - 1; i >= 0; i--){
        v[i] = n % 10;
        n = n / 10;
    }
}

void casamento(int a, int b, int *resA, int *resB){

    int tamA = contaDigitos(a);
    int tamB = contaDigitos(b);
    int tamMax;

    if(tamA > tamB){
        tamMax = tamA;
    }else{
        tamMax = tamB;
    }
    int vA[20] = {0};
    int vB[20] = {0};

    numeroParaVetor(vA + (tamMax - tamA), tamA, a);
    numeroParaVetor(vB + (tamMax - tamB), tamB, b);

    *resA = 0;
    *resB = 0;

    int sobrouA = 0;
    int sobrouB = 0;

    int i;

    for(i = 0; i < tamMax; i++){

        if(vA[i] > vB[i]){
            *resA = (*resA * 10) + vA[i];
            sobrouA = 1;
        }
        else if(vB[i] > vA[i]){
            *resB = (*resB * 10) + vB[i];
            sobrouB = 1;
        }
        else{
            *resA = (*resA * 10) + vA[i];
            *resB = (*resB * 10) + vB[i];

            sobrouA = 1;
            sobrouB = 1;
        }
    }

    if(sobrouA != 1)
        *resA = -1;

    if(sobrouB != 1)
        *resB = -1;
}

int main(){

    int A, B;
    int rA, rB;
         
    printf("Digite o numero A:\n");
    scanf("%d", &A);
    printf("Digite o numero B:\n");
    scanf("%d", &B);

    casamento(A, B, &rA, &rB);

    printf("Resultado:\n");
    if(rA <= rB)
        printf("%d %d\n", rA, rB);
    else
        printf("%d %d\n", rB, rA);

    return 0;
}