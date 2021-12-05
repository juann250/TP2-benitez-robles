#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <iostream>
using namespace std;

typedef char cadena[32];

struct fecha
{
	int dia, mes, anio;
};

struct persona
{
	char usuario[10];
	char contrasenia [32];
	char apnom [60];
};

struct profesional
{
	int id;
	persona datos;	
	int dni;
	int telefono;
};

struct auxiliar
{
	char nombre [60];
	int cantidad;
};

struct turnos
{
int idprof;
fecha dia;
int dnicliente;
char detalle[380];
};

void gotoxy(int x,int y);
int menuPrincipal();
void encabezado();
void RegistrarProf();
void RegistrarSec();
void cargarvector(auxiliar v[], int &n);
void atencionlista(auxiliar v[], int n);
void topatencion(auxiliar v[], int n);

main(){

system("mode con: cols=140 lines=30");
system("COLOR F0");
int op=0, n=0;
auxiliar v[100];
		
encabezado();

do{

					system ("CLS");
					encabezado();	
	op = menuPrincipal();
	
		switch(op){
			case 1: 
					system ("CLS");
					encabezado();
					RegistrarProf();
				 		 break;	 
			case 2:	
					system ("CLS");
					encabezado();
					RegistrarSec();	
						 break;
					 
			case 3: 
					system ("CLS");
					encabezado();
					cargarvector(v, n);
					atencionlista(v, n);
					 break;
					 
			case 4:
					system ("CLS");
					encabezado(); 
					cargarvector(v, n);
					topatencion(v, n);
					 break;	
					 	
			case 5: 
					system ("CLS");
					encabezado();
					printf("\n\nMuchas gracias por utilizar el programa");
					 break;			 
		}
		printf("\n");
		system("pause");
	}while(op != 5);
	exit(1);
	
}


int menuPrincipal(){
	
	int op=0;

				gotoxy(54, 8);printf(" [1].- Registrar Profesional ");
				gotoxy(54,10);printf(" [2].- Registrar Usuario Recepcionista ");	
				gotoxy(54,12);printf(" [3].- Atenciones por Profesional ");
				gotoxy(54,14);printf(" [4].- Ranking de Profesionales por Atenciones ");
				gotoxy(54,20);printf(" [5].- Cerrar aplicacion ");
				
					gotoxy(54,24);printf("-----------------");
					gotoxy(54,25);printf("Ingrese la opcion deseada: ");
					scanf("%d", &op);
		
	return op;
}

void encabezado(){
	gotoxy(2,1);printf("========================================================================================================================================");
	gotoxy(40,2);printf("                  A D M I N I S T R A C I O N                    ");
	gotoxy(2,3);printf("========================================================================================================================================");	
}

