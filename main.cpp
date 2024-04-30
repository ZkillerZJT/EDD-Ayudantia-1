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
        ///*monto_arriendo =calcularArriendo(superficie, tipoINT);*/
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
    void setMontoarriendo(int monto_arriendo_){
        this->monto_arriendo=monto_arriendo_;
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
    void ver(){
        cout<<"nombre local: "<<nombre_local<<endl;
        cout<<"tipo de local: "<<tipo_local<<endl;
        cout<<"superficie en m2 del local: "<<superficie<<endl;
        cout<<"Monto en uf a pagar por arriendo: "<<monto_arriendo<<endl;
        if(tipoINT=1){// oficina
        cout<<"se aplico tarifa de oficina, 0.5UF por m2."<<endl;
        }
        else if (tipoINT=2){// local comercial
        cout<<"se aplico tarifa de local comercial, 0.65UF por m2."<<endl;
        }
        
    }
    void calcularArriendomiembro(int tipoINT) { // funcion miembro
        // 0.5 uf/m2 para oficinas, 0.65 uf/m2 para locales comerciales
        cout<<"la superficie es de:"<<superficie<<"y el tipo de local es"<<tipo_local<<endl;
        if(tipoINT=1){// oficina
        float precio=superficie*0.5;
        setMontoarriendo(precio);
            //this->monto_arriendo=this->superficie*0,5;
        }
        else if (tipoINT=2){// local comercial
        float precio=superficie*0.65;
        setMontoarriendo(precio);
            //this->monto_arriendo=this->superficie*0,65;
        }
    }
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
    cout<<locsuperficie<<endl;
    Local L;
    L.setNombrelocal(locnombre);
    L.setTipolocal(tipoINT);
    L.setSuperficie(locsuperficie);
    L.calcularArriendomiembro(tipoINT);
    //L.setMontoarriendo(calcularArriendo(locsuperficie, tipoINT));
    L.ver();
    }
void HandleChoice(int opcion){// falta logica 
    switch (opcion){
        case 1:
            crearLocal();    // llamado a funcion de crearobjeto
            break;
        case 0:
        exit(0);// puede que este bien o no que esto se encuentre aquí, hay una condicion en main para case 0.
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