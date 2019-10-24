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
    char user[10];
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
    if (strcmp(cadastrarUsuario[a].user,usuario[c].user)==0)
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
    if (strcmp(cadastrarAdmin[a].user,admin[c].user)==0)
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
    scanf(" %s", cadastrarUsuario[a].user);
    for ( c = 0; c < 1000;c++)
    {
        /* code */
        b = validaLoginUsuario(a,c);
        if(b==1) break;
    }if (b==0)
    {
        /* code */
        memcpy(usuario[a].user, cadastrarUsuario[a].user,50);
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

void cadastrodAdministrador(int a){
    int b,c;
    system("cls");
    adminExiste:
    admin[a].codigo = a+1;
    printf("\n\tCadastro %d",admin[a].codigo);
    puts("\n\n\tDigite o login: ");
    printf("\t");
    scanf(" %s", cadastrarAdmin[a].user);
    for ( c = 0; c < 50; c++)
    {
        /* code */
        b = validacaoLoginAdmin(a,c);
        {
            /* code */
            if (b==1) break;
        }if (b==0)
        {
            /* code */
            memcpy(admin[a].user, cadastrarAdmin[a].user,50);
            puts("\tDigite a senha: ");
            printf("\t");
            scanf(" %s", admin[a].senha);
        }else if (b==1)
        {
            /* code */
            printf("\nLogin Existente!\n");
            goto adminExiste;
        } 
    }
}
//--------------------------------------------------------------------------------------------------------------

void logarUsuario(){
    int c;
    int logado;
    char login[1][20], senha[1][20];
    char fecharLogin[] = {"Exit"}, fecharSenha[] = {"EXIT"};
    
    erroLogin:

    printf("\n\tLogon\n ");
    printf("\n\tLogin: ");
    scanf(" %s", login[0]);
    printf("\n\tSenha: ");
    scanf(" %s",senha[0]);

    if ((strcmp(login[0],fecharLogin)==0)&&(strcmp(senha[0],fecharSenha)==0))
    {
        /* code */
        exit(0);
    }else
    {
        /* code */
        for ( c = 0; c < 1000; c++)
        {
            /* code */
            if((strcmp(login[0],usuario[c].user)!=0) || (strcmp(senha[0],usuario[c].senha))){
                logado =1; //login e/ou senha incorretos
            }else
            {
                /* code */
                if((strcmp(login[0],usuario[c].user)==0) &&(strcmp(senha[0],usuario[0].senha))){
                    logado = 2; //logado com sucesso
                    break;
                }
            }if (logado==1)
            {
                /* code */
                system("cls");
                printf("\nLogin e /ou senha incorreta(s)\n");
                printf("\nTry Again\n");
                goto erroLogin;
            }else if (logado==2)
            {
                /* code */
                system("cls");
                printf("\nLogado com sucesso!\nWelcome to %s\n",login[0]);
                printf("Codigo de usuario:  %d\n\n",usuario[c].codigo);
                logarUsuario();
            }
        }   
    }
}

void loginUsuario(){
    int opUser;
    telaInicialUser:
        printf("\n\t9- Voltar para tela inicial de login");
        printf("\n\t0- Fechar\n\t");
        scanf("%d" ,&opUser);

        if (opUser==9){
            system("cls");
            menuLogin();}else
            /* code */
            if (opUser==0) exit(0);
            else{system("cls"); 
            printf("\n\nOpcao Invalida\n");
            goto telaInicialUser;}
}

void logarAdmin(){
    int c;
    int logado;
    char login[1][20], senha[1][20];
    char fecharLogin[] = {"EXIT"}, fecharSenha[] =  {"EXIT"};

    erroLogin:

    printf("\n\tPara fechar digite o usuario e a senha EXIT em maiusculo\n");
    printf("\n\tLogon\n");
    printf("\n\tLogin: ");
    printf(" %s", login[0]);
    printf("\n\tSenha: ");
    scanf(" %s",senha[0]);

    if((strcmp(login[0],administrador)==0)&&(strcmp(login[0],senhaAdministrador)==0)) logado ==2;
    else if ((strcmp(login[0],fecharLogin)==0)&&(strcmp(senha[0],fecharSenha)==0)) exit(0);
    else
    {
        /* code */
        for ( c = 0; c < 1000; c++)
        {
            /* code */
            if ((strcmp(login[0],admin[c].user)!=0) || (strcmp(senha[0],admin[c].senha)==0)){
                logado =1;  //login e/ou senha incorretos
            }else if ((/* condition */ strcmp(login[0],admin[c].user)==0) && (strcmp(senha[0],admin[c].senha)==0))
            {
                /* code */
                logado ==2; //logado com sucesso
                break;
            }
        }
        
    }

        if(logado ==1){
            system("cls");
            printf("\nLogin e/ou senha incorreto(s)\n");
            printf("\nTry again!\n");
            goto erroLogin;
        }else if (logado ==2){
            system("cls");
            printf("\n\tLogado com sucesso!\n\n\tBem vindo(a)[ADM]%s\n",login[0]);
            // printf("Codigo do ADMIN: %d\n\n",admin[c].codigo);
            loginAdmin();
        }
    
}

void loginAdmin(){
    int opAdmin;
    int a=0,adminCadastro=0,b,c,nc;

    telaInicialAdmin:
        printf("\n\t1- Cadastro de Usuarios\n");
        printf("\n\t2- Cadastro de administradores\n");
        printf("\n\t9- Voltar para tela de login\n");
        printf("\n\t0- Fechar\n");
        printf("\t");
        scanf("%d", &opAdmin);
        system("cls");
        if (/* condition */ opAdmin==1)
        {
            /* code */
            printf("\nQuantidade de cadastros a fazer? \n");
            scanf("%d",&nc);
            if (/* condition */a==0)
            {
                /* code */
                for ( a = 0; a < nc; a++)
                {
                    /* code */
                    cadastroCliente(a);
                }
                goto telaInicialAdmin;
            }
            else if (/* condition */a!=0)
            {
                /* code */
                b = a;
                c = a+nc-1;
                printf("\n%d\n",a);
                for ( a = b; a <= c; a++)
                {
                    /* code */
                    cadastroCliente(a);
                }
                goto telaInicialAdmin;
            }
        }
        else if (/* condition */ opAdmin ==2)
        {
            /* code */
            printf("\nQuantidade de cadastros a fazer? \n");
            scanf("%d", &nc);
            if(adminCadastro==0){
                for (adminCadastro = 0; adminCadastro < nc; adminCadastro++)
                {
                    /* code */
                    cadastrodAdministrador(adminCadastro);
                }
                goto telaInicialAdmin;
            }else if (/* condition */ adminCadastro!=0)
            {
                /* code */
                b = adminCadastro;
                c = adminCadastro+nc-1;
                printf("\n%d\n",a);
                for ( adminCadastro = b; adminCadastro <= c; adminCadastro++)
                {
                    /* code */
                    cadastrodAdministrador(adminCadastro);
                }
                goto telaInicialAdmin;
            }
        }
        else if (opAdmin ==0) exit(0);
        else if (opAdmin ==9) menuLogin();
}

void menuLoginInicial(){
    int opLogin;

    menuDeLogin:
    printf("1- Login de USUARIO\n");
    printf("2- Login de ADMINISTRADOR\n");
    printf("0- FECHAR\n");
    scanf(" %d",&opLogin);
    if(opLogin ==1) logarUsuario();
    else if (opLogin==2) logarAdmin();
    else if (opLogin==0) exit(0);
    else{
        system("cls");
        printf("Opcao invalida!\n");
        goto menuDeLogin;
    }
}

int main(void){
    menuLoginInicial();

/*    //char usuario[30];
    char senha[15];

    //printf("Insira seu nome de usuario:\n");
    //scanf("%s",&usuario);

    //printf("Insira sua senha:\n");
    //scanf("%s",&senha);
    int tentativas =0;
    if (strcmp(usuario, "rodrigo")==0)
    {
        // code 
        if (strcmp(senha,"321")==0)
        {
            // code
            printf("\nBem-Vindo.Login Aceito com sucesso!");
        }else
        {
            // code 
            printf("\nsenha invalida");
            tentativas++;
        }
        
    }else
    {
        printf("usuario nao existe");
    }
    */
    return 0;
}