#include "Mapa.h"

//Constructor de la clase Mapa
// Pre: argumentos inicializados con valores naturales
// Post: Objeto Mapa
Mapa::Mapa( int filas, int columnas ){

    mapa = new Casillero**[columnas];

    for( int i=0; i < filas; i++)
    {
        mapa[i] = new Casillero*[filas];
    }
}

//Constructor de la clase Mapa
// Pre: Objeto Mapa bien formado
// Post: Objeto Mapa
Mapa::Mapa(const Mapa &inicial){
    int i,j;
    cant_columnas = inicial.cant_columnas;
    cant_filas = inicial.cant_filas;

    mapa = new Casillero**[cant_filas];

    for( i=0; i < cant_filas; i++)
    {
        mapa[i] = new Casillero*[cant_columnas];
        mapa[i] = nullptr;
    }

    for ( i = 0; i < cant_filas; i++) {
        for ( j = 0; j < cant_columnas; j++) {
                mapa[i][j] = inicial.mapa[i][j];
        }
    }
}

// Destructor de la clase Mapa
// Pre: Objeto Mapa bien formado
// Post: -
Mapa::~Mapa(){

    for (int i = 0; i < cant_filas; i++) {
        delete [] mapa[i];
    }
    delete [] mapa;

}

// Sobrecarga del operador = para formar Mapa
// Pre: El Mapa debe esatr bien formado
// Post: Un Mapa formado
Mapa& Mapa::operator=( const Mapa & derecha){

    int i,j;

    if(&derecha != this){
        
        if( cant_filas != derecha.cant_columnas || cant_filas != derecha.cant_columnas){

            Casillero*** aux;

            aux = new Casillero**[derecha.cant_filas];

            for( i=0; i < derecha.cant_filas; i++)
            {
                aux[i] = new Casillero*[derecha.cant_columnas];
                aux[i] = nullptr;
            }

            for ( i = 0; i < cant_filas; i++) {
                delete [] mapa[i];
            }
            delete [] mapa;
           
            cant_filas = derecha.cant_filas;
            cant_columnas = derecha.cant_columnas;
            mapa = aux;

            for ( i = 0; i < cant_filas; i++) {
                for ( j = 0; j < cant_columnas; j++) {
                        mapa[i][j] = derecha.mapa[i][j];
                }
            }
            return *this;
        }
        else
        {
            for ( i = 0; i < cant_filas; i++) {
                for ( j = 0; j < cant_columnas; j++) {
                        mapa[i][j] = derecha.mapa[i][j];
                }
            }
            return *this;
        }
    }
    return *this;
}

// Sobrecarga del operador == para comparar Mapa
// Pre: El Mapa debe estar bien formado
// Post: Un booleano que identifica si son iguales
bool Mapa::operator== (const Mapa & derecha){

    if( cant_filas != derecha.cant_filas || cant_columnas != derecha.cant_columnas)
        return false;
    else
    {
        for ( int i = 0; i < cant_filas; i++) {
            for (  int j = 0; j < cant_columnas; j++) {
                    if( mapa[i][j] != derecha.mapa[i][j])
                        return false;
            }
        }
    }
    
    return true;
}

// Constructor de la clase Casillero formado a traves de un flujo de entrada
// Pre: Flujo de entrada bien formado
// Post: Objeto Casillero
Mapa::Mapa( const string &input){
    fstream archivo_edificios(input, ios::in);

    if (!archivo_edificios.is_open()) {
		cout << BGND_LIGHT_PINK_203 << "No se encontro ningun archivo con el nombre " << input << END_COLOR << endl;
    }

    char dato;
    int opcion_casillero, i , j;

    archivo_edificios >> cant_filas;
    archivo_edificios >> cant_columnas;

    mapa = new Casillero**[cant_filas];

    for( i=0; i < cant_filas; i++)
    {
        mapa[i] = new Casillero*[cant_columnas];
    }
    
    for ( i = 0; i < cant_filas-1;i++) {
        for ( j = 0; j < cant_columnas-1; j++) {
            
            archivo_edificios >> dato;

            for( opcion_casillero = 0; diccionario_casilleros[opcion_casillero]!=dato; opcion_casillero++){}

            switch( opcion_casillero){

                case TRANSITABLE:{  
                    Casillero_Transitable * a = new Casillero_Transitable(dato, Coordenada(i,j), nullptr);
                    mapa[i][j] = a;
                    break;
                }

                case INACCESIBLE:{
                    Casillero_Inaccesible * b = new Casillero_Inaccesible(dato, Coordenada(i,j));
                    mapa[i][j] = b;
                    break;
                }

                case CONSTRUIBLE:{
                    Casillero_Construible * c = new Casillero_Construible(dato, Coordenada(i,j), nullptr);
                    mapa[i][j] = c;
                    break;
                }
            }
        }
    }
    archivo_edificios.close();
}

