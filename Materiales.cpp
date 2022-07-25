#include "materiales.h"

void listar_materiales_de_construccion(vector<material*> &lista_de_materiales) {

    cout << BGND_DARK_PURPLE_96 << "╔═════════════════════════════════╗" << END_COLOR << endl;
    cout << BGND_DARK_PURPLE_96 << "║                                 ║" << END_COLOR << endl;
    cout << BGND_DARK_PURPLE_90 << "║    Listado de materiales        ║" << END_COLOR << endl;
    cout << BGND_DARK_PURPLE_90 << "║  Se mostrará con el formato:    ║" << END_COLOR << endl;
    cout << BGND_DARK_PURPLE_90 << "║     material[cantidad]          ║" << END_COLOR << endl;    
    cout << BGND_DARK_PURPLE_96 << "║                                 ║" << END_COLOR << endl;                       
	cout << BGND_DARK_PURPLE_96 << "╚═════════════════════════════════╝" << END_COLOR << endl;
    
    cout << "_______________________________________" << endl;

    for (int i = 0; i < lista_de_materiales.get_cantidad(); i++) 
        cout << (*lista_de_materiales[i])<< endl;
    cout << "_______________________________________" << endl;
}

int buscar_pos_material(string nombre_material_a_buscar, vector<material*> &lista_de_materiales) {
    int posicion_material = ERROR;

    for (int i = 0; i < lista_de_materiales.get_cantidad(); i++) {
        if (lista_de_materiales[i]->get_nombre() == nombre_material_a_buscar ) {
            posicion_material = i;
        }
    }

    return posicion_material;
}

void guardar_materiales(vector<material*> &lista_de_materiales) {
    ofstream materiales_archivo(PATH_MATERIALES, ios::trunc);

    if (materiales_archivo.is_open()) {
        for (int i = 0; i < lista_de_materiales.get_cantidad(); i++) {
        materiales_archivo << (*lista_de_materiales[i]) << endl;
        }
        materiales_archivo.close();
    }

    else {
        cout << TXT_RED_196 << "No se pudo abrir el archivo" << END_COLOR << endl;
    }
    
}

void cargar_material(vector<material*> &lista){

    fstream archivo_materiales(PATH_MATERIALES, ios::in);

    if (!archivo_materiales.is_open()) {
		cout << BGND_LIGHT_PINK_203 << "No se encontro ningun archivo con el nombre " << PATH_MATERIALES << END_COLOR << endl;
    }

    string nombre;
    int cantidad;
    int i;
    material* mat;

    for( i=0; archivo_materiales >> nombre; i++) {
        archivo_materiales >> cantidad;

        if( i == lista.get_cantidad()){
            lista.resize();
        }

        mat = new material(nombre, cantidad);
        lista[i] = mat;
    }
    archivo_materiales.close();
}




