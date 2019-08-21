#include <iostream>
#include <locale> // para o setlocale
#include <stdlib.h> // para o system("cls"); (So funciona no windows)

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
void clear();
void pause();

int main()
{

	setlocale(LC_ALL, "Portuguese");

   	no *lista;
	lista = NULL; //O primeiro valor da lista aponta para NULL
	no *novo;

	int num;
   	int flag = 0; //Flag para sair do loop

    do{

        switch(menu()){
        case 1:
		//inserir();

		cout << "Digite um Número inteiro para inserir na lista lista: ";
		cin >> num;
		cout << endl;

		novo = (no *)malloc(sizeof(no)); //O ponteiro 'novo' recebe o local indicado por malloc(); do tamanho definido por sizeof();

		if (novo == NULL){ //Impede que o programa execute caso o malloc não consiga encontrar memória livre
                	cout << "Memória insuficiente!\n Tente fechar alguns programas ou reiniciar a máquina." << endl;
                	pause();
               		if(lista == NULL){ // se novo e lista == NULL então nada foi adicionado na lista e o programa pode ser fechado
                    		exit(1);
                	} // se a lista possuir elementos o programa não fecha, mesmo com o malloc não conseguindo encontrar espaços de memória livres
            	}else{
                	novo->valor=num;
                	novo->prox=lista; //Lista inicialmente vale NULL, depois de ser inserido algum valor 'lista' vai ser igual ao ptr anterior
                	lista=novo;
            	}
        break;
        case 2:
		//excluir();


        break;
        case 3:
		//pesquisar();

            if(lista == NULL){
                cout << "Lista vazia!" << endl;
                pause();
            }else{
                cout << endl;
                cout << endl;
                no *aux = novo;
                	do{				
				cout << aux->valor << endl;
                		aux = aux->prox; //O ptr 'aux' agora vai apontar para o proximo valor
                	}while(aux != NULL);
                pause();
            }

        break;
        case 4:
        //limpar();
            lista = NULL; //perde-se o local do ultimo valor informado
        break;
        case 5:
        //Sair
            flag = 1;
        break;
        default:
            cout << "Opção inválida!" << endl;
            pause();
        }

        clear();

    }while(flag != 1);

    return 0;
}

int menu(){

    int op;

    cout << "**LISTA SIMPLESMENTE ENCADEADA**" << endl;
    cout << "1 - Inserir" << endl;
    cout << "2 - Excluir" << endl;
    cout << "3 - Pesquisar" << endl;
    cout << "4 - Limpar" << endl;
    cout << "5 - Sair" << endl;
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