// Sobrecarga del operador << para imprimir Mapa en el flujo de salida indicado
// Pre: El Mapa debe estar bien formado y el flujo de salida abierto previamente
// Post: Un flujo de salida donde se imprimio la informacion de la clase
ostream& operator<<(ostream& os, const Mapa& aux){
    
    for ( int i = 0; i < aux.cant_filas -1; i++) {
        for (  int j = 0; j < aux.cant_columnas -1; j++) {
                aux.mapa[i][j]->Mostrar(os);
        }
        cout << endl;
    }
    cout << endl;
    return os;

}

// Verifica si los valores de la coordenada estan dentro de los limites de la matriz
// Pre: El objeto Coordenada debe estar bien formado
// Post: Un booleano que identifica si la coordenada esta dentro de la matriz
bool Mapa::consultar_limites_mapa(Coordenada ubicacion){
    
    if( ubicacion.GetHorizontal() < 0 || ubicacion.GetHorizontal() > cant_columnas){
        cout << " La coordenada izquierda esta fuera del limite del mapa" << endl;
        return false;
    }
    else if( ubicacion.GetVertical() < 0 || ubicacion.GetVertical() > cant_filas ){
        cout << " La coordenada derecha esta fuera del limite del mapa" << endl;
        return false;
    }
    else{
        return true;
    }
}

// Verifica si los valores de la coordenada dentro del mapa ubican a un casillero construible
// Pre: El objeto Coordenada debe estar bien formado
// Post: Un booleano que identifica si la coordenada corresponde dentro de la matriz a un casillero construible
bool Mapa::consultar_ubicacion_construible( Coordenada ubicacion){
    if(mapa[ubicacion.GetHorizontal()][ubicacion.GetVertical()]->get_data() != CASILLERO_CONSTRUIBLE ){
        cout << " El casillero no puede ser utilizado para construir o demoler edificios" << endl;
        return false;
    }
    else{
        return true;
    }
}

// Consulta al usuario por una coordenada particular que sera utilizada para ubicar un casillero del mapa
// Pre: -
// Post: Una coordenada que sera utilizada en el mapa
Coordenada Mapa::obtener_ubicacion(){

    string coordenada_izquierda, coordenada_derecha;

    cout << "Ingresar la ubicacion" << endl;
    cout << "coordenada izquierda: ";
    cin >> coordenada_izquierda;
    cout << endl;
    cout << "coordenada derecha: " ;
    cin >> coordenada_derecha;

    Coordenada aux(coordenada_izquierda, coordenada_derecha);

    return aux;
}

// Consulta la informacion que esta contenida en el casillero que identificara al mismo
// Pre: -
// Post: -
void Mapa::consultar_informacion_casillero(){
    Coordenada ubicacion_a_demoler;

    ubicacion_a_demoler = obtener_ubicacion();
    if(consultar_limites_mapa(ubicacion_a_demoler) == true){
        (mapa[ubicacion_a_demoler.GetHorizontal()][ubicacion_a_demoler.GetVertical()])->consultar_casillero();
    }
}

// Recorre la matriz de forma lineal, si identifica un casillero transitable ejecuta la funcion que genra materiales de 
// forma aleatoria para generar una lluvia de recursos dentro del mapa de forma aleatoria
// Pre: -
// Post: -
void Mapa::lluvia_recursos(){
    Material * aux = nullptr;

    for ( int i = 0; i < cant_filas -1; i++) {
        for (  int j = 0; j < cant_columnas -1; j++) {
                if( mapa[i][j]->get_data()==CASILLERO_TRANSITABLE){
                    mapa[i][j]->set_material(aux->generar_material_random());
                }
        }
    }   
}

// Guarda los valores y las dimensiones del mapa formado por una matriz
// Pre: String que identifica al archivo que sera utilizado como flujo de salida
// Post: -
void Mapa:: guardar( const string &output ) {
    ofstream edificios_archivo(output, ios::trunc);

    if (edificios_archivo.is_open()) {
        edificios_archivo << cant_filas << " " << cant_columnas << endl;
        for ( int i = 0; i < cant_filas -1; i++) {
            for (  int j = 0; j < cant_columnas -1; j++) {
                    mapa[i][j]->Mostrar(edificios_archivo);
                    edificios_archivo << " ";
            }
            edificios_archivo << endl;
        }
    
        edificios_archivo.close();
    }
    else {
        cout << TXT_RED_196 << "No se pudo abrir el archivo" << END_COLOR << endl;
    }
	
}

// Guarda los materiales contenidos en los casilleros transitables del mapa
// Pre: String que identifica al archivo que sera utilizado como flujo de salida
// Post: -
void Mapa:: guardar_materiales( const string &output ) {
    ofstream edificios_archivo(output, ios::app);

    if (edificios_archivo.is_open()) {
        for ( int i = 0; i < cant_filas -1; i++) {
            for (  int j = 0; j < cant_columnas -1; j++) {
                if( mapa[i][j]->get_data() == CASILLERO_TRANSITABLE && mapa[i][j]->get_material()!= nullptr) {
                    edificios_archivo << mapa[i][j]->get_material()->get_nombre() << " " << "(" << i << ',' << " " << j << ")" << endl;
                }
            }
        }
        edificios_archivo.close();
    }
    else {
        cout << TXT_RED_196 << "No se pudo abrir el archivo" << END_COLOR << endl;
    }
	
}