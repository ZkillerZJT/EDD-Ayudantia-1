#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Local{//ta weno, quizás agregar int id;
private:
    int superficie;
    string tipo_local;
    float monto_arriendo;
    string nombre_local;
public:
    Local(int superficie_, string tipo_local_, string nombre_local_) {//constructor
        superficie = superficie_;
        tipo_local = tipo_local_;
        string nombre_local = nombre_local_;
        monto_arriendo = calcularArriendo(superficie, tipo_local);
    }
    //al indicar superficie en m2 del local y su nombre, se debe especificar el tipo de local antes de usar el constructor.
    ~Local() {}
        //definir setters



        //definir getters


        //definir visualizador de objetos
    float calcularArriendo(int superficie, string tipo_local) { // ta weno
        // 0.5 uf/m2 para oficinas, 0.65 uf/m2 para locales comerciales
        int precio_calculado=0;
        if(tipo_local=="oficina"){
            precio_calculado=superficie*0,5;
        }
        else if (tipo_local=="local comercial"){
            precio_calculado=superficie*0,65;
        }
        return precio_calculado;
    }
    void setTipo(int tipoINT){ // falta la logica para utilizar esta función y utilizar la variable
        if (tipoINT==1)         // int usado en el menu de creacion de objeto
            tipo_local="oficina";
        if (tipoINT==1)
            tipo_local="local comercial";
    }
};

void mostrarMenu() { //ta weno
    int opcion=0;
    cout << "=== Menú ===" << endl;
    cout << "1. Crear objeto" << endl;
    cout << "2. Ver listado de objetos" << endl;
    cout << "3. Eliminar objeto" << endl;
    cout << "Ingrese su opción: ";
}
void HandleChoice(int opcion){// falta logica 
    switch (opcion){
        case 1:
                // llamado a funcion de crearobjeto
            break;
        case 2:
                //llamado a funcion ver listado de objetos
            break;
        case 3:
            //llamado a funcion destructor considerando el local a eliminar
            break;
        case 0:
        exit(0);// puede que este bien o no que esto se encuentre aquí, hay una condicion en main para case 0.
        /*case default:
            cout<<"opcion incorrecta, intente nuevamente."<<endl;
            main();
            break; */
        
    }
}
void crearLocal(){//falta toda la logica usando setters y usar las variables.

    }

int main() {
    //al indicar superficie en m2 del local y su nombre, se debe especificar el tipo de local antes de usar el constructor.
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        HandleChoice(opcion);
    } while (opcion != 0);

    return 0;
}
