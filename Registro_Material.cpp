#include "Registro_Material.h"

// Carga los datos del archivo de entrada pasado como string a los atributos de la clase registro de materiales
// Pre: El string que se pasa como argumento debe contener la ruta del archivo de donde se obtiene los datos de los materiales
// Post: -
void Registro_Material::cargar_material(const string &input){

    fstream archivo_materiales(input, ios::in);

    if (!archivo_materiales.is_open()) {
		cout << BGND_LIGHT_PINK_203 << "No se encontro ningun archivo con el nombre " << input << END_COLOR << endl;
    }

    string nombre;
    int cantidad_material;
    int i;
    Material* mat;

    for( i=0; archivo_materiales >> nombre; i++) {
        archivo_materiales >> cantidad_material;

        if( i == cantidad){
            resize();
        }

        mat = new Material(nombre, cantidad_material);
        registro_material[i] = mat;
    }
    archivo_materiales.close();
}

// Aumenta la cantidad de edifcios que puede almacenar el registro de materiales
// Pre:-
// Post: -
void Registro_Material::resize(){

    int j, aux_cantidad;
    Material** aux_datos;

    aux_cantidad = ++cantidad;
    aux_datos = new Material*[aux_cantidad];
            
    for( j=0; j < cantidad; j++){
        aux_datos[j] = registro_material[j];
    }
            
    cantidad = aux_cantidad;
    delete [] registro_material;
    registro_material = aux_datos;
}

// Guarda los valores del registro de materiales
// Pre: String que identifica al archivo que sera utilizado como flujo de salida
// Post: -
void Registro_Material::guardar(const string &output) {
    ofstream materiales_archivo(RUTA_MATERIALES, ios::trunc);

    if (materiales_archivo.is_open()) {
        for (int i = 0; i < cantidad; i++) {
        materiales_archivo << (*registro_material[i]) << endl;
        }
        materiales_archivo.close();
    }

    else {
        cout << TXT_RED_196 << "No se pudo abrir el archivo" << END_COLOR << endl;
    }
    
}

// Recorre el registro de materiales para hallar la posicion en el registro del material precizado
// Pre: El nombre del material cuya posicion es buscada
// Post: Posicion del material en el registro
int Registro_Material::buscar_pos_material(string nombre_material) {
    int posicion_material = ERROR;

    for (int i = 0; i < cantidad; i++) {
        if (registro_material[i]->get_nombre() == nombre_material ) {
            posicion_material = i;
        }
    }
    return posicion_material;
}

// Imprime por consola todos los materiales contenidos en el registro de materiales
// Pre: -
// Post: - 
void Registro_Material::listar_materiales_de_construccion() {


    cout << '\t' << BGND_DARK_PURPLE_90 << "    Listado de materiales        " << END_COLOR << endl;
    cout << '\t' << BGND_DARK_PURPLE_90 << "  Se mostrara con el formato:    " << END_COLOR << endl;
    cout << '\t' << BGND_DARK_PURPLE_90 << "     material   [cantidad]       " << END_COLOR << endl;    

    
    cout << "_______________________________________" << endl;

    for (int i = 0; i < cantidad; i++) 
        cout << (*registro_material[i])<< endl;
    cout << "_______________________________________" << endl;
}
