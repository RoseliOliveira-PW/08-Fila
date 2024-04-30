#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* inicio = NULL;
NO* fim = NULL;

// headers
void menu();
void inicializar();
void insere();
void remove();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 4) {
		system("cls"); // somente no windows
		cout << "Menu Fila";
		cout << endl << endl;
		cout << "1 - Inicializar Fila \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Remover elemento  \n";
		cout << "4 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:insere();
			break;
		case 3: remove();
			break;
		case 4:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = inicio;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	inicio = NULL;
	fim = NULL;
	cout << "Fila inicializada \n";

}


void insere()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	novo->valor;
	novo->prox = NULL;
	if (inicio == NULL) {
		inicio = novo;
	}
	else {
		fim->prox = novo;
	}
	fim = novo;


}

void remove()
{   
	int item;
	NO* temp = inicio;
	cout << "fila: [";
	while (temp != NULL) {
		cout << temp->valor << " ";
		temp = temp->prox;
	}
	cout << "]\n";
	temp = inicio;
	inicio->valor;
	if (inicio != NULL) {
		cout << " O valor do primeiro elemento é: " << inicio->valor << endl;
		inicio = inicio->prox;
		delete temp;
		cout << " O elemento vai ser deletado \n";
	}
	else {
		 cout << "Não existe mais nenhum elemento \n";
		 cout << "A lista está vazia \n";
		return;
	}
}


