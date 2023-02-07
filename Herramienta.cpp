/*Verificar interfaces - ver la ip de la interfaz activa*/
/*Verificar si hay conectividad con google*/
/*Abrir Wireshark*/
/*Usar TCPDump*/
/*Verificar versión de Kernel*/
/*Verificar nombre de Dispositivo*/

#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int main() {
    int option;
    cout << "1. Verificar interfaces de red" << endl;
    cout << "2. Verificar conectividad con Google" << endl;
    cout << "3. Abrir Wireshark" << endl;
    cout << "4. Usar TCPDump (ICMP o ARP)" << endl;
    cout << "5. Verificar version de Kernel" << endl;
    cout << "6. Verificar nombre de dispositivo" << endl;
    cout << "Elija una opcion: ";
    cin >> option;

    switch (option) {
        case 1:
            system("ifconfig");
            break;
        case 2:
        {
            int result = system("ping -c 3 www.google.com");
            if (result == 0) {
                cout << "Te has podido conectar a google" << endl;
            } else {
                cout << "No estas conectado a google" << endl;
            }
            break;
        }
        case 3:
            system("wireshark &");
            break;
        case 4:
        {
            cout << "1. TCPDump con ICMP" << endl;
            cout << "2. TCPDump con ARP" << endl;
            cout << "Elija una opcion: ";
            int dumpOption;
            cin >> dumpOption;
            if (dumpOption == 1) {
                system("sudo tcpdump icmp");
            } else if (dumpOption == 2) {
                system("sudo tcpdump arp");
            } else {
                cout << "Opcion invalida." << endl;
            }
            break;
        }
        case 5:
            system("uname -r");
            break;
        case 6:
            system("hostname");
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
    }

    return 0;
}
