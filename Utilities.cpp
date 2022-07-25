#include "utilities.h"

void insertar_nombre_edificio(string accion, string* nombre_edificio_ingresado) {
    
    if (accion == DEMOLER) {
    cout << BGND_DARK_PINK_174 << "Ingrese el nombre del edificio que desea demoler"<< END_COLOR << endl;
    cin >> *nombre_edificio_ingresado;
    }

    else {
    cout << BGND_DARK_PINK_174 << "Ingrese el nombre del edificio que desea construir"<< END_COLOR << endl;
    cin >> *nombre_edificio_ingresado;
    }
    
}

int buscar_pos_edificio_ingresado(string nombre_edificio_ingresado, vector<Edificio*> &lista_de_edificios ) {
    int posicion_edificio_ingresado = ERROR;

    for (int i = 0; i < lista_de_edificios.get_cantidad(); i++) {
        if (lista_de_edificios[i]->get_nombre() == nombre_edificio_ingresado) {
            posicion_edificio_ingresado = i;
        }
    }

    return posicion_edificio_ingresado;
}

bool consultar_construccion() {
    bool confirmacion;
    int seleccion = ERROR;
    
    cout << BGND_DARK_PURPLE_96 << "¿Desea usted construir el edificio?" << END_COLOR << endl;
    cout << TXT_GREEN_118 << "\t (1) Si" << END_COLOR << endl;
    cout << TXT_RED_196  << "\t (2) No" << END_COLOR << endl;
    
    cin >> seleccion;
    switch (seleccion) {
        case 1:
                confirmacion = true;
                break;
        case 2:
                confirmacion = false;
                break;
    }
    
    return confirmacion;
}

void construir_edificio(string nombre_edificio_cons, vector<Material*> &lista_de_materiales,  vector<Edificio*> &lista_de_edificios) {
    int pos_edificio = buscar_pos_edificio_ingresado(nombre_edificio_cons,lista_de_edificios); 
    int pos_piedra =  buscar_pos_material(PIEDRA,lista_de_materiales);
    int pos_madera = buscar_pos_material(MADERA,lista_de_materiales);
    int pos_metal = buscar_pos_material(METAL,lista_de_materiales);

    if ( pos_edificio == ERROR) {
        cout << TXT_RED_196 << "El edificio que desea construir no existe" << END_COLOR << endl;
    }
    
    else if ( lista_de_edificios[pos_edificio]->get_construidos() >= lista_de_edificios[pos_edificio]->get_maxpermitida()  ){
        cout << TXT_RED_196 << "Se ha superado el máximo de construcciones permitidas del edificio que desea construir" << END_COLOR << endl;
    }
    else if ( lista_de_edificios[pos_edificio]->get_piedra() > lista_de_materiales[pos_piedra]->get_cantidad() ) {
         cout << TXT_RED_196 << "El edificio seleccionado no puede ser construído ya que no hay suficiente piedra" << END_COLOR << endl;
    }
    else if ( lista_de_edificios[pos_edificio]->get_madera() > lista_de_materiales[pos_madera]->get_cantidad() ) {
         cout << TXT_RED_196 << "El edificio seleccionado no puede ser construído ya que no hay suficiente madera" << END_COLOR << endl;
    }
    else if ( lista_de_edificios[pos_edificio]->get_metal() > lista_de_materiales[pos_metal]->get_cantidad() ) {
         cout << TXT_RED_196 << "El edificio seleccionado no puede ser construído ya que no hay suficiente metal" << END_COLOR << endl;
    }
    else {
        bool confirmar_construccion = consultar_construccion();
        if (confirmar_construccion == true) {
            lista_de_materiales[pos_piedra]->set_cantidad( lista_de_materiales[pos_piedra]->get_cantidad() - lista_de_edificios[pos_edificio]->get_piedra() );
            lista_de_materiales[pos_madera]->set_cantidad( lista_de_materiales[pos_madera]->get_cantidad() - lista_de_edificios[pos_edificio]->get_madera() );
            lista_de_materiales[pos_metal]->set_cantidad( lista_de_materiales[pos_metal]->get_cantidad() - lista_de_edificios[pos_edificio]->get_metal() );

            lista_de_edificios[pos_edificio]->set_construidos( lista_de_edificios[pos_edificio]->get_construidos()+1); 

            cout << TXT_GREEN_118 << "Se ha construído exitosamente un edificio de tipo " << lista_de_edificios[pos_edificio]->get_nombre() << END_COLOR << endl;
       }
    }

}