void RegistrarProf(){
	
	profesional registro;
	int dni[100], id[100], a=0, b=0, c=0;
	cadena usuarios[100];
	
	
     FILE *arch;
	 arch = fopen("Profesionales.dat", "ab+");
	 
	 fread(&registro, sizeof(registro), 1, arch);	
		while(!feof(arch)){	
		
			dni[c]=registro.dni;
			id[c]=registro.id;
			strcpy(usuarios[c],registro.datos.usuario);
			c++;
			fread(&registro, sizeof(registro), 1, arch);
		}

	 gotoxy(0, 6);printf("%c",205);	
	 gotoxy(1, 6);printf("%c",187);
	 gotoxy(1, 7);printf("%c",186);
	 gotoxy(1, 7);printf("%c",200);
	 for(int i=2; i<=85; i++){
	 	gotoxy(i,7);printf("%c",205);	 	
	 }
	 gotoxy(15, 6);printf("%c Ingrese el apellido y nombre del profesional: ", 175);
	 	_flushall();
		gets(registro.datos.apnom);
		
	bool bandera=false;
	
		gotoxy(0, 10);printf("%c",205);	
	 	gotoxy(1, 10);printf("%c",187);
	 	gotoxy(1, 11);printf("%c",186);
	 	gotoxy(1, 11);printf("%c",200);
	 	for(int i=2; i<=85; i++){
	 		gotoxy(i,11);printf("%c",205);	 	
	 	}
	 	gotoxy(15, 10);printf("%c Ingrese el [ID] del profesional: ", 175);
	 	scanf("%d", &registro.id);
	 	
	do{		
	bandera=false;

	 	for(int i=0; i<c; i++){
			if(registro.id==id[i]) {
				cout<<"\e[A";
				cout<<"\e[A";
				bandera=true;
			}
		}
		if (bandera){
			gotoxy(15, 12);printf("-El ID ingresado ya esta registrado-");
			 	gotoxy(15, 10);printf("%c Ingrese el [ID] del profesional: ", 175);
	 	scanf("%d", &registro.id);
		}


	}while(bandera);

	bandera=false;
	do{		
	 	gotoxy(0, 14);printf("%c",205);	
	 	gotoxy(1, 14);printf("%c",187);
	 	gotoxy(1, 15);printf("%c",186);
	 	gotoxy(1, 15);printf("%c",200);
	 	for(int i=2; i<=85; i++){
	 		gotoxy(i,15);printf("%c",205);	 	
	 	}
	 	gotoxy(15, 14);printf("%c Ingrese el [DNI] del profesional: ", 175);
	 	scanf("%d", &registro.dni);
		for(int i=0; i<c; i++){
			if(registro.dni==dni[i]) bandera=true;
		}
		gotoxy(15, 16);if (bandera)printf("-El DNI ingresado ya esta registrado-");
	}while(bandera);
	
	 gotoxy(0, 18);printf("%c",205);	
	 gotoxy(1, 18);printf("%c",187);
	 gotoxy(1, 19);printf("%c",186);
	 gotoxy(1, 19);printf("%c",200);
	 for(int i=2; i<=85; i++){
	 	gotoxy(i,19);printf("%c",205);	 	
	 }
	 gotoxy(15, 18);printf("%cIngrese el Numero de telefono: ", 175);
	 	scanf("%d", &registro.telefono);	

		bool min=false, may=false, dig=false;
		bandera=false;



	do{
		min=false; may=false; dig=false;
		do{
			system("cls");
		gotoxy(56, 5);printf("D A T O S - I N G R E S A D O S");
		gotoxy(54, 6);printf("----------------------------------");
			encabezado();
		gotoxy(25, 7);printf("%cNombre: %s - %cID: %d - %cDNI: %d - %cTelefono: %d", 175, registro.datos.apnom, 175, registro.id, 175, registro.dni, 175, registro.telefono);
			gotoxy(20, 10);printf("%cINGRESE: ", 16);
			gotoxy(35, 12);printf("%cNombre de Usuario ", 175);
			for(int i=35; i<=92; i++){
	 			gotoxy(i,13);printf("%c",196);	 	
	 		}
			gotoxy(35, 14);printf("Debe estar compuesto por letras; laprimera minuscula");
			gotoxy(35, 15);printf("y al menos dos mayusculas, como maximo 3 números y/o ");
			gotoxy(35, 16);printf("símbolos del conjunto {+,-,/,*,?,¿,!,¡}");
			for(int i=35; i<=92; i++){
	 			gotoxy(i,17);printf("%c",196);	 	
	 		}		
			gotoxy(35, 18);printf("%c",175);
			gotoxy(36, 18);scanf("%s", registro.datos.usuario);
			for(int i=0; i<c; i++){
				if(strcmp(registro.datos.usuario, usuarios[i])==0) bandera=true;
			}
			if(bandera){
			gotoxy(36, 19);printf("-Usuario ya ingresado. Intente nuevamente-");	
			}
		}while(bandera);
			
		int mayuscula=0, digito=0;
		
			if(strlen(registro.datos.usuario)>= 6 && strlen(registro.datos.usuario) <= 10){
				for(int i=0; i < strlen(registro.datos.usuario); i++){
					if (registro.datos.usuario[i] >= 65 && registro.datos.usuario[i] <= 90) {
						mayuscula++;	
					}
					if (registro.datos.usuario[i] == 43 || registro.datos.usuario[i] == 45 || registro.datos.usuario[i] == 47 || registro.datos.usuario[i] == 42 || registro.datos.usuario[i] == 63 || registro.datos.usuario[i] == 168 || registro.datos.usuario[i] == 173 || registro.datos.usuario[i] == 33 || registro.datos.usuario[i] >= 48 && registro.datos.usuario[i] <= 57){
						digito++;
					}			
				}	
			}
			else {
				gotoxy(35, 19);printf("-El usuario debe tener un minimo de 6 y un maximo de 10 digitos-");
			}
			
			if(registro.datos.usuario[0] >=97 && registro.datos.usuario[0] <=122){
					min=true;
			}
			else  {
			gotoxy(35, 20);printf("-La primer letra debe ser minuscula-");
			}
			
			if(mayuscula >= 2){	
					may=true;
			}
			
			else {
			gotoxy(35, 21);printf("-El usuario debe contener al menos dos letras mayusculas-");
			}
			if(digito>0 && digito<4){
					dig=true;
			}
			else {
			gotoxy(35, 22);printf("-El usuario debe contener un/unos numeros o digitos valido-");
			}
			gotoxy(35, 23);system("pause");
			
	}while(min==false || may==false || dig==false);
	
	dig=false;
	bool sucesionl=false, sucesiond=false, minuscula=false, mayuscula=false, numero=false;
	do{
		int c=0;
		system("cls");
		encabezado();
	
		if(c>0){
		gotoxy(56, 20);printf("Contrase%a No Valida! Intente nuevamente", 164);	
		}
		char caux[32];
		
			gotoxy(56, 5);printf("D A T O S - I N G R E S A D O S");
			gotoxy(54, 6);printf("----------------------------------");
			gotoxy(25, 7);printf("%cNombre: %s - %cID: %d - %cDNI: %d - %cTelefono: %d - %cUsuario: %s", 175, registro.datos.apnom, 175, registro.id, 175, registro.dni, 175, registro.telefono, 175, registro.datos.usuario);
			gotoxy(20, 10);printf("%cINGRESE: ", 16);
			gotoxy(35, 12);printf("%cContrase%ca", 175, 164);
			for(int i=35; i<=92; i++){
	 			gotoxy(i,13);printf("%c",196);	 	
	 		}
			gotoxy(35, 14);printf("Debe tener entre 6 y 32 caracteres y debe contener: ");	
			gotoxy(35, 15);printf("Al menos una letra mayuscula, una minuscula no consecutivas");
			gotoxy(35, 16);printf("alfabeticamente y minimo un numero; no puede ser una sucesion ");
			gotoxy(35, 17);printf("de 3 numeros consecutivos. No podra contener ningún carácter de");
			gotoxy(35, 17);printf("puntuacion, ni acentos, ni espacios.Sólo caracteres alfanumericos");
			for(int i=35; i<=92; i++){
	 			gotoxy(i,18);printf("%c",196);	 	
	 		}
			gotoxy(35, 19);printf("%c",175);
			gotoxy(36, 19);scanf("%s", registro.datos.contrasenia);			
				if(strlen(registro.datos.contrasenia)>= 6 && strlen(registro.datos.contrasenia) <= 32){
					strcpy(caux,registro.datos.contrasenia);
					strupr(caux);
					for(int i=0; i < strlen(caux); i++){
						if(caux[i]>=65 && caux[i]<=90){
							if (caux[i]+1==caux[i+1]) {
								sucesionl=true;
							}					
						}
						else if(caux[i]>=48 && caux[i]<=57){
							if (caux[i]+1==caux[i+1] and caux[i]+2==caux[i+2] and caux[i]+3==caux[i+3]) {
								sucesiond=true;							
							}
						}
						else  dig=true;
						
					}
					for(int i=0; i < strlen(registro.datos.contrasenia); i++){
						
						if (registro.datos.contrasenia[i] >= 65 && registro.datos.contrasenia[i] <= 90) {
							mayuscula=true;
						}
						if(registro.datos.contrasenia[i] >= 97  && registro.datos.contrasenia[i] <= 122){
							minuscula=true;
						}
						if(registro.datos.contrasenia[i] >= 48  && registro.datos.contrasenia[i] <= 57){
							numero=true;
						}
					}
								
				}

/*				else {
					gotoxy(36, 21);printf("-la contraseña debe contener entre 6 y 32 caracteres-");
				}
				
				if(!mayuscula){
					gotoxy(36, 22);printf("\n-La contraseña debe tener al menos una letra mayuscula-");
				} 
					
				if(!minuscula){
					gotoxy(36, 23);printf("\n-La contraseña debe tener al menos una letra minuscula-");
				}
				
				if(!numero){
					gotoxy(36, 24);printf("\n-La contraseña debe tener al menos un numero-");
				}
				if(dig){
					gotoxy(36, 25);printf("\n-La contraseña no debe tener digitos: digitos, espacios, signos de puntuacion-");
				}
				if(sucesionl){
					gotoxy(36, 26);printf("\n-La contraseña no puede tener letras sucesivas (AB,BC,CD,etc)-");
				}	
				if(sucesiond){
					gotoxy(36, 27);printf("\n-La contraseña no puede tener mas de tres numeros consecutivos entre si (1234,2345,3456,etc)-");
				}
*/
				c++;
	}while(minuscula==false || mayuscula==false || numero==false || dig==true || sucesionl==true || sucesiond==true);
	
	fwrite(&registro, sizeof(registro), 1, arch);
	fclose(arch);
}


