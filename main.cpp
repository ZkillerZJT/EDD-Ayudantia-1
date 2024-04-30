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
    //constructor default
    Local(){}
    //destructor
    ~Local() {}
        //Setters
    void setSuperficie(int superficie_){ this->superficie=superficie_;}                 //superficie
    void setTipolocal(int tipoINT){                                                     //tipo local
        if (tipoINT==1)         // int usado en el menu de creacion de objeto  
            this->tipo_local="oficina";
        if (tipoINT==2)
            this->tipo_local="local comercial";
        
    }
    void setNombrelocal(string nombre_local_){ this->nombre_local=nombre_local_;}       // nombre de local
    void setMontoarriendo(int monto_arriendo_){ this->monto_arriendo=monto_arriendo_;}  //monto de arriendo
        
        //Getters
    int getsuperficie(){return superficie;}                 //superficie
    string getTipolocal(){return this->tipo_local;}         //Tipo local
    string getNombrelocal(){return this->nombre_local;}     // nombre de local
    float getMontoarriendo(){return this->monto_arriendo;}  //monto de arriendo
   
        //Visualizador
    void ver(){
        cout<<"nombre local: "<<nombre_local<<endl;
        cout<<"tipo de local: "<<tipo_local<<endl;
        cout<<"superficie en m2 del local: "<<superficie<<endl;
        cout<<"Monto en uf a pagar por arriendo: "<<monto_arriendo<<endl;
        if(tipo_local=="oficina"){
        cout<<"se aplico tarifa de oficina, 0.5UF por m2."<<endl;
        }
        else if(tipo_local=="local comercial"){
        cout<<"se aplico tarifa de local comercial, 0.65UF por m2."<<endl;
        }
        
    }
    void calcularArriendomiembro(int tipoINT) { // funcion miembro
        // 0.5 uf/m2 para oficinas, 0.65 uf/m2 para locales comerciales
        float superf=superficie;
        if(tipo_local=="oficina"){
            float precio=superf*0.5;
        setMontoarriendo(precio);
        }
        if(tipo_local=="local comercial"){
            float precio=superf*0.65;
        setMontoarriendo(precio);
        }
    }
};
void checktipoINT(){
if(tipoINT>2 || tipoINT<1){
    cout<<"Opción indicada es incorrecta, usted digito "<<tipoINT<<" y se esperaba 1 o 2."<<endl;
    cout<<"indique tipo de local digitando 1 para oficina y 2 para local comercial:"<<endl;
    cin.clear();
    cin>>tipoINT;
    checktipoINT();
    }
}
void mostrarMenu() { //ta weno
    cout << "=== Menú ===" << endl;
    cout << "1. Crear nuevo local." << endl;
    cout << "0. Finalizar." << endl;
    cout << "Ingrese su opción: ";
}
void crearLocal(){
    cout<<"indique nombre de local:"<<endl;
    string locnombre;
    cin.ignore();
    getline(cin, locnombre);
    cout<<"indique tipo de local digitando 1 para oficina y 2 para local comercial:"<<endl;
    cin>>tipoINT;
    checktipoINT();
    cout<<"indique superficie de local en m2:"<<endl;
    int locsuperficie;
    cin.clear();
    cin>>locsuperficie;
    Local L;
    L.setNombrelocal(locnombre);
    L.setTipolocal(tipoINT);
    L.setSuperficie(locsuperficie);
    L.calcularArriendomiembro(tipoINT);
    L.ver();
    }
void HandleChoice(int opcion){
    switch (opcion){
        case 1:
            crearLocal();
            break;
        case 0:
        exit(0);
        default:
            cout<<"opcion incorrecta, intente nuevamente."<<endl;
            break;
        
    }
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