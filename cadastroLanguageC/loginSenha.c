//License:Vou deixar o código aqui, se alguém que está iniciando como eu quiser dar uma olhada, 
//até usar esse código, tá certo que não é o melhor que vão achar, nem o melhor jeito de fazer
// (acho eu), mas fazendo um código assim já dá pra começar a entender um pouquinho de C xD (ou não).
//codigo fornecido por:https://forum.imasters.com.br/topic/468071-cadastro-e-login-em-c/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
//-----------------------------------------------------
#define administrador "root"
#define senhaAdministrador "root"
//------------------------------------------------------
void adminLogin();
void menuLogin();
int validaLoginUsuario();
//-----------------------------------------------------
struct cadastrar{
    char usuario[10];
    char senha[10];
    int codigo;
}   
    usuario[1000],
    admin[50],
    cadastrarUsuario[1000],
    cadastrarAdmin[50];
//------------------------------------------------------

//validacao de login usuario
int validaLoginUsuario(int a, int c){
    int r;
    if (strcmp(cadastrarUsuario[a].usuario,usuario[c].usuario)==0)
    {
        /* code */
        r =1; //ja existe usuario;
    }else
    {
        /* code */
        r = 0; //nao existe usuario
        return r;
    }
}
//--------------------------------------------------------------------------------------------------------------

//validacao de login administrador
int validacaoLoginAdmin(int a, int c){
    int r;
    if (strcmp(cadastrarAdmin[a].usuario,admin[c].usuario)==0)
    {
        /* code */
        r=1; //admin ja existe
    }else
    {
        /* code */
        r = 0; //admin nao existe
        return (r);
    }
}
//--------------------------------------------------------------------------------------------------------------    
    
//criar cadastro de  cliente
void cadastroCliente(int a){
    int b,c;
    system("cls");
    usuarioExiste:
    usuario[a].codigo = a+1;
    printf("\n\tCadastro %d", usuario[a].codigo);
    puts("\n\n\tDigite seu login: ");
    printf("\t");
    scanf(" %s", cadastrarUsuario[a].usuario);
    for ( c = 0; c < 1000;c++)
    {
        /* code */
        b = validaLoginUsuario(a,c);
        if(b==1) break;
    }if (b==0)
    {
        /* code */
        memcpy(usuario[a].usuario, cadastrarUsuario[a].usuario,50);
        puts("\tDigite a senha: ");
        printf("\t");
        scanf(" %s", usuario[a].senha);
    }else
    {
        if (b==1)
        {
            /* code */
            printf("\nlogin existente!\n");
            goto usuarioExiste;
        }
    }
    
    
    

}



int main(){
    //char usuario[30];
    char senha[15];

    //printf("Insira seu nome de usuario:\n");
    //scanf("%s",&usuario);

    //printf("Insira sua senha:\n");
    //scanf("%s",&senha);
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