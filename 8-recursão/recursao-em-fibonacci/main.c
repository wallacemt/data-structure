#include<stdlib.h>

int fibonacci(int x){
     if(x==1||x==0){
        return x; 
     }else{
        return fibonacci(x-1) + fibonacci(x-2);      
     }
}

int main(){
    int n=5;
    printf("Fibonacci de %d:\n",n);
    printf("%d\n",fibonacci(n-1)); 
}
