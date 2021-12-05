#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>

struct fecha{
    int dia;
    int mes;
    int anio;
};



struct cliente{
    char apeNom[60];
    char domicilio[60];
    char localidad[60];
    char telefono[25];
    int dni;
    float peso;
};

struct turnos{
    int idProfesional;
    fecha fecTurno;
    int dniCliente;
    char detalleAtencion[380];
};

struct persona
{
	char usuario[10];
	char contrasenia [32];
	char apnom [60];
};

struct profesional{
    char apeNom[60];
    int idProfesional;
    int dni;
    char telefono[25];
    persona user;
};

//Declaracion de variables globales
bool login = false;
bool loop = true;


void menu();
void iniciarSesion();
void registroCliente();
void registrarTurno();
void listadoAtenciones();


int main(int argc, char const *argv[])
{
    system("mode con: cols=140 lines=30");
    system("COLOR F0");
    while (loop == true)
    {
        menu();
    }
    
    return 0;
}

void menu(){
    int opt;
    printf("\n\tModulo del recepcionista\n\t=========================\n\t1.- Iniciar Sesion\n\t2.- Registrar Cliente\n\t3.- Registrar Turno\n\t4.- Listado de Atenciones por Profesional y Fecha\n\t5.- Cerrar la aplicacion.\n\n\t\tIngrese una opcion: "  );
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        system("CLS");
        iniciarSesion();
        break;
    case 2:
        if (login == true)
            {
                system("cls");
                registroCliente();
            }
        else{
            system("cls");
            printf("\n\t\t\tNo inicio sesion.\t\n\n");
            system("pause");
            system("cls");
            menu();
        }
        break;
    case 3:
        if (login == true)
            {
                system("cls");
                registrarTurno();
            }
        else{
            system("cls");
            printf("\n\t\t\tNo inicio sesion.\t");
            menu();
        }
        break;
    case 4:
        if (login == true)
            {
                system("cls");
                listadoAtenciones();
            }
        else{
            system("cls");
            printf("\n\t\t\tNo inicio sesion.\t");
            menu();
        }
        break;
    case 5: loop=false;
        break;
    default:
        system("cls");
        menu();
        break;
    }
}

void iniciarSesion(){
    persona user, aux;
    FILE *arch1 = fopen ("Recepcionistas.dat", "a+b");
    printf("\n\n\t\t\t----------- Inicio de sesion -----------\n\n");
    _flushall();
    printf("\n\tUsuario: ");
    gets(user.usuario);
    printf("\tContraseña: ");
    gets(user.contrasenia);
    rewind(arch1);
    fread(&aux, sizeof(persona), 1, arch1);
    for(int i=0; !feof(arch1); i++){
        if(strcmp(user.usuario, aux.usuario)==0){ //compara si el usuario ingresado ya existe
            if(strcmp(user.contrasenia, aux.contrasenia)==0){ //compara si el usuario ingresado ya existe
                login = true;
                fclose(arch1);
                system("cls");
                printf("¡Bienvenido %s!", aux.apnom);
                menu();
            }
        }
        fread(&aux, sizeof(persona), 1, arch1);
    }
    system("cls");
    printf("Usuario inexistente.");
    iniciarSesion();
}
        
void registroCliente(){
    FILE *arch=fopen("Clientes.dat", "a+b");
    cliente aux, client;
    bool band=false;
    do{
        band=false;
        system("cls");
        printf("Ingrese el dni del cliente: ");
        scanf("%d", &client.dni);
        rewind(arch);
        fread(&aux, sizeof(cliente), 1, arch);
            for(int i=0; !feof(arch); i++){
                if(client.dni == aux.dni){ //compara si el usuario ingresado ya existe
    				band=true;
                    break;
                }
                fread(&aux, sizeof(cliente), 1, arch);
            }
                if(band){
                    printf("\nEl cliente ya existe\n");
                    band=false;
                    system("pause>nul");
                    system("cls");
                    break;
                }else{
                    _flushall();
                    printf("\nIngrese Apellido y Nombre :");
                    gets(client.apeNom);
                    printf("\nIngrese su Domicilio: ");
                    gets(client.domicilio);
                    printf("Ingrese su Localidad: ");
                    gets(client.localidad);
                    printf("\nIngrese su peso: ");
                    scanf("%f", &client.peso);
                    _flushall();
                    printf("\nIngrese numero de telefono: ");
                    gets(client.telefono);
                    fseek(arch, sizeof(cliente), SEEK_END);
                    fwrite(&client, sizeof(cliente), 1, arch);
                    fclose(arch);
                }
    }while(band==true);
    system("pause");
    system("cls");
}

