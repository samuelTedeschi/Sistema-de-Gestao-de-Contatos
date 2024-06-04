#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*defini�oes de constantes*/

#define MAX_CONTATOS 100
#define TAM_NOME 50
#define TAM_EMAIL 50
#define TAM_TELEFONE 15
#define FILENAME "contatos.txt" /*estrutura para armazenar o contato*/

typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
} Contato;

Contato contatos[MAX_CONTATOS];
int numContatos = 0;

/*Fun�ao salvar contatos*/
void salvarContatos(){
    FILE *file = fopen(FILENAME, "w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo.:( \n");
        return;
    }

    fwrite(&numContatos, sizeof(int), 1, file);
    fwrite(contatos, sizeof(Contato), numContatos, file);
    fclose(file);
}

void carregarContatos(){
    FILE *file = fopen(FILENAME, "r");
    if(file == NULL){
        printf("Nenhum arquivo de contato encontrado. Inicie novamente.\n");
        return;
    }

    fread(&numContatos, sizeof(int), 1, file);
    fread(contatos, sizeof(Contato), numContatos, file);
    fclose(file);
}

void adicionarContato(){
    if(numContatos >= MAX_CONTATOS){
        printf("Limite de contatos atingido.\n");
        return;
    }

    Contato novoContato;
    printf("Digite o nome: ");
    scanf("%[^\n]s", novoContato.nome);
    printf("digite o telefone: ");
    scanf("%s", novoContato.telefone);
    printf("Digite o email: ");
    scanf("%s", novoContato.email);

    contatos[numContatos++] = novoContato;
    salvarContatos();
    printf("Contato adicionado com sucesso!\n");
}

void listarContatos(){
    if(numContatos == 0 ){
        printf("Nenhum contato encontrado\n");
        return;
    }

    for(int i = 0; i < numContatos; i++){
        printf("Contato %d\n",i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("telefone: %s\n", contatos[i].telefone);
        printf("email: %s\n\n", contatos[i].email);
    }
}

void buscarContato(){
    char nomeBusca[TAM_NOME];
    printf("Digite o nome do contato para a busca");
    scanf("%[^\n]s", nomeBusca);

    for(int i = 0; i < numContatos; i++){
        if(strcmp(contatos[i].nome, nomeBusca) == 0){
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Email: %s\n", contatos[i].email);
            return;
        }
    }

    printf("contado nao encontrado\n")
}

