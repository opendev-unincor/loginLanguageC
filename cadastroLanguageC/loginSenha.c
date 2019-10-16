#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

int main(){
    char usuario[30];
    char senha[15];

    printf("Insira seu nome de usuario:\n");
    scanf("%s",&usuario);

    printf("Insira sua senha:\n");
    scanf("%s",&senha);
    int tentativas =0;
    if (strcmp(usuario, "rodrigo")==0)
    {
        /* code */
        if (strcmp(senha,"321")==0)
        {
            /* code */
            printf("\nBem-Vindo.Login Aceito com sucesso!");
        }else
        {
            /* code */
            printf("\nsenha invalida");
            tentativas++;
        }
        
    }else
    {
        printf("usuario nao existe");
    }
    
    return 0;
}