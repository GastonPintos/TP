#include "utiles.h"

void mostrar_menu() {
    cout << '\t' << '\t'<< '\t'<< BGND_LIGHT_PINK_210 << "MENU" << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PINK_168 << "╔═══════════════════════════════════════╗" << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PINK_168 << "║ (1) Listar materiales de construccion ║" << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PINK_168 << "║ (2) Construir edificio por nombre     ║" << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PINK_168 << "║ (3) Listar los edificios construidos  ║" << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PINK_168 << "║ (4) Listar todos los edificios        ║" << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PINK_168 << "║ (5) Demoler un edificio por nombre    ║" << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PINK_168 << "║ (6) Guardar y salir                   ║" << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PINK_168 << "╚═══════════════════════════════════════╝" << END_COLOR << endl;
}

void pedir_opcion(int* opcion_elegida) {
    cout << BGND_DARK_PINK_174 << "Ingrese el número correspondiente a la acción que desea realizar: " << END_COLOR << endl;
    cin >> *opcion_elegida;
}


void validar_opcion_elegida(int* opcion_elegida) {
    bool es_opcion_elegida_valida = *opcion_elegida > 0 && *opcion_elegida <= CANTIDAD_DE_OPCIONES_VALIDAS;
    while (!es_opcion_elegida_valida) {
        cout << TXT_RED_124 << "La opción seleccionada no es válida, por favor elija otra opción del menú" << END_COLOR << endl;
        mostrar_menu();
        pedir_opcion(opcion_elegida);
        es_opcion_elegida_valida = *opcion_elegida > 0 && *opcion_elegida <= CANTIDAD_DE_OPCIONES_VALIDAS;
    }
}

void listar_materiales_de_construccion(vector<material*> &lista_de_materiales) {

    cout << BGND_DARK_PURPLE_96 << "╔═════════════════════════════════╗" << END_COLOR << endl;
    cout << BGND_DARK_PURPLE_96 << "║                                 ║" << END_COLOR << endl;
    cout << BGND_DARK_PURPLE_90 << "║    Listado de materiales        ║" << END_COLOR << endl;
    cout << BGND_DARK_PURPLE_90 << "║  Se mostrará con el formato:    ║" << END_COLOR << endl;
    cout << BGND_DARK_PURPLE_90 << "║     material[cantidad]          ║" << END_COLOR << endl;    
    cout << BGND_DARK_PURPLE_96 << "║                                 ║" << END_COLOR << endl;                       
	cout << BGND_DARK_PURPLE_96 << "╚═════════════════════════════════╝" << END_COLOR << endl;
    
    cout << "_______________________________________" << endl;

    for (int i = 0; i < lista_de_materiales.GetCantidad(); i++) 
        cout << (*lista_de_materiales[i])<< endl;
    cout << "_______________________________________" << endl;
}

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

int buscar_pos_edificio_ingresado(string nombre_edificio_ingresado, vector<edificio*> &lista_de_edificios ) {
    int posicion_edificio_ingresado = ERROR;

    for (int i = 0; i < lista_de_edificios.GetCantidad(); i++) {
        if (lista_de_edificios[i]->GetNombre() == nombre_edificio_ingresado) {
            posicion_edificio_ingresado = i;
        }
    }

    return posicion_edificio_ingresado;
}

