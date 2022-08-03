#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void st(char* s,char* str){
    char* start = s;
    char* temp = s;
    char* su = str;
    int count=0;
    while (*temp) {
        temp++;
        if (*temp == '\0') {
            printf("\n");
        }
        if (*temp == *su) {
            printf("Found");
        } 
    }
}
int main(int argc, char const *argv[]){
    char str[100],s[100];
    printf("Enter The String : ");
    scanf("%s",&str);
    printf("search : ");
    scanf("%s",&s);
    st(str,s);


    return 0;
}
