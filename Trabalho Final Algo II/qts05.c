#include <stdio.h>
void tamanhoCollatz(int n,int *maiorp,int *n_maiorp){
    int temp,cont=0;
    FILE *arquivo = fopen("arquivo.txt","w");
    for (int i = 1; i <= n; i++)
    { 
        fprintf(arquivo, " \n %d: -> %d",i,i);
        cont =1;
        temp =i;
        while (temp > 1)
        {

          if (temp%2  ==0)
          {
            temp = temp/2;
          }else{
            temp = (temp*3)+1;
          }
          cont++;
          if (temp==1)
          {
            fprintf(arquivo," -> %d",temp);
            break;
          }
          fprintf(arquivo," -> %d",temp);
            
        }
        if(cont > *maiorp){
            *maiorp = cont;
            *n_maiorp = i;
        }
        
        
    }
    fclose(arquivo);
    
}
int main(){
    int n,maior=0,n_maior;
    do
    {
        printf("informe um número inteiro e positivo ");
        scanf(" %d",&n);
    } while (n>100000 || n < 1);
   tamanhoCollatz(n,&maior,&n_maior);
   printf("maior sequencia %d \n n %d",maior,n_maior);

    
}