int buscar_pos_material(string nombre_material_a_buscar, vector<material*> &lista_de_materiales) {
    int posicion_material = ERROR;

    for (int i = 0; i < lista_de_materiales.GetCantidad(); i++) {
        if (lista_de_materiales[i]->GetNombre() == nombre_material_a_buscar ) {
            posicion_material = i;
        }
    }

    return posicion_material;
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

void construir_edificio(string nombre_edificio_cons, vector<material*> &lista_de_materiales,  vector<edificio*> &lista_de_edificios) {
    int pos_edificio = buscar_pos_edificio_ingresado(nombre_edificio_cons,lista_de_edificios); 
    int pos_piedra =  buscar_pos_material(PIEDRA,lista_de_materiales);
    int pos_madera = buscar_pos_material(MADERA,lista_de_materiales);
    int pos_metal = buscar_pos_material(METAL,lista_de_materiales);

    if ( pos_edificio == ERROR) {
        cout << TXT_RED_196 << "El edificio que desea construir no existe" << END_COLOR << endl;
    }
    
    else if ( lista_de_edificios[pos_edificio]->GetConstruidos() >= lista_de_edificios[pos_edificio]->GetMaxCantPerimitida()  ){
        cout << TXT_RED_196 << "Se ha superado el máximo de construcciones permitidas del edificio que desea construir" << END_COLOR << endl;
    }
    else if ( lista_de_edificios[pos_edificio]->GetPiedra() > lista_de_materiales[pos_piedra]->GetCantidad() ) {
         cout << TXT_RED_196 << "El edificio seleccionado no puede ser construído ya que no hay suficiente piedra" << END_COLOR << endl;
    }
    else if ( lista_de_edificios[pos_edificio]->GetMadera() > lista_de_materiales[pos_madera]->GetCantidad() ) {
         cout << TXT_RED_196 << "El edificio seleccionado no puede ser construído ya que no hay suficiente madera" << END_COLOR << endl;
    }
    else if ( lista_de_edificios[pos_edificio]->GetMetal() > lista_de_materiales[pos_metal]->GetCantidad() ) {
         cout << TXT_RED_196 << "El edificio seleccionado no puede ser construído ya que no hay suficiente metal" << END_COLOR << endl;
    }
    else {
        bool confirmar_construccion = consultar_construccion();
        if (confirmar_construccion == true) {
            lista_de_materiales[pos_piedra]->SetCantidad( lista_de_materiales[pos_piedra]->GetCantidad() - lista_de_edificios[pos_edificio]->GetPiedra() );
            lista_de_materiales[pos_madera]->SetCantidad( lista_de_materiales[pos_madera]->GetCantidad() - lista_de_edificios[pos_edificio]->GetMadera() );
            lista_de_materiales[pos_metal]->SetCantidad( lista_de_materiales[pos_metal]->GetCantidad() - lista_de_edificios[pos_edificio]->GetMetal() );

            lista_de_edificios[pos_edificio]->SetConstruidos( lista_de_edificios[pos_edificio]->GetConstruidos()+1); 

            cout << TXT_GREEN_118 << "Se ha construído exitosamente un edificio de tipo " << lista_de_edificios[pos_edificio]->GetNombre() << END_COLOR << endl;
       }
    }

}

void listar_edificios_contruidos(vector<edificio*> &lista_de_edificios) {
    cout << BGND_LIGHT_AQUA_85 << "╔═════════════════════════════════╗" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_85 << "║                                 ║" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_114 << "║  Lista edificios construídos    ║" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_114 << "║  Se mostrará con el formato:    ║" << END_COLOR << endl;
    cout << BGND_LIGHT_AQUA_114 << "║  nombre edificio, construídos   ║" << END_COLOR << endl;    
    cout << BGND_LIGHT_AQUA_85 << "║                                 ║" << END_COLOR << endl;                       
	cout << BGND_LIGHT_AQUA_85 << "╚═════════════════════════════════╝" << END_COLOR << endl;
    
    cout << "_______________________________________" << endl;
    for (int i = 0; i < lista_de_edificios.GetCantidad() ; i++) {
        if (lista_de_edificios[i]->GetConstruidos() > 0) {
             cout << lista_de_edificios[i]->GetNombre() << ","  << lista_de_edificios[i]->GetConstruidos()<< endl;
        }
    }     
    cout << "_______________________________________" << endl;
}

void listar_edificios_todos(vector<edificio*> &lista_de_edificios) {
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
    for (int i = 0; i < lista_de_edificios.GetCantidad() ; i++) {
        cout << (*lista_de_edificios[i])<<endl;
    }
    cout << "_______________________________________" << endl;
}

void demoler_edificio(string nombre,vector<material*> &lista_de_materiales,  vector<edificio*> &lista_de_edificios) {
    int pos_edificio = buscar_pos_edificio_ingresado(nombre,lista_de_edificios); 
    int pos_piedra =  buscar_pos_material(PIEDRA,lista_de_materiales);
    int pos_madera = buscar_pos_material(MADERA,lista_de_materiales);
    int pos_metal = buscar_pos_material(METAL,lista_de_materiales);

    if ( pos_edificio == ERROR) {
        cout << TXT_RED_196 << "El edificio que desea demoler no existe" << END_COLOR << endl;
    }
    else if (lista_de_edificios[pos_edificio]->GetConstruidos() == 0) {
        cout << TXT_RED_196 << "No es posible demoler el edificio debido a que no hay ninguna construcción de este tipo" << END_COLOR << endl;
    }

    else { 

        lista_de_materiales[pos_piedra]->SetCantidad( lista_de_materiales[pos_piedra]->GetCantidad() + lista_de_edificios[pos_edificio]->GetPiedra()/2 );
        lista_de_materiales[pos_madera]->SetCantidad( lista_de_materiales[pos_madera]->GetCantidad() + lista_de_edificios[pos_edificio]->GetMadera()/2 );
        lista_de_materiales[pos_metal]->SetCantidad( lista_de_materiales[pos_metal]->GetCantidad() + lista_de_edificios[pos_edificio]->GetMetal()/2 );

        lista_de_edificios[pos_edificio]->SetConstruidos( lista_de_edificios[pos_edificio]->GetConstruidos()-1 );

        cout << TXT_GREEN_118 << "Se ha demolido exitosamente un edificio de tipo " << lista_de_edificios[pos_edificio]->GetNombre() << END_COLOR << endl;
    }
    
}


void guardar_materiales(vector<material*> &lista_de_materiales) {
    ofstream materiales_archivo(PATH_MATERIALES, ios::trunc);

    if (materiales_archivo.is_open()) {
        for (int i = 0; i < lista_de_materiales.GetCantidad(); i++) {
        materiales_archivo << (*lista_de_materiales[i]) << endl;
        }
        materiales_archivo.close();
    }

    else {
        cout << TXT_RED_196 << "No se pudo abrir el archivo" << END_COLOR << endl;
    }
    
}

void guardar_edificios( vector<edificio*> &lista_de_edificios ) {
    ofstream edificios_archivo(PATH_EDIFICIOS, ios::trunc);

    if (edificios_archivo.is_open()) {
        for (int i = 0; i < lista_de_edificios.GetCantidad() ; i++) {
            edificios_archivo << (*lista_de_edificios[i]) << endl;
        }
        edificios_archivo.close();
       
    }

    else {
        cout << TXT_RED_196 << "No se pudo abrir el archivo" << END_COLOR << endl;
    }
	
}

void guardar( vector<material*> &lista_de_materiales, vector<edificio*> &lista_de_edificios) {
    guardar_materiales( lista_de_materiales );
    guardar_edificios( lista_de_edificios );
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

        if( i == lista.GetCantidad()){
            lista.Resize();
        }

        mat = new material(nombre, cantidad);
        lista[i] = mat;
    }
    archivo_materiales.close();
}


