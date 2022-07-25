#include "Registro_Edificio.h"

// Aumenta la cantidad de edifcios que puede almacenar el registro de edificios
// Pre:-
// Post: -
void Registro_Edificio::resize(){

    int j, aux_cantidad;
    Edificio** aux_datos;

    aux_cantidad = ++cantidad;
    aux_datos = new Edificio*[aux_cantidad];
            
    for( j=0; j < cantidad; j++){
        aux_datos[j] = registro_edificios[j];
    }
            
    cantidad = aux_cantidad;
    delete [] registro_edificios;
    registro_edificios = aux_datos;
}

// Carga los datos del archivo de entrada pasado como string a los atributos de la clase registro de edificios
// Pre: El stringo que se pasa como argumento debe contener la ruta del archivo de donde se obtiene los datos de los edifcios
// Post: -
void Registro_Edificio::cargar_data_edificio(const string &input) {

    fstream archivo_edificios(input, ios::in);

    if (!archivo_edificios.is_open()) {
		cout << BGND_LIGHT_PINK_203 << "No se encontro ningun archivo con el nombre " << input << END_COLOR << endl;
    }

    string nombre;
    int cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos;
    int i;
    Edificio* edif;
      

    for( i=0; archivo_edificios >> nombre; i++) {
        if(nombre == PRIMER_NOMBRE_PLANTA_ELECTRICA){
            string segundo_nombre;
            archivo_edificios >> segundo_nombre;
            nombre = nombre + " " + segundo_nombre;
        }
        archivo_edificios >> cantidad_piedra;
        archivo_edificios >> cantidad_madera;
        archivo_edificios >> cantidad_metal;
        archivo_edificios >> maxima_cantidad_permitidos;

        if( i ==cantidad){
            resize();
        }

        edif = obtener_edificio_por_nombre(nombre, cantidad_piedra, cantidad_madera, cantidad_metal, maxima_cantidad_permitidos);
        registro_edificios[i] = edif;
    }

    archivo_edificios.close();
}

// Carga las ubicaciones del archivo de entrada pasado como string a los edificios ya formados en el registro de edificios
// Pre: El string que se pasa como argumento debe contener la ruta del archivo de donde se obtiene la ubicacion de los edifcios construidos
// Post: -
void Registro_Edificio::cargar_ubicacion_edificio(const string &input, Mapa &mapa_edificios) {

    fstream archivo_edificios(input, ios::in);

    if (!archivo_edificios.is_open()) {
		cout << BGND_LIGHT_PINK_203 << "No se encontro ningun archivo con el nombre " << input << END_COLOR << endl;
    }

    string nombre, coord_derecha, coord_izquierda, derecha, izquierda;
    int i;
    

    for( i=0; archivo_edificios >> nombre; i++) {
        archivo_edificios >> coord_izquierda;
        archivo_edificios >> coord_derecha;

        derecha = coord_derecha[0];
        izquierda = coord_izquierda[1];
        
        Coordenada coord(izquierda, derecha);

        int pos_edificio = buscar_pos_edificio(nombre);

        registro_edificios[pos_edificio]->set_ubicacion(coord,registro_edificios[pos_edificio]->get_construidos());

        registro_edificios[pos_edificio]->set_construidos(registro_edificios[pos_edificio]->get_construidos() +1 );

        (mapa_edificios.get_mapa()[coord.GetHorizontal()][coord.GetVertical()])->set_edificio( registro_edificios[pos_edificio]);
    }

    archivo_edificios.close();
}

// Recorre el registro de edificios para hallar la posicion en el registro del edificio precizado
// Pre: El nombre del edificio cuya posicion es buscada
// Post: Posicion del edificio en el registro
int Registro_Edificio::buscar_pos_edificio(string nombre_edificio_ingresado) {
    int posicion_edificio_ingresado = ERROR;

    for (int i = 0; i < cantidad; i++) {
        if (registro_edificios[i]->get_nombre() == nombre_edificio_ingresado) {
            posicion_edificio_ingresado = i;
        }
    }
    return posicion_edificio_ingresado;
}