void listar_edificios_contruidos(vector<Edificio*> &lista_de_edificios) {
    cout << BGND_LIGHT_AQUA_85 << "╔═════════════════════════════════╗" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_85 << "║                                 ║" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_114 << "║  Lista edificios construídos    ║" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_114 << "║  Se mostrará con el formato:    ║" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_114 << "║  nombre edificio, construídos   ║" << END_COLOR << endl;    
    cout << BGND_LIGHT_AQUA_85 << "║                                 ║" << END_COLOR << endl;                       
	cout << BGND_LIGHT_AQUA_85 << "╚═════════════════════════════════╝" << END_COLOR << endl;
    
    cout << "_______________________________________" << endl;
    for (int i = 0; i < lista_de_edificios.get_cantidad() ; i++) {
        if (lista_de_edificios[i]->get_construidos() > 0) {
             cout << lista_de_edificios[i]->get_nombre() << ","  << lista_de_edificios[i]->get_construidos()<< endl;
        }
    }     
    cout << "_______________________________________" << endl;
}

void listar_edificios_todos(vector<Edificio*> &lista_de_edificios) {
    cout << BGND_LIGHT_YELLOW_186 << "╔═════════════════════════════════╗" << END_COLOR << endl;
    cout << BGND_LIGHT_YELLOW_191 << "║                                 ║" << END_COLOR << endl;
    cout << BGND_LIGHT_YELLOW_185 << "║   Lista de todos los edificios  ║" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_84 << "║  Se mostrará con el formato:    ║" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_85 << "║  nombre edificio|cantidad de    ║" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_49 << "║ material requerido para hacerlo ║" << END_COLOR << endl;
    cout << BGND_LIGHT_PURPLE_104 << "║   (piedra, madera, metal)       ║" << END_COLOR << endl;
    cout << BGND_LIGHT_PURPLE_105 << "║ construídos hasta el momento|   ║" << END_COLOR << endl;
    cout << BGND_LIGHT_PURPLE_133 << "║ cantidad que se puede construir ║" << END_COLOR << endl;
    cout << BGND_LIGHT_PURPLE_134 << "║ sin superar el máximo permitido ║" << END_COLOR << endl;   
    cout << BGND_LIGHT_PINK_203 << "║                                 ║" << END_COLOR << endl;                       
	cout << BGND_LIGHT_PINK_204 << "╚═════════════════════════════════╝" << END_COLOR << endl;
    
    cout << "_______________________________________" << endl;
    for (int i = 0; i < lista_de_edificios.get_cantidad() ; i++) {
        cout << (*lista_de_edificios[i]) << lista_de_edificios[i]->get_ubicacion() << endl;
    }
    cout << "_______________________________________" << endl;
}

void demoler_edificio(string nombre,vector<Material*> &lista_de_materiales,  vector<Edificio*> &lista_de_edificios) {
    int pos_edificio = buscar_pos_edificio_ingresado(nombre,lista_de_edificios); 
    int pos_piedra =  buscar_pos_material(PIEDRA,lista_de_materiales);
    int pos_madera = buscar_pos_material(MADERA,lista_de_materiales);
    int pos_metal = buscar_pos_material(METAL,lista_de_materiales);

    if ( pos_edificio == ERROR) {
        cout << TXT_RED_196 << "El edificio que desea demoler no existe" << END_COLOR << endl;
    }
    else if (lista_de_edificios[pos_edificio]->get_construidos() == 0) {
        cout << TXT_RED_196 << "No es posible demoler el edificio debido a que no hay ninguna construcción de este tipo" << END_COLOR << endl;
    }

    else { 

        lista_de_materiales[pos_piedra]->set_cantidad( lista_de_materiales[pos_piedra]->get_cantidad() + lista_de_edificios[pos_edificio]->get_piedra()/2 );
        lista_de_materiales[pos_madera]->set_cantidad( lista_de_materiales[pos_madera]->get_cantidad() + lista_de_edificios[pos_edificio]->get_madera()/2 );
        lista_de_materiales[pos_metal]->set_cantidad( lista_de_materiales[pos_metal]->get_cantidad() + lista_de_edificios[pos_edificio]->get_metal()/2 );

        lista_de_edificios[pos_edificio]->set_construidos( lista_de_edificios[pos_edificio]->get_construidos()-1 );

        cout << TXT_GREEN_118 << "Se ha demolido exitosamente un edificio de tipo " << lista_de_edificios[pos_edificio]->get_nombre() << END_COLOR << endl;
    }
    
}

