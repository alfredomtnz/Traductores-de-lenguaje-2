//Ejercicio 1:
//ALFREDO AMEZCUA MARTINEZ
#include <iostream>
#include <stack>
#include <string>
#include <cctype> // Para isalpha y isdigit
using namespace std;
// Tabla de transiciones simplificada (0 para aceptar, negativos para reducir)
int tabla[5][3] = {
    {2, -1, 1},
    {-1, -1, -1},
    {-1, 3, -1},
    {4, -2, -2},
    {-1, -3, -3}
};

// Funci�n para obtener el siguiente token
int getToken(const string& input, int& i) {
    if (i < input.size()) {
        char c = input[i];
        if (isalpha(c)) {
            return 0; // identificador
        } else if (c == '+') {
            return 1; // '+'
        } else if (c == '$') {
            return 2; // fin de entrada
        }
    }
    return -1; // token inv�lido
}

bool analizar(string input) {
    input += "$";
    stack<int> pila;
    pila.push(0);
    int i = 0;

    while (!pila.empty()) {
        int estado = pila.top();
        int token = getToken(input, i);
        int accion = tabla[estado][token];

        if (accion == 0) {
            return true; // Aceptaci�n
        } else if (accion < 0) {
            int reduccion = -accion;
            for (int j = 0; j < reduccion; j++) {
                pila.pop();
            }
            int estado_actual = pila.top();
            // Consultar la tabla con el s�mbolo de reducci�n
            int simbolo_reduccion = 3; // Por ejemplo, 3 representa la reducci�n de regla 3
            int nuevo_estado = tabla[estado_actual][simbolo_reduccion];
            pila.push(simbolo_reduccion);
            pila.push(nuevo_estado);
        } else {
            pila.push(token);
            pila.push(accion);
            i++;
        }
    }
    return false; // No se alcanz� la aceptaci�n
}

int main() {
    cout<<"EJERCICIO 1"<<endl;
    string input = "hola+mundo";
    cout << "expresion: "<<input<<endl;
   

    if (analizar(input)) {
        cout << "Expresion valida.\n";
    } else {
        cout << "Expresion invalida.\n";
    }
    return 0;
}
