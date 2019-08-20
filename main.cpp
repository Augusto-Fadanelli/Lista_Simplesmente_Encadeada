#include <iostream>
#include <locale> // para o setlocale
#include <stdlib.h> // para o system("cls"); (So funciona no windows)

#ifdef __unix__

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
//int inserir(no **);
void clear();

int main()
{

    setlocale(LC_ALL, "Portuguese");

    no *novo;
	*novo.valor = 0;
    int flag = 0;

    do{

        if(flag == 2){
            cout << "Opção inválida!" << endl;
            flag = 0;
        }

        switch(menu()){
        case 1:
		//inserir();
		if(novo.valor==0){
			novo.prox = NULL;
		}else{
			novo.prox = (no *) malloc(sizeof(no));
		}
        break;
        case 2:

        break;
        case 3:

        break;
        case 4:

        break;
        case 5:
            flag = 1;
        break;
        default:
            flag = 2;
        }

        clear();

    }while(flag != 1);

    return 0;
}

int menu(){

    int op;

    cout << "***LISTA SIMPLESMENTE ENCADEADA***" << endl;
    cout << "1 - Inserir" << endl;
    cout << "2 - Excluir" << endl;
    cout << "3 - Pesquisar" << endl;
    cout << "4 - Limpar" << endl;
    cout << "5 - Sair" << endl;
    cin >> op;

	return op;
}

/*(int inserir(int **Ptrrecebido){

	if(Ptrvalor==0){
		Ptrprox = NULL;
	}else

	return 0;
}*/

void clear(){

	#ifdef OS_Windows
	// Codigo Windows
		system("cls");
	#else
	// Codigo GNU/Linux
		system("clear");
	#endif
}