// Recorre el registro de edificios para hallar la ubicacion en el registro del edificio precizado
// Pre: El nombre del edificio cuya ubicacion es buscada
// Post: Ubicacion del edificio en el registro
int Registro_Edificio::buscar_ubicacion_edificio(Coordenada ubicacion, int pos_edificio) {
    int ubicacion_edificio_ingresado = ERROR;

    for (int i = 0; i < registro_edificios[pos_edificio]->get_construidos(); i++) {
        if (registro_edificios[pos_edificio]->get_ubicacion()[i] == ubicacion) {
            ubicacion_edificio_ingresado = i;
        }
    }
    return ubicacion_edificio_ingresado;
}

// Recorre el registro de edificios para borrar la ubicacion en el registro del edificio precizado
// Pre: El nombre del edificio cuya ubicacion es buscada
// Post: -
void Registro_Edificio::borrar_ubicacion_edificio(Coordenada ubicacion, int pos_edificio) {
    int ubicacion_edificio_ingresado = ERROR;

    for (int i = 0; i < registro_edificios[pos_edificio]->get_maxpermitida(); i++) {
        if (registro_edificios[pos_edificio]->get_ubicacion()[i] == ubicacion) {
            ubicacion_edificio_ingresado = i;
            break;
        }
    }

    for (int i = ubicacion_edificio_ingresado; i < registro_edificios[pos_edificio]->get_maxpermitida(); i++) {
            registro_edificios[pos_edificio]->get_ubicacion()[i] = registro_edificios[pos_edificio]->get_ubicacion()[i+1];
    }

}

// Recorre el registro de edificios para comparar los materiales que precisa el edificio con los 
// los materiales que contiene el registro de materiales 
// Pre: El registro de materiales, la posicion del edificio que se quiere construir y la posicion de cada material en el registro
// Post:Retorna un booleano afirmativo en caso de poder construir el edificio
bool Registro_Edificio::consultar_recursos_construccion( Registro_Material &registro_material, int pos_edificio, int pos_piedra, int pos_madera, int pos_metal){
    
    if ( pos_edificio == ERROR) {
        cout << TXT_RED_196 << "El edificio que desea construir no existe" << END_COLOR << endl;
        return false;
    }
    
    else if ( registro_edificios[pos_edificio]->get_construidos() >= registro_edificios[pos_edificio]->get_maxpermitida()  ){
        cout << TXT_RED_196 << "Se ha superado el máximo de construcciones permitidas del edificio que desea construir" << END_COLOR << endl;
        return false;
    }
    else if ( registro_edificios[pos_edificio]->get_piedra() > registro_material.get_registro()[pos_piedra]->get_cantidad() ) {
        cout << TXT_RED_196 << "El edificio seleccionado no puede ser construído ya que no hay suficiente piedra" << END_COLOR << endl;
        return false;
    }
    else if ( registro_edificios[pos_edificio]->get_madera() > registro_material.get_registro()[pos_madera]->get_cantidad() ) {
        cout << TXT_RED_196 << "El edificio seleccionado no puede ser construído ya que no hay suficiente madera" << END_COLOR << endl;
        return false;
    }
    else if ( registro_edificios[pos_edificio]->get_metal() > registro_material.get_registro()[pos_metal]->get_cantidad() ) {
        cout << TXT_RED_196 << "El edificio seleccionado no puede ser construído ya que no hay suficiente metal" << END_COLOR << endl;
        return false;
    }
    else 
        return true;
}

// Crea un objeto edificio segun el nombre que es pasado por parametro
// Pre: El nombre del edificio que se desea construir junto con los valores de los atributos de la clase Edificio
// Post: Objeto Edificio bien formado
Edificio* Registro_Edificio::obtener_edificio_por_nombre( string nombre, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maxima_cantidad_permitidos){
    Edificio* edif;
    int opcion_nombre;
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

    return edif;
}

