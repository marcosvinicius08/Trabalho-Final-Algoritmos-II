#include <stdio.h>

void troca(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

int tamanhoNumero(int *vet){

    int i = 0;

    while(*(vet + i) != -1){
        i++;
    }

    return i;
}

void maiorNumero(int *vet, int tam, int t){

    int i, j;
    int maior, posMaior;

    for(i = 0; i < tam && t > 0; i++){

        maior = *(vet + i);
        posMaior = i;

        for(j = tam - 1; j > i; j--){

            if(*(vet + j) > maior){

                maior = *(vet + j);
                posMaior = j;

            }
        }

        if(posMaior != i){

            troca(vet + i, vet + posMaior);

            t--;
        }
    }
}

int main(){

    int vet[41];
    int t;
    int i, tam;

    printf("Digite os digitos do numero separados por espaco:\n");
    printf("Digite -1 para terminar o numero.\n");

    i = 0;


    while(i < 40){

        scanf("%d", &vet[i]);

        if(vet[i] == -1){
            break;
        }
 
            i++;
    }

    vet[i] = -1;

    tam = tamanhoNumero(vet);

    printf("Digite T:\n");
    scanf("%d", &t);

    if(tam == 1 && vet[0] == 0 && t == 0){ 
        return 0; 
    }

    maiorNumero(vet, tam, t);

    printf("Maior numero possivel:\n");

    for(i = 0; i < tam; i++){
        printf("%d", vet[i]);
    }

    printf("\n");

    return 0;
}