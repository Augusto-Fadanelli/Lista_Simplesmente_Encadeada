#include <iostream>
#include <locale> // para o setlocale
#include <stdlib.h> // para o system("cls"); (So funciona no windows)

using std::cout;
using std::cin;
using std::endl;

typedef struct no{
    int valor;
    struct no *prox;
}no;

int menu();

int main()
{

    setlocale(LC_ALL, "Portuguese");

    no novo;
    int flag = 0;

    do{

        if(flag == 2){
            cout << "Opção inválida!" << endl;
            flag = 0;
        }

        switch(menu()){
        case 1:

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

        system("cls");

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