// Construye un edificio en el registro de edificio verificando los materiales en el registro de materiales y lo ubica en el mapa
// Pre: Registro de edifcios, registro de materiales y mapa bien caergados. Nombre del edificio que se desea construir
// Post: -
void Registro_Edificio::construir_edificio(string nombre_edificio_cons, Registro_Material &registro_material,Mapa &mapa_edificios) {
    Coordenada ubicacion;

    int pos_edificio = buscar_pos_edificio(nombre_edificio_cons); 

    int pos_piedra =  registro_material.buscar_pos_material(PIEDRA);
    int pos_madera = registro_material.buscar_pos_material(MADERA);
    int pos_metal = registro_material.buscar_pos_material(METAL);

    if( consultar_recursos_construccion(registro_material, pos_edificio, pos_piedra, pos_madera, pos_metal) == false){
        cout << TXT_RED_196 << "Se regresa al menu principal." << END_COLOR << endl;
        
    }
    else {
        bool confirmar_construccion = consultar_construccion();
        if (confirmar_construccion == true) {
            ubicacion = mapa_edificios.obtener_ubicacion();
            if( mapa_edificios.consultar_limites_mapa(ubicacion) == true && mapa_edificios.consultar_ubicacion_construible(ubicacion) == true){
                
                registro_material.get_registro()[pos_piedra]->set_cantidad( registro_material.get_registro()[pos_piedra]->get_cantidad() - registro_edificios[pos_edificio]->get_piedra() );
                registro_material.get_registro()[pos_madera]->set_cantidad( registro_material.get_registro()[pos_madera]->get_cantidad() - registro_edificios[pos_edificio]->get_madera() );
                registro_material.get_registro()[pos_metal]->set_cantidad( registro_material.get_registro()[pos_metal]->get_cantidad() - registro_edificios[pos_edificio]->get_metal() );


                registro_edificios[pos_edificio]->set_construidos(registro_edificios[pos_edificio]->get_construidos()+1);
                registro_edificios[pos_edificio]->set_ubicacion(ubicacion,registro_edificios[pos_edificio]->get_construidos()-1);

                (mapa_edificios.get_mapa()[ubicacion.GetHorizontal()][ubicacion.GetVertical()])->set_edificio( registro_edificios[pos_edificio]);

                cout << TXT_GREEN_118 << "Se ha construido exitosamente un edificio de tipo " << registro_edificios[pos_edificio]->get_nombre() << END_COLOR << endl;
            }
       }
    }

}

// Imprime por consola todos los edificios construidos contenidos en el registro de edificios
// Pre: -
// Post: - 
void Registro_Edificio::listar_edificios_contruidos() {

    cout << '\t' << BGND_DARK_GREEN_22 << "  Lista edificios construIdos    " << END_COLOR << endl;
    cout << '\t' << BGND_DARK_GREEN_22 << "  Se mostrarA con el formato:    " << END_COLOR << endl;
    cout << '\t' << BGND_DARK_GREEN_22 << "  nombre edificio, construIdos   " << END_COLOR << endl;    
    
    cout << "_______________________________________" << endl;
    for (int i = 0; i < cantidad ; i++) {
        if (registro_edificios[i]->get_construidos() > 0) {
            cout << registro_edificios[i]->get_nombre() << " "  << registro_edificios[i]->get_construidos()<<  " " ;
            for(int j=0; j<registro_edificios[i]->get_construidos(); j++) 
              cout<< registro_edificios[i]->get_ubicacion()[j] <<  " ";
            cout<<endl;
        }
    }     
    cout << "_______________________________________" << endl;
}

