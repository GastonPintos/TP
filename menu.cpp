#include "menu.h"

// Imprime las opciones del menu
// Pre: -
// Post: -
void mostrar_menu() {
    cout << '\t' << '\t'<< '\t'<< BGND_LIGHT_PINK_210 << "MENU" << END_COLOR << endl;

    cout << '\t' << BGND_BLUE_12  << " (1) Construir edificio por nombre         " << END_COLOR << endl;
    cout << '\t' << BGND_BLUE_12  << " (2) Listar los edificios construidos      " << END_COLOR << endl;
    cout << '\t' << BGND_BLUE_12  << " (3) Listar todos los edificios            " << END_COLOR << endl;
    cout << '\t' << BGND_BLUE_12  << " (4) Demoler un edificio por coordenada    " << END_COLOR << endl;
    cout << '\t' << BGND_BLUE_12  << " (5) Mostrar mapa                          " << END_COLOR << endl;
    cout << '\t' << BGND_BLUE_12  << " (6) Consultar coordenada                  " << END_COLOR << endl;
    cout << '\t' << BGND_BLUE_12  << " (7) Mostrar invetario                     " << END_COLOR << endl;
    cout << '\t' << BGND_BLUE_12  << " (8) Recolectar recursos producidos        " << END_COLOR << endl;
    cout << '\t' << BGND_BLUE_12  << " (9) Lluvia de recursos                    " << END_COLOR << endl;
    cout << '\t' << BGND_BLUE_12  << " (10) Guardar y salir                      " << END_COLOR << endl;

}

// Toma de la consola la opcion del menu 
// Pre: la opcion fue previamente inicializada
// Post: -
void pedir_opcion(int* opcion_elegida) {
    cout << BGND_DARK_PINK_174 << "Ingrese el numero correspondiente a la accion que desea realizar: " << END_COLOR << endl;
    cin >> *opcion_elegida;
}


// Valida la opcion tomada por consola  
// Pre: la opcion elegida por el usuario previamente
// Post: -
void validar_opcion_elegida(int* opcion_elegida) {
    bool es_opcion_elegida_valida = *opcion_elegida > 0 && *opcion_elegida <= CANTIDAD_DE_OPCIONES_VALIDAS;
    while (!es_opcion_elegida_valida) {
        cout << TXT_RED_124 << "La opción seleccionada no es válida, por favor elija otra opción del menú" << END_COLOR << endl;
        mostrar_menu();
        pedir_opcion(opcion_elegida);
        es_opcion_elegida_valida = *opcion_elegida > 0 && *opcion_elegida <= CANTIDAD_DE_OPCIONES_VALIDAS;
    }
}

// Procesa la opcion tomada por consola  
// Pre: Datos cargados de materailes, edificios y el mapa que son pasados como parametros y la opcion elegida por el usuario
// Post: -
void procesar_opcion_elegida(Registro_Material &registro_material, Registro_Edificio &registro_edificio, int *opcion,Mapa &mapa_edificios) {
    
    switch (*opcion) {

        //LISTO - Sbien
        case CONSTRUIR_EDIFICIO_POR_NOMBRE:{
            string nombre_edificio_a_construir;
            registro_edificio.insertar_nombre_edificio(CONSTRUIR, &nombre_edificio_a_construir);
            registro_edificio.construir_edificio(nombre_edificio_a_construir, registro_material, mapa_edificios);
        }
            break;
        
        //LISTO - bien
        case LISTAR_LOS_EDIFICIOS_CONSTRUIDOS:
            registro_edificio.listar_edificios_contruidos();
            break;

        //LISTO - bien
        case LISTAR_TODOS_LOS_EDIFICIOS:
            registro_edificio.listar_edificios_todos();
            break;

        // LISTO - bien
        case DEMOLER_UN_EDIFICIO_POR_COORDENADA:
            registro_edificio.demoler_edificio( registro_material, mapa_edificios);
            break;

        //LISTO - bien
        case MOSTRAR_MAPA:
            cout << mapa_edificios;
            break;

        //LISTO  - bien
        case CONSULTAR_COORDENADA:
            mapa_edificios.consultar_informacion_casillero();
            break;

        //LISTO  - bien
        case MOSTRAR_INVENTARIO:
            registro_material.listar_materiales_de_construccion();
            break;

        //LISTO - bien
        case RECOLECTAR_RECURSOS_PRODUCIDOS:
            registro_edificio.recolectar_recursos_producidos(registro_material);
            break;

        //FALTA
        case LLUVIA_DE_RECURSOS:
            mapa_edificios.lluvia_recursos();
            break;

        //LISTO
        case GUARDAR_Y_SALIR:
            registro_material.guardar(RUTA_MATERIALES);
            registro_edificio.guardar(RUTA_DATA_EDIFICIOS);
            registro_edificio.guardar_ubicacion(RUTA_UBICACION_EDIFICIOS);
            mapa_edificios.guardar(RUTA_CASILLEROS_MAPA);
            mapa_edificios.guardar_materiales(RUTA_UBICACION_EDIFICIOS);
            *opcion = SALIR;
            break;

        case SALIR:
            break;

        default:
            cout << TXT_RED_196 << "ERROR: LA OPCIÓN INGRESADA NO PERTENECE AL MENÚ" << END_COLOR << endl;
			break;
    }
}

