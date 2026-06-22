#include <stdio.h>
void ordenaponteiros(int **vptr,int n){
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
    int *p = v;
    int **pp = vptr;
    printf("Informe os valores do vetor:");
    while(p < v + n){
         scanf(" %d",p);
         *pp = p;
         p++;
         pp++;
         
    }  
    ordenaponteiros(vptr,n);
    printf("vetor reogarnizado");
    pp = vptr;
    while (pp < vptr + n) {
        printf("%d ", **pp);
        pp++;
    }
     
    
}