void cargar_edificio(vector<edificio*> &lista) {

    fstream archivo_edificios(PATH_EDIFICIOS, ios::in);

    if (!archivo_edificios.is_open()) {
		cout << BGND_LIGHT_PINK_203 << "No se encontro ningun archivo con el nombre " << PATH_EDIFICIOS << END_COLOR << endl;
    }

    string nombre;
    int cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos;
    int i;
    edificio* edif;

    for( i=0; archivo_edificios >> nombre; i++) {
        archivo_edificios >> cantidad_piedra;
        archivo_edificios >> cantidad_madera;
        archivo_edificios >> cantidad_metal;
        archivo_edificios >> maxima_cantidad_permitidos;

        if( i == lista.GetCantidad()){
            lista.Resize();
        }
        
        edif = new edificio(nombre, cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos);
        
        lista[i] = edif;
    }

    archivo_edificios.close();
}


void procesar_opcion_elegida(vector<material*> &lista_de_materiales, vector<edificio*> &lista_de_edificios, int *opcion) {
    
    switch (*opcion) {
        case LISTAR_MATERIALES_DE_CONSTRUCCION: 
            listar_materiales_de_construccion(lista_de_materiales);
            break;

        case CONSTRUIR_EDIFICIO_POR_NOMBRE:
        {
            string nombre_edificio_a_construir;
            insertar_nombre_edificio(CONSTRUIR, &nombre_edificio_a_construir);
            construir_edificio(nombre_edificio_a_construir, lista_de_materiales, lista_de_edificios);
        }
            break;
      
        case LISTAR_LOS_EDIFICIOS_CONSTRUIDOS:
            listar_edificios_contruidos(lista_de_edificios);
            break;

        case LISTAR_TODOS_LOS_EDIFICIOS:
            listar_edificios_todos(lista_de_edificios);
            break;

        case DEMOLER_UN_EDIFICIO_POR_NOMBRE:
        {
            string nombre_edificio_a_demoler;
            insertar_nombre_edificio(DEMOLER, &nombre_edificio_a_demoler);
            demoler_edificio(nombre_edificio_a_demoler, lista_de_materiales, lista_de_edificios);
        }
            break;

        case GUARDAR_Y_SALIR:
            guardar(lista_de_materiales, lista_de_edificios);
            *opcion = SALIR;
            break;

        case SALIR:
            break;

        default:
            cout << TXT_RED_196 << "ERROR: LA OPCIÓN INGRESADA NO PERTENECE AL MENÚ" << END_COLOR << endl;
			break;
    }
}