void guardar_edificios( vector<Edificio*> &lista_de_edificios ) {
    ofstream edificios_archivo(RUTA_DATA_EDIFICIOS, ios::trunc);

    if (edificios_archivo.is_open()) {
        for (int i = 0; i < lista_de_edificios.get_cantidad() ; i++) {
            edificios_archivo << (*lista_de_edificios[i]) << endl;
        }
        edificios_archivo.close();
       
    }

    else {
        cout << TXT_RED_196 << "No se pudo abrir el archivo" << END_COLOR << endl;
    }
	
}

void cargar_data_edificio(vector<Edificio*> &lista) {

    fstream archivo_edificios( RUTA_DATA_EDIFICIOS, ios::in);

    if (!archivo_edificios.is_open()) {
		cout << BGND_LIGHT_PINK_203 << "No se encontro ningun archivo con el nombre " << RUTA_DATA_EDIFICIOS << END_COLOR << endl;
    }

    string nombre;
    int cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos;
    int i, opcion_nombre;
    Edificio* edif;
      

    for( i=0; archivo_edificios >> nombre; i++) {
        archivo_edificios >> cantidad_piedra;
        archivo_edificios >> cantidad_madera;
        archivo_edificios >> cantidad_metal;
        archivo_edificios >> maxima_cantidad_permitidos;

        if( i == lista.get_cantidad()){
            lista.resize();
        }

        for( opcion_nombre=0; nombres_edificios[opcion_nombre] != nombre; opcion_nombre++){}

        switch( opcion_nombre ){

            case ASERRADERO :
            	edif = new Aserradero( cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos);
                break;

            case FABRICA :
            	edif = new Fabrica( cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos);
                break;

            case ESCUELA :
            	edif = new Escuela( cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos);
                break;

            case YACIMIENTO :
            	edif = new Yacimiento( cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos);
                break;

            case OBELISCO :
            	edif = new Obelisco( cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos);
                break;
            
            case MINA :
            	edif = new Mina( cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos);
                break;

            case PLANTA_ELECTRICA:
            	edif = new Planta_Electrica( cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos);
                break;
            
            default:
            cout << TXT_RED_196 << "ERROR: LA OPCIÓN INGRESADA NO PERTENECE AL MENÚ" << END_COLOR << endl;
			break;
        }

        lista[i] = edif;
    }

    archivo_edificios.close();
}


void cargar_ubicacion_edificio(vector<Edificio*> &lista) {

    fstream archivo_edificios(RUTA_UBICACION_EDIFICIOS, ios::in);

    if (!archivo_edificios.is_open()) {
		cout << BGND_LIGHT_PINK_203 << "No se encontro ningun archivo con el nombre " << RUTA_UBICACION_EDIFICIOS << END_COLOR << endl;
    }

    string nombre, coord_derecha, coord_izquierda, derecha, izquierda;
    int i;
    

    for( i=0; archivo_edificios >> nombre; i++) {
        archivo_edificios >> coord_izquierda;
        archivo_edificios >> coord_derecha;

        derecha = coord_derecha[0];
        izquierda = coord_izquierda[1];
        
       coordenada coord(stoi(izquierda), stoi(derecha));

        int pos_edificio = buscar_pos_edificio_ingresado(nombre,lista);
        lista[pos_edificio]->set_ubicacion( coord );
    }

    archivo_edificios.close();
}
