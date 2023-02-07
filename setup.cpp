#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main() {
    // Actualiza la lista de paquetes disponibles
    cout << "Actualizando lista de paquetes disponibles..." << endl;
    int update = system("sudo apt-get update");
    if (update != 0) {
        cerr << "Error al actualizar la lista de paquetes" << endl;
        return 1;
    }

    // Instalación Wireshark
    cout << "Instalando Wireshark..." << endl;
    int install = system("sudo apt-get install wireshark");
    if (install != 0) {
        cerr << "Error al instalar Wireshark" << endl;
        return 1;
    }

    cout << "Instalacion de Wireshark completada" << endl;
    return 0;
}
