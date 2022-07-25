#include "main.h"

int main() {
   int opcion = 1; 

    Mapa mapa(RUTA_CASILLEROS_MAPA);

    Registro_Edificio registro_edificio(CANTIDAD_INICIAL);
    Registro_Material registro_material(CANTIDAD_INICIAL);

    registro_material.cargar_material(RUTA_MATERIALES);
    registro_edificio.cargar_data_edificio(RUTA_DATA_EDIFICIOS);
    registro_edificio.cargar_ubicacion_edificio(RUTA_UBICACION_EDIFICIOS, mapa);

    while (opcion != SALIR) {
        mostrar_menu();
	    pedir_opcion(&opcion);
		validar_opcion_elegida(&opcion);
	    procesar_opcion_elegida(registro_material, registro_edificio, &opcion, mapa);
    }

    return 0;
}