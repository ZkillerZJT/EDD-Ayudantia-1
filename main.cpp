#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int tipoINT=0;
class Local{//ta weno, quizás agregar int id;
private:
    int superficie;
    string tipo_local;
    float monto_arriendo;
    string nombre_local;
public:
    Local(){}
    void Local2(int superficie_, string tipo_local_, string nombre_local_) {//constructor
        superficie = superficie_;
        tipo_local = tipo_local_;
        string nombre_local = nombre_local_;
        //monto_arriendo = calcularArriendo(superficie, tipoINT);
    }
    //al indicar superficie en m2 del local y su nombre, se debe especificar el tipo de local antes de usar el constructor.
    ~Local() {}
        //definir setters
    void setSuperficie(int superficie_){
        this->superficie=superficie_;
    }
    /*void setTipolocal(string tipo_local_){ // no necesario en este caso, placeholder.
        this->tipo_local=tipo_local_;
    }*/
    void setTipolocal(int tipoINT){ // falta la logica para utilizar esta función y utilizar la variable
        if (tipoINT==1)         // int usado en el menu de creacion de objeto
            this->tipo_local="oficina";
        if (tipoINT==2)
            this->tipo_local="local comercial";
    }
    void setNombrelocal(string nombre_local_){
        this->nombre_local=nombre_local_;
    }
    void setMontoarriendo(int superficie_){
        this->superficie=superficie_;
    }
        //definir getters
    int getsuperficie(){
        return superficie;
    }
    string getTipolocal(){
        return this->tipo_local;
    }
    string getNombrelocal(){
        return this->nombre_local;
    }
    float getMontoarriendo(){
        return this->monto_arriendo;
    }
        //definir visualizador de objetos

};
float calcularArriendo(int superficie, int tipoINT) { // funcion miembro
        // 0.5 uf/m2 para oficinas, 0.65 uf/m2 para locales comerciales
        int precio_calculado=0;
        if(tipoINT=1){// oficina
            precio_calculado=superficie*0,5;
        }
        else if (tipoINT=2){// local comercial
            precio_calculado=superficie*0,65;
        }
        return precio_calculado;
    }
void mostrarMenu() { //ta weno
    cout << "=== Menú ===" << endl;
    cout << "1. Crear objeto" << endl;
    cout << "2. Ver listado de objetos" << endl;
    cout << "3. Eliminar objeto" << endl;
    cout << "Ingrese su opción: ";
}
void HandleChoice(int opcion){// falta logica 
    switch (opcion){
        case 1:
            crearLocal();    // llamado a funcion de crearobjeto
            break;
        case 2:
                //llamado a funcion ver listado de objetos
            break;
        case 3:
            //llamado a funcion destructor considerando el local a eliminar
            break;
        case 0:
        exit(0);// puede que este bien o no que esto se encuentre aquí, hay una condicion en main para case 0.
        default:
            cout<<"opcion incorrecta, intente nuevamente."<<endl;
            main();
            break;
        
    }
}
void checktipoINT(){
if(tipoINT>2 || tipoINT<1){
        cout<<"Opción indicada es incorrecta, usted digito "<<tipoINT<<" y se esperaba 1 o 2."<<endl;
        cout<<"indique tipo de local digitando 1 para oficina y 2 para local comercial:"<<endl;
    cin>>tipoINT;
    checktipoINT();
    }
}
void crearLocal(){//falta toda la logica usando setters y usar las variables.
    cout<<"indique nombre de local:"<<endl;
    string locnombre;
    cin>>locnombre;
    cout<<"indique tipo de local digitando 1 para oficina y 2 para local comercial:"<<endl;
    cin>>tipoINT;
    checktipoINT();
    cout<<"indique superficie de local en m2:"<<endl;
    int locsuperficie;
    cin>>locsuperficie;
    Local L;
    L.setNombrelocal(locnombre);
    L.setTipolocal(tipoINT);
    L.setSuperficie(locsuperficie);
    L.setMontoarriendo(calcularArriendo(locsuperficie, tipoINT));



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
