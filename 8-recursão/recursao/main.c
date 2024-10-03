#include<stdlib.h>

void imprimir(int x){
     if(x==0){
        printf("%d\n",x);         
     }else{
        printf("%d  ",x);
        imprimir(x-1);      
     }
}

int main(){
    int n=0;
    printf("Digite um numero  ");
    scanf("%d",&n);
    imprimir(n);
}