void registrarTurno(){
    turnos reg;
    profesional prof, aux;
    cliente client, aux1;
    bool verifProfesional=false, verifCliente=false;
    FILE *arch=fopen("Turnos.dat", "a+b");
    FILE *arch1=fopen("Clientes.dat", "r");
    FILE *arch2=fopen("Profesionales.dat", "r");
    printf("\n\t\t============ Regsitrar Turno ===========\n\n");
    printf("\n\t\tIngrese el id del Profesional: ");
    scanf("%d", &prof.idProfesional);
    rewind(arch2);
    fread(&aux, sizeof(profesional), 1, arch2);
        for (int i = 0; !feof(arch2); i++){
            if(prof.idProfesional==aux.idProfesional){
            	verifProfesional=true;
            	break;
			}
            fread(&aux, sizeof(profesional), 1, arch2);
        }
            if(verifProfesional){
                printf("\n\t\tIngrese el dni del cliente: ");
                scanf("%d", &client.dni);
                rewind(arch1);
    			fread(&aux1, sizeof(cliente), 1, arch1);
    				for(int i=0; !feof(arch1); arch1){
    					if(client.dni==aux1.dni){
    						verifCliente=true;
    						break;
						}
						fread(&aux1, sizeof(cliente), 1, arch1);
					}
                    	if(verifCliente){
	                        printf("\n\t\tIngrese la Fecha para el turno:\n");
	                        printf("\n\t\tDia: ");
	                        scanf("%d", &reg.fecTurno.dia);
	                        printf("\n\t\tMes: ");
	                        scanf("%d", &reg.fecTurno.mes);
	                        printf("\n\t\tAnio: ");
	                        scanf("%d", &reg.fecTurno.anio);
	                        _flushall();
	                        printf("\n\t\tIngrese el detalle de la atencion:\n");
	                        printf("\n\t\t ");
	                        gets(reg.detalleAtencion);
	                        fseek(arch, sizeof(turnos), SEEK_END );
	                        fwrite(&reg, sizeof(turnos), 1, arch);
	                        fclose(arch);
                    	}else{
                    		printf("\n\t\tEl cliente no esta registrado\n");
                    		system("pause");
                    		system("cls");
						} 
            }		else{
            			printf("\n\t\tEl profesional no existe\n");
            			system("pause");
            			system("cls");
					} 
    fclose(arch1);
    fclose(arch2);                    
}

void listadoAtenciones(){
   FILE *arch = fopen("Turnos.dat", "a+b");
    FILE *arch1 = fopen("Profesionales.dat", "a+b");
    turnos atencion;
    profesional aux;
    int id;
    bool verif = false;
    printf("\n\n\t\t\t----------- Listado de atenciones -----------\n\n");
    _flushall();
    printf("\n\tIngrese el id del profesional: ");
    scanf("%d", &id);
    rewind(arch1);
    fread(&aux, sizeof(aux), 1, arch1);
    for(int i=0; !feof(arch1); i++){ //compara si el profesional existe ingresado ya existe
        if (id==aux.idProfesional)
        {
            system("cls");
            printf("\n\n\t\t\t----------- | Listado de atenciones - %s| -----------\n\n", aux.apeNom);
            fread(&atencion, sizeof(atencion), 1, arch);
            for(int i=0; !feof(arch); i++){ //compara si el profesional existe ingresado ya existe
                if (id==atencion.idProfesional){
                    verif = true;
                    printf("\n\t\tID: %s", atencion.idProfesional);
					printf("\n\t\tDNI: %d", atencion.dniCliente);
					printf("FECHA: %d/%d/%d", atencion.fecTurno.dia, atencion.fecTurno.mes, atencion.fecTurno.anio);
                }     
                fread(&atencion, sizeof(atencion), 1, arch);
            }
            if(verif = false) printf("\n\n\t\t\t======== | NO HAY ATENCIONES | ========");
            fclose(arch);
            system("pause>null");
            menu();
        }     
        fread(&aux, sizeof(aux), 1, arch1);
    }
    fclose(arch1); 
    system("cls");
    printf("\n\n\t\t\tId de profesional inexistente.");
    system("pause>null");
}