// Imprime por consola todos los edificios contenidos en el registro de edificios
// Pre: -
// Post: - 
void Registro_Edificio::listar_edificios_todos() {

    cout << '\t' << BGND_LIGHT_PURPLE_134 << " Lista de todos los edificios  " << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PURPLE_134 << " Se mostrara con el formato:    " << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PURPLE_134 << " *nombre edificio     " << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PURPLE_134 << " *cantidad de material requerido para hacerlo (piedra, madera, metal) " << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PURPLE_134 << " *construidos hasta el momento   " << END_COLOR << endl;
    cout << '\t' << BGND_LIGHT_PURPLE_134 << " *cantidad que se puede construir " << END_COLOR << endl;                    
    cout << '\t' << BGND_LIGHT_PURPLE_134 << " *material que brinda el edificio " << END_COLOR << endl;
    cout << "___________________________________________________________________________________" << endl;
    for (int i = 0; i < cantidad ; i++) {
        cout <<  registro_edificios[i]->get_nombre()<< " " ;
        cout <<  registro_edificios[i]->get_piedra()<< " "   ;
        cout <<  registro_edificios[i]->get_madera()<< " "  ;
        cout <<  registro_edificios[i]->get_metal() << " "  ;
        cout <<  registro_edificios[i]->get_construidos() << " "  ;
        cout <<  (registro_edificios[i]->get_maxpermitida() - registro_edificios[i]->get_construidos())<< " " ;
        
        Edificio* edificio_construido;
        edificio_construido = obtener_edificio_por_nombre(registro_edificios[i]->get_nombre());
        (*edificio_construido).cantidad_material_entregado();
        cout << " " << endl;
        cout << "___________________________________________________________________________________" << endl;


    }
}

// Destruye un edificio en el registro de edificio verificando los materiales en el registro de materiales y lo ubicacion en el mapa
// Pre: Registro de edifcios, registro de materiales y mapa bien caergados.
// Post: -
void Registro_Edificio:: demoler_edificio(Registro_Material &registro_materiales, Mapa &mapa_edificios) {
    Coordenada ubicacion_a_demoler;
    Edificio * edificio_a_demoler;

    ubicacion_a_demoler = mapa_edificios.obtener_ubicacion();
    if(mapa_edificios.consultar_limites_mapa(ubicacion_a_demoler) == true && mapa_edificios.consultar_ubicacion_construible(ubicacion_a_demoler) == true){
        edificio_a_demoler = (mapa_edificios.get_mapa()[ubicacion_a_demoler.GetHorizontal()][ubicacion_a_demoler.GetVertical()])->get_edificio();
        if( edificio_a_demoler != nullptr){
            int pos_edificio = buscar_pos_edificio(edificio_a_demoler->get_nombre()); 
            int pos_piedra =  registro_materiales.buscar_pos_material(PIEDRA);
            int pos_madera = registro_materiales.buscar_pos_material(MADERA);
            int pos_metal = registro_materiales.buscar_pos_material(METAL);

            if ( pos_edificio == ERROR) {
                cout << TXT_RED_196 << "El edificio que desea demoler no existe" << END_COLOR << endl;
            }
            else if (registro_edificios[pos_edificio]->get_construidos() == 0) {
                cout << TXT_RED_196 << "No es posible demoler el edificio debido a que no hay ninguna construcción de este tipo" << END_COLOR << endl;
            }

            else {

                registro_materiales.get_registro()[pos_piedra]->set_cantidad( registro_materiales.get_registro()[pos_piedra]->get_cantidad() + registro_edificios[pos_edificio]->get_piedra()/2 );
                registro_materiales.get_registro()[pos_madera]->set_cantidad( registro_materiales.get_registro()[pos_madera]->get_cantidad() + registro_edificios[pos_edificio]->get_madera()/2 );
                registro_materiales.get_registro()[pos_metal]->set_cantidad( registro_materiales.get_registro()[pos_metal]->get_cantidad() + registro_edificios[pos_edificio]->get_metal()/2 );

                registro_edificios[pos_edificio]->set_construidos( registro_edificios[pos_edificio]->get_construidos()-1 );
                borrar_ubicacion_edificio( ubicacion_a_demoler, pos_edificio );

                (mapa_edificios.get_mapa()[ubicacion_a_demoler.GetHorizontal()][ubicacion_a_demoler.GetVertical()])->set_edificio( nullptr);

                cout << TXT_GREEN_118 << "Se ha demolido exitosamente un edificio de tipo " << registro_edificios[pos_edificio]->get_nombre() << END_COLOR << endl;
            }
        }
        else{
            cout << TXT_RED_196 << "No existe un edificio en la ubicacion ingresada" << END_COLOR << endl;
        }
    }
    else{
        cout << TXT_RED_196 << "La ubicacion es incorrecta" << END_COLOR << endl;
    }
}

