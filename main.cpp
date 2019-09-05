#include <iostream>
#include <locale> // para o setlocale
#include <stdlib.h> // para o system("cls"); (So funciona no windows) // para o malloc

//Verifica se o SO é GNU/Linux ou Windows
#ifdef _unix_

	#define OS_UNIX

#elif defined(_WIN32) || defined(WIN32)

	#define OS_WINDOWS

#endif

using std::cout;
using std::cin;
using std::endl;

typedef struct no{
    int valor;
    struct no *prox;
}no;

int menu();

int inserir(int, no **, no **);
int inserirpos(int, int, no *, no **, no **);
void listar(no *, no **);
int excluir(int, no *, no **, no **);

void clear();
void pause();

int main()
{

	setlocale(LC_ALL, "Portuguese");

   	no *lista;
	lista = NULL; //O primeiro valor da lista aponta para NULL
	no *novo;

	int cont = 0;
	int ind;
   	int flag = 0; //Flag para sair do loop

   	no *aux;//usado em excluir e pesquisar

    do{

        switch(menu()){
        case 1:
            cont = inserir(cont, &novo, &lista);

        break;
        case 2:
        //Inserir por Posição
            cout << "Digite o local a ser inserido: ";
            cin >> ind;

            if(ind == 1){
                cont = inserir(cont, &novo, &lista);
            }else if(ind > 0 && ind <= cont + 1){
                cont = inserirpos(cont, ind, lista, &novo, &lista);
            } else{
                cout << "Posição inválida!" << endl;
                pause();
            }

        break;
        case 3:
            listar(lista, &lista);

        break;
        case 4:
            cont = excluir(cont, lista, &novo, &lista);

        break;
        case 5:
        //limpar();
            lista = NULL; //perde-se o local do ultimo valor informado
            novo = NULL;
            cont = 0;

        break;
        case 6:
            flag =1;

        break;
        default:
            cout << "Opção inválida!" << endl;
            pause();

        }

        clear();

    }while(flag != 1);

    return 0;
}

int inserir(int cont, no **novo, no **lista){

    int num;

    cout << "Digite um Número inteiro para inserir na lista lista: ";
    cin >> num;
    cout << endl;

    *novo = (no *)malloc(sizeof(no)); //O ponteiro 'novo' recebe o local indicado por malloc(); do tamanho definido por sizeof();

    if (*novo == NULL){ //Impede que o programa execute caso o malloc não consiga encontrar memória livre
        cout << "Memória insuficiente!\n Tente fechar alguns programas ou reiniciar a máquina." << endl;
        pause();
        if(*lista == NULL){ // se novo e lista == NULL então nada foi adicionado na lista e o programa pode ser fechado
            exit(1);
        } // se a lista possuir elementos o programa não fecha, mesmo com o malloc não conseguindo encontrar espaços de memória livres
    }else{
        (*novo)->valor=num;
        (*novo)->prox=*lista; //Lista inicialmente vale NULL, depois de ser inserido algum valor 'lista' vai ser igual ao ptr anterior
        *lista=*novo;
        cont++;
    }

    return cont;
}

int inserirpos(int cont, int ind, no *aux, no **novo, no **lista){

    int num;
    cout << "Digite um Número inteiro para inserir na lista lista: ";
    cin >> num;

    for(int i=1; i<ind-1; i++){
        aux = aux->prox;
    }
    *novo = (no *)malloc(sizeof(no)); //O ponteiro 'novo' recebe o local indicado por malloc(); do tamanho definido por sizeof();

    (*novo)->valor=num;
    (*novo)->prox=aux->prox;
    aux->prox=*novo;

    cont++;

    return cont;
}

void listar(no *aux, no **lista){

    if(*lista == NULL){
        cout << "Lista vazia!" << endl;
        pause();
    }else{
        cout << endl;
        cout << endl;
        int cont = 0;
        do{
            cout << cont+1 << "º "<< aux->valor << " | ";
            aux = aux->prox; //O ptr 'aux' agora vai apontar para o proximo valor
            cont++;
        }while(aux != NULL);
        cout << endl;
        cout << endl;
        cout << "A lista possui " << cont <<  " valores." << endl;
        pause();
    }

}

int excluir(int cont, no *aux, no **novo, no **lista){

    int ind;
    no *morta;
    cout << "Digite o índice do valor a ser excluido: ";
    cin >> ind;

    if(ind > 1 && ind <= cont){ //Impede que um valor de um indice que não exista seja excluido (O que poderia causar uma falha de segmentação "Crashar")
        for(int i=0; i<ind-2; i++){
            aux = aux->prox;
        }
        morta = aux->prox;
        aux->prox = morta->prox;
        cont--;
    }else{
        if(ind == 1 && cont != 0){ //Impede a execução caso não exista indice
            *novo = aux->prox;
            *lista = *novo;
            cont--;
        }else{
            cout << "Índice inválido!" << endl;
            pause();
        }
    }
    
	return cont;
}

int menu(){

    int op;

    cout << "**LISTA SIMPLESMENTE ENCADEADA**" << endl;
    cout << "1 - Inserir no Início" << endl;
    cout << "2 - Inserir por Posição" << endl;
    cout << "3 - Listar" << endl;
    cout << "4 - Excluir por Posição" << endl;
    cout << "5 - Limpar Lista" << endl;
    cout << "6 - Sair" << endl;
    cin >> op;

	return op;
}

void clear(){

	#ifdef OS_WINDOWS
	// Codigo Windows
		system("cls");
	#else
    //Codigo GNU/Linux
		system("clear");
	#endif
}

void pause(){

    #ifdef OS_WINDOWS
    // Codigo Windows
        system("pause");
    #else
    // Codigo GNU/Linux
        cout << "Pressione qualquer tecla para continuar...";
        getchar();
    #endif

}
