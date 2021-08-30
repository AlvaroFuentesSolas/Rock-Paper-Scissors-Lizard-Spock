#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

enum tElemento {
	PIEDRA, PAPEL, TIJERAS, LAGARTO, SPOCK, INVALIDO
};
tElemento jugada;
tElemento jugador;
tElemento maquina;

enum tResultado {
	HUMANO, COMPUTADORA, EMPATE
};
tResultado resultado;

void menu() {
	cout << "Bienvenido: \n";
	cout << "1.- Jugar una partida. \n";
	cout << "2.- Ver instrucciones. \n";
	cout << "0.- Salir. \n";
}

//Opcion 2 menu
int leeOpcion(string pregunta, string mensajeError, int valMin, int valMax) { //Lee la opcion del menu
	int valor;


	cout << pregunta << "\n";
	cin >> valor;

	while (valMin > valor || valMax < valor) {
		cout << mensajeError;
		cin >> valor;
	}

	return valor;
}

//Opcion 2 menu
void Instruccion() { //Leer fichero

	ifstream fichero;

	fichero.open("reglas.txt");
	if (!fichero.is_open()) {
		cout << "Existe un error, vuelva a intentarlo. \n";
	}
	else {
		string line;

		getline(fichero, line);
		while (line != "XXX") { //centinela
			cout << line << '\n';
			getline(fichero, line);
		}
		fichero.close();
	}
}
// Usuario
bool localizacionJugador(string apodo) {

	ifstream registro;
	registro.open("registro.txt");
	bool retono = false;

	if (!registro.is_open()) {
		cout << "Existe un error, vuelva a intentarlo. \n";
	}
	else {
		string line;

		getline(registro, line);
		while (line != "XXX") { //centinela
			cout << line << '\n';
			getline(registro, line);
		}
		registro.close();
	}

	return false; //HAY QUE RETOCARLA
}


//Opcion 1 menu

tElemento leeJugada(string pregunta) { //Escribe la opcion con la que se va a jugar

	string eleccion;

	cout << pregunta;
	cin >> eleccion;
	while (eleccion != "piedra" && eleccion != "papel" && eleccion != "tijeras" && eleccion != "lagarto" && eleccion != "Spock") {
		cout << "Opcion incorrecta, introducela de nuevo: ";
		cin >> eleccion;
	}

	// tElemento fromString(string)
	if (eleccion == "piedra") {
		jugada = PIEDRA;
	} if (eleccion == "papel") {
		jugada = PAPEL;
	} if (eleccion == "tijeras") {
		jugada = TIJERAS;
	} if (eleccion == "lagarto") {
		jugada = LAGARTO;
	} if (eleccion == "Spock") {
		jugada = SPOCK;
	}

	return jugada;
}

tElemento jugada_maquina(int a) //aleatorio
{

	tElemento jugada;

	if (a == 0) {
		jugada = PIEDRA;
	}
	else if (a == 1) {
		jugada = PAPEL;
	}
	else if (a == 2) {
		jugada = TIJERAS;
	}
	else if (a == 3) {
		jugada = LAGARTO;
	}
	else {
		jugada = SPOCK;
	}


	return jugada;
}


string toString(int aleatorio) {

	string cad;
	if (aleatorio == PIEDRA) {
		cad = "piedra";
	} if (aleatorio == TIJERAS) {
		cad = "tijeras";
	} if (aleatorio == PAPEL) {
		cad = "papel";
	} if (aleatorio == SPOCK) {
		cad = "Spock";
	} if (aleatorio == LAGARTO) {
		cad = "lagarto";
	}
	cout << cad;   //hay que quitarlo
	return cad;
}

// Ejecuta el punto 2 del menu, ver instrucciones

int aleatorio() {
	srand(time(NULL));
	int aleatorio;

	for (int i = 0; i < 1; i++) {
		aleatorio = rand() % 5;

	}
	cout << aleatorio; // hay que quitarlo
	return aleatorio;


}








bool gana(tElemento jugador1, tElemento jugador2) {

	bool retorno = false;

	if ((jugador1 == LAGARTO) && (jugador2 == PAPEL || jugador2 == SPOCK)) {
		retorno = true;
	}
	if ((jugador1 == TIJERAS) && (jugador2 == PAPEL || jugador2 == LAGARTO)) {
		retorno = true;
	}

	if ((jugador1 == PIEDRA) && (jugador2 == TIJERAS || jugador2 == LAGARTO)) {
		retorno = true;
	}

	if ((jugador1 == PAPEL) && (jugador2 == PIEDRA || jugador2 == SPOCK)) {
		retorno = true;
	}

	if ((jugador1 == SPOCK) && (jugador2 == TIJERAS || jugador2 == PIEDRA)) {
		retorno = true;
	}


	return retorno;
}






int main() {

	int opcion;
	menu();
	opcion = leeOpcion("Opcion: ", "Opcion Invalida, introduzacala otra vez: ", 0, 2);

	if (opcion == 0) {

	} if (opcion == 1) {

		tElemento jugador;
		int eleccion_maquina;
		string cad;


		//Maquina
		eleccion_maquina = aleatorio();
		cad = toString(eleccion_maquina);

		maquina = jugada_maquina(eleccion_maquina);
		//Usuario
		jugador = leeJugada("\nElige una opcion:");

		bool gana_jugador = gana(jugador, maquina);
		bool gana_maquina = gana(maquina, jugador);

		if (gana_jugador == true){
			cout << "ganaste \n";
		}
		else if (gana_maquina == true){
			cout << "gano la maquina \n";
		}
		else {
			cout << "empate \n";
		}



		system("pause");

	} if (opcion == 2) {
		Instruccion();
		return main();
	}



}
