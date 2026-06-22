#include <stdio.h>

void inverterEdeslocar(int *vet, int n, int k){
    int i, j, aux, ultimo;

    for(i=0; i<(n/2); i++){
        aux = *(vet + i);
        *(vet + i) = *(vet + n - 1 - i);
        *(vet + n - 1 - i) = aux;
    }

    k = k % n;

    for(i = 0; i < k; i++){

        ultimo = *(vet + n - 1);
        
        for(j = n-1; j > 0; j--){

            *(vet + j) = *(vet + j - 1);

        }
        *(vet) = ultimo;
    }

}

int main() {
    int n, k, i;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);

    while(n <= 0){
        printf("Tamanho invalido. Digite novamente:\n");
        scanf("%d", &n);
    }

    int vet[n];

    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    printf("Digite o valor de K:\n");
    scanf("%d", &k);

    printf("Vetor antes de ser invertido e deslocado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }

    inverterEdeslocar(vet, n, k);

    printf("\nVetor depois de ser invertido e deslocado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }

    return 0;

}