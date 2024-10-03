#include<stdlib.h>

int fatorial(int x){
     if(x<=1){
        return 1; 
     }else{
        return x * fatorial(x-1);      
     }
}

int main(){
    int n=5;
    printf("Fatorial de %d: %d\n",n,fatorial(n));
    system("PAUSE"); 
}
