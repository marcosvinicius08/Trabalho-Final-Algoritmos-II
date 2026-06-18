#include <stdio.h>
void ordenavetor(int **vptr,int n){
    int **x;
     x = vptr + n - 1;
    
    while(vptr <x){
        int **aux;
        aux= vptr + 1;
        while(aux <= x){
            int *temp;
            if (**vptr > **aux)
            { 
               temp = *aux;
               *aux = *vptr;
               *vptr = temp;
                
            }
            aux++;
            
        }
        vptr++;
         
    }
    
}
int main(){
    int n=5,v[5];
    int *vptr[5];
    printf("Informe os valores do vetor:");
    for(int i =0;i<5;i++){
         scanf(" %d",&v[i]);
         vptr[i] = &v[i];
    }  
    ordenavetor(vptr,n);
    printf("vetor reogarnizado");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",*(vptr[i]));
       
    }
     
    
}