// Guarda los valores del registro de edifcios
// Pre: String que identifica al archivo que sera utilizado como flujo de salida
// Post: -
void Registro_Edificio:: guardar( const string &output ) {
    ofstream edificios_archivo(output, ios::trunc);

    if (edificios_archivo.is_open()) {
        for (int i = 0; i < cantidad ; i++) {
            edificios_archivo << (*registro_edificios[i]) << endl;
        }
        edificios_archivo.close();
    }
    else {
        cout << TXT_RED_196 << "No se pudo abrir el archivo" << END_COLOR << endl;
    }
	
}

// Guarda los nombres y la ubicacion de los edificios del registro
// Pre: String que identifica al archivo que sera utilizado como flujo de salida
// Post: -
void Registro_Edificio:: guardar_ubicacion( const string &output ) {
    ofstream edificios_archivo(output, ios::trunc);

    if (edificios_archivo.is_open()) {
        for (int i = 0; i < cantidad ; i++) {
            if (registro_edificios[i]->get_construidos()) {
                for(int j = 0; j < registro_edificios[i]->get_construidos(); j++) {
                    edificios_archivo << registro_edificios[i]->get_nombre() << " " << registro_edificios[i]->get_ubicacion()[j] << endl;
                }
            }
        }
        edificios_archivo.close();
    }
    else {
        cout << TXT_RED_196 << "No se pudo abrir el archivo" << END_COLOR << endl;
    }
	
}


// Pide al usuario por consola que ingrese el nombre del edificio que desea construir/destruir
// Pre: Nombre del edificio y accion a realizar
// Post: -
void Registro_Edificio::insertar_nombre_edificio(string accion, string* nombre_edificio_ingresado) {
    
    if (accion == DEMOLER) {
        cout << BGND_DARK_PINK_174 << "Ingrese el nombre del edificio que desea demoler"<< END_COLOR << endl;
        cin >> *nombre_edificio_ingresado;
        if(*nombre_edificio_ingresado == PRIMER_NOMBRE_PLANTA_ELECTRICA || *nombre_edificio_ingresado == NOMBRE_PLANTA_ELECTRICA){
            *nombre_edificio_ingresado = *nombre_edificio_ingresado + " " + "electrica";
        }

    }

    else {
        cout << BGND_DARK_PINK_174 << "Ingrese el nombre del edificio que desea construir"<< END_COLOR << endl;
        cin >> *nombre_edificio_ingresado;
        if(*nombre_edificio_ingresado == PRIMER_NOMBRE_PLANTA_ELECTRICA || *nombre_edificio_ingresado == NOMBRE_PLANTA_ELECTRICA){
            *nombre_edificio_ingresado = *nombre_edificio_ingresado + " " + "electrica";
        }
    }
    
}

// Confirma que el usuario desea construir un edifcio
// Pre: -
// Post: Retorna booleano afirmativo en caso de que el iusuario quiera construir
bool Registro_Edificio::consultar_construccion() {
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

// Recorre el registro de edificios para recolectar los recursos de aquellos edifcios construidos
// Pre: Registro de materiales bien cargado.
// Post: - 
void Registro_Edificio::recolectar_recursos_producidos(Registro_Material &registro_materiales) {
    for (int i = 0; i < cantidad; i++) {
        if (registro_edificios[i]->get_construidos())
            registro_edificios[i]->Recurso(registro_materiales);
    } 
}

