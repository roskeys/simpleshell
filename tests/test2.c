#include<stdio.h>
#include<string.h>
int main(){
    char data[] = "test";
    char test[] = "test";
    if (strcmp(data,test)==0){
        printf("test is 0 %d", strcmp(data,test));
    }
}