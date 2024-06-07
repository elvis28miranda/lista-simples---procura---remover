#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int codigo;
    char nome[30];
    struct no *next;
} no;

struct no *inicio,*corrente,*auxiliar;


void Show()
{
   if(inicio == NULL)
   {
       printf("\n  >>>>>>>>  Lista vazia <<<<<<<<<<<<");
       printf("\n\n");
       system("pause");

   }else{
            auxiliar = inicio;

            while (auxiliar != NULL)
            {
                printf("\n Codigo ==> : %d",auxiliar->codigo);
                printf("\n Nome ===>  : %s",auxiliar->nome);
                auxiliar = auxiliar->next;
            }
            system("pause");
   }
   system("cls");
}
void Enterdata()
{
    printf("\n Informe o Codigo");
    scanf("%d",&corrente->codigo);

    printf("\n Informe o Nome");
    scanf("%s",&corrente->nome);

}
/*----------------------------------------- Feito no dia 06/03 ------------------------------------------------*/

void Insert()
{
    if(inicio == NULL)
    {
        corrente=(no*)malloc(sizeof(no));
        inicio = corrente;
        auxiliar = corrente;
        corrente->next = NULL;
        Enterdata();
    }
    else
    {
        corrente=(no*)malloc (sizeof(no));
        auxiliar->next = corrente;
        corrente->next = NULL;
        auxiliar = corrente;
        Enterdata();
    }
}

void search ()
{
    int achou, k;

    char xnome[30];
    k=0;
    achou=0;

    if(inicio == NULL)
    {
        printf("\n Lista vazia: ");
        system("pause");
    }
    else
    {

        printf("\n Informe o nome a ser procurado: ");
        scanf("%s",xnome);
        auxiliar = inicio;

        while(auxiliar != NULL)
        {
            k++;
            if(strcmp(xnome,auxiliar->nome)==0)
            {
              printf("\n o registro foi encontrado a lista %d", k);
              system("pause");
              achou = 1;
              break;

            }else
            {
            auxiliar = auxiliar -> next;
            }
            if(achou ==0)
            {
            printf("\n Registro não consta na Lista");
            system("pause");
        }
    }
}

void Rem()
{
    int achou;
    char xnome[30];

    if (inicio == NULL)
    {
        printf("\n Lista vazia, tente novamente");
        system ("pause");
    }
    else
    {

            printf("\n Informe o nome a ser procurado");
            scanf("%s", xnome);
            auxiliar = inicio;

            if(strcmp(auxiliar->nome,xnome)==0)
                {
                    inicio = inicio -> next;
                    free(auxiliar);
                    printf("\n Removido o primeiro elemento da lista");
                    system("pause");
                    achou = 1;

                }else{
                    corrente = auxiliar;
                    auxiliar = auxiliar -> next;

                    while(auxiliar != NULL)
                    {
                        if(strcmp(auxiliar->nome,xnome)==0)
                        {
                            corrente -> next = auxiliar -> next;
                            free(auxiliar);
                            printf("\n Registro removido no meio ou fim da lista");
                            system("pause");
                            achou = 1;
                            break;
                        }else{

                            auxiliar = auxiliar -> next;
                            corrente = corrente -> next;

                        }
                    }
            }
        }
        if(achou  == 0 )
        {
            printf("\n Registro não consta na Lista");
            system("pause");
        }

}


/*----------------------------------------- Feito no dia 06/03 ------------------------------------------------*/

int main()
{
    corrente = NULL;
    inicio = NULL;
    auxiliar = NULL;

    int op;

    do
    {
        printf("\n ******** Lista Simplesmente Encadeada *********");
        printf("\n [1] Inserindo Registo na Lista ");
        printf("\n [2] Exibindo os Registros na Lista");
        printf("\n [3] Pesquisa os Registros na Lista");
        printf("\n [4] Removendo Registros da Lista ");

        printf("\n Escolha a Opção...");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            Insert ();
            break;
        case 2:
            Show ();
            break;
        case 3:
            Search ();
            break;
        case 4:
            Rem ();
            break;

        default :

            printf("\n Função não encontrada.. tente novamente");
            system("pause");
        }

    }while (op != 5);

    system("cls");
    printf("\n Final de processamento");
    system("pause");

}