void RegistrarSec(){
	
	persona registro;
	
     FILE *arch;
	 arch = fopen("Recepcionistas.dat", "ab+");
	 
	 printf("\n\nIngrese el apellido y nombre del profesional: ");
	 _flushall();
	 gets(registro.apnom);
	
	bool min=false, may=false, dig=false;
	do{

		int mayuscula=0, digito=0;
		printf("\n\nIngrese nombre de usuario: ");
		printf("\n\nDebe estar compuesto por letras; la primera minuscula y al menos dos mayusculas, como maximo 3 números y/o símbolos del conjunto {+,-,/,*,?,¿,!,¡}");	
		scanf("%s", &registro.usuario);
			if(strlen(registro.usuario)>= 6 && strlen(registro.usuario) <= 10){
				for(int i=0; i < strlen(registro.usuario); i++){
					if (registro.usuario[i] >= 65 && registro.usuario[i] <= 90) {
						mayuscula++;	
					}
					if (registro.usuario[i] == 43 || registro.usuario[i] == 45 || registro.usuario[i] == 47 || registro.usuario[i] == 42 || registro.usuario[i] == 63 || registro.usuario[i] == 168 || registro.usuario[i] == 173 || registro.usuario[i] == 33 || registro.usuario[i] >= 48 || registro.usuario[i] <= 57){
						digito++;
					}			
				}	
			}
			else printf("-El usuario debe tener un minimo de 6 y un maximo de 10 digitos-");
			
			if(registro.usuario[0] >=65 && registro.usuario[0] <=90){
					min=true;
			}
			else printf("-La primer letra debe ser minuscula-");
				
			if(mayuscula >= 2){	
					may=true;
			}
			else printf("-El usuario debe contener al menos dos letras mayusculas-");
			
			if(digito>0 and digito<4){
					dig=true;
			}
			else printf("-El usuarion debe contener un numero de numeros o digitos valido-");
			
	}while(min==false && may==false && dig==false);
	
		int k=0;
		dig=false;
		bool sucesionl=false, sucesiond=false, mayuscula=false, minuscula=false, numero=false;	
	do{
		
		char caux[32];
		
			printf("\n\nIngrese la contraseña: ");
			printf("\n\nDebe tener entre 6 y 32 caracteres y debe contener: ");	
			printf("\nAl menos una letra mayúscula, una minúscula no consecutivas alfabeticamente y minimo un número; no puede ser una sucesion de 3 numeros consecutivos.");
			printf("\nNo podrá contener ningún carácter de puntuación, ni acentos, ni espacios.Sólo caracteres alfanuméricos");
			printf("\nNo podrá contener ningún carácter de puntuación, ni acentos, ni espacios.Sólo caracteres alfanuméricos");
			scanf("%s", &registro.contrasenia);
			
				if(strlen(registro.contrasenia)>= 6 && strlen(registro.contrasenia) <= 32){
					strcpy(caux,registro.contrasenia);
					for(int i=0; i < strlen(caux); i++){
						strupr(caux);
						if(caux[i]>=65 && caux[i]<=90){
							if (caux[i]+1==caux[i+1]) {
								sucesionl=true;
							}					
						}
						else if(caux[i]>=48 && caux[i]<=57){
							if (caux[i]+1==caux[i+1] and caux[i]+2==caux[i+2] and caux[i]+3==caux[i+3]) {
								sucesiond=true;							
							}
						}
						else  dig=true;
						
					}
					for(int i=0; i < strlen(registro.contrasenia); i++){
						
						if (registro.contrasenia[i] >= 65 && registro.contrasenia[i] <= 90) {
							mayuscula=true;
						}
						if(registro.contrasenia[i] >= 97  && registro.contrasenia[i] <= 122){
							minuscula=true;
						}
						if(registro.contrasenia[i] >= 48  && registro.contrasenia[i] <= 57){
							numero=true;
						}
					}
								
				}

	/*			else printf("-la contraseña debe contener entre 6 y 32 caracteres-");
				
				if(!mayuscula){
					printf("\n-La contraseña debe tener al menos una letra mayuscula-");
				} 
					
				if(!minuscula){
					printf("\n-La contraseña debe tener al menos una letra minuscula-");
				}
				
				if(!numero){
					printf("\n-La contraseña debe tener al menos un numero-");
				}
				if(dig){
					printf("\n-La contraseña no debe tener digitos: digitos, espacios, signos de puntuacion-");
				}
				if(sucesionl){
					printf("\n-La contraseña no puede tener letras sucesivas (AB,BC,CD,etc)-");
				}	
				if(sucesiond){
					printf("\n-La contraseña no puede tener mas de tres numeros consecutivos entre si (1234,2345,3456,etc)-");
				}
*/
			k++;
			
	}while(minuscula==false || mayuscula==false || numero==false || dig==true || sucesionl==true || sucesiond==true);
	
	fwrite(&registro, sizeof(registro), 1, arch);
	fclose(arch);
}


