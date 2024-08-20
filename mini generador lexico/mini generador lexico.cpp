//ALFREDO AMEZCUA MARTINEZ 
#include <iostream>
#include <string>
using namespace std;

// En esta parte revisamos si el caracter es una letra
bool esLetra(char c) {
    return isalpha(c);
}

// En esta parte revisamos si el caracter es un numero
bool esDigito(char c) { 
    return isdigit(c);
}

// Aquí se imprimen los identificadores y los reales
void imprimirToken(string token, bool real){
    if (!token.empty()) {
        if (real) {
            cout << "Real: " << token << endl;
        } else {
            cout << "Identificador: " << token << endl;
        }
    }
}

// Función para analizar el texto y encontrar tokens
void analizarTexto(const string& texto) {
    string tokenActual;
    bool esReal = false;
    bool esId = false;

    for (size_t i = 0; i < texto.length(); ++i) {
        char c = texto[i];

        if (esLetra(c)) {
            tokenActual += c;
            esId = true;
        } else if (esDigito(c)) {
            tokenActual += c;
            if (!esId) esReal = true;
        } else if (c == '.' && esReal) {
            tokenActual += c;
        } else {
            imprimirToken(tokenActual, esReal);
            tokenActual.clear();
            esReal = false;
            esId = false;
        }
    }

    imprimirToken(tokenActual, esReal);
}

int main() {
    string texto = "4123 xft 123.456 12.1 xyrrz 789.0 aaa1 a2 a3 a4";

    cout << "Analizando el texto:" << endl;
    analizarTexto(texto);

    return 0;
}