void cargarvector(auxiliar v[],	int &n){
	
	profesional p;
	turnos o;
	
	FILE *lista; FILE *prof;
	prof = fopen("Profesionales.dat", "rb");
	lista = fopen("Turnos.dat", "rb");


	
	fread(&p, sizeof(p), 1, prof);
 	while(!feof(prof))	{
 		strcpy(v[n].nombre, p.datos.apnom);
 		v[n].cantidad=0;
 		rewind(lista);
 		fread(&o, sizeof(o), 1, lista);
			 while(!feof(lista)){
			 	if(o.idprof==p.id and strcmp(o.detalle, "")!=0){
			 		v[n].cantidad++;
				 }
 				fread(&o, sizeof(o), 1, lista);
		 }

		fread(&p, sizeof(p), 1, prof);
		n++;
	}	
}

void atencionlista(auxiliar v[], int n){
	
	char nombre [60];	
	auxiliar z;
	gotoxy(20, 6);printf("¡----LISTA ATENCION POR PROFESIONAL----");


	for (int i=1; i<n; i++){	
   	   for (int j=0; j<n-1; j++){
			if (strcmp(v[j].nombre,v[j+1].nombre)>0) {	
					
				z= v[j];
   	   	        v[j]= v[j+1];
   	   	        v[j+1]=z;
			}    		   
		}
	}
	for(int i=0; i<n; i++){
		
		gotoxy(35, 8+i);printf("Profesional: %s", v[i].nombre);
		gotoxy(35, 9+1);printf("atenciones: %d", v[i].cantidad);
	}
}
void topatencion(auxiliar vector[], int n){

	auxiliar z;

		gotoxy(35, 19);printf("\n\n----LISTA TOP ATENCIONES----");

	for (int i=1; i<n; i++){	
   	   for (int j=0; j<n-1; j++){
			if (vector[j].cantidad>vector[j+1].cantidad) {
						
				z= vector [j];
   	   	        vector [j]= vector [j+1];
   	   	        vector [j+1]=z;
			}    		   
		}
	}
	for(int i=0; i<n; i++){
		
		printf("Profesional: %s", vector[i].nombre);
		printf("atenciones: %d", vector[i].cantidad);
	
	}
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}


