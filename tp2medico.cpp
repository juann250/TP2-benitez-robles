#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <iostream>
using namespace std;


struct inicio
{
	char usuario[10];
	char contrasenia [10];

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

int menuPrincipal();
void gotoxy(int x,int y);
void encabezado();
bool iniciosesion();
void listaturnos();

main(){
	
system("mode con: cols=140 lines=30");
system("COLOR F0");
	system("cls");
	encabezado();

int op=0;
	
bool sesion=false;
do{

	op = menuPrincipal();

		switch(op){
			case 1: 	
					system("cls");
					encabezado();
					sesion=iniciosesion();
					
				 		 break;
						  	 
/*			case 2:
					system("cls");
					encabezado();	
					if(sesion) {
						RegistrarSec();	
					}
					else{
						printf("Es necesario iniciar sesion")
					}
					
						 break;
					 
			case 3: 
						system("cls");
						encabezado();	
					if(sesion) {
						RegistrarSec();	
					}
					else{
						printf("Es necesario iniciar sesion")
					}
					 break;
*/					 
			case 4: 
					 break;	
					 			 
		}
		printf("\n");
		system("pause");
	}while(op != 4);
	exit(1);
	
}

int menuPrincipal(){
	
	int op=0;

		do{
			 op=0;
			
			gotoxy(33, 8);printf(" [1].- Iniciar Sesion ");
			gotoxy(32, 9);printf("%c", 192); 
			 for(int i=33; i<=105; i++){
	 			gotoxy(i,9);printf("%c",196);	 	
	 		}
			gotoxy(33, 11);	printf(" [2].- Visualizar Lista de Espera de Turnos (informe) ");
			gotoxy(32, 12);printf("%c", 192); 
			 for(int i=33; i<=105; i++){
	 			gotoxy(i,12);printf("%c",196);	 	
	 		}				
			gotoxy(33, 14);	printf(" [3].- Registrar Evolucion del tratamiento ");
			gotoxy(32, 15);printf("%c", 192); 
			 for(int i=33; i<=105; i++){
	 			gotoxy(i,15);printf("%c",196);	 	
	 		}				
			gotoxy(33, 18);	printf(" [4].- Cerrar aplicacion ");
			 for(int i=33; i<=75; i++){
	 			gotoxy(i,19);printf("%c",196);	 	
	 		}			
				
			gotoxy(54, 22);	printf("%cIngrese la opcion deseada:", 175);
					scanf("%d", &op);			
					
		}while(op<1 or op>5);
		
	return op;
}

void encabezado(){
	gotoxy(2,1);printf("========================================================================================================================================");
	gotoxy(35,2);printf("                  A D M I N I S T R A C I O N                    ");
	gotoxy(2,3);printf("========================================================================================================================================");	
}


bool iniciosesion(){
	
	inicio registro;
	profesional p;
	bool bien;

	FILE *prof;
	prof = fopen("Profesionales.dat", "rb");
	
	gotoxy(35,6);printf("I N I C I A R - S E S I O N");
	gotoxy(34,7);printf("-----------------------------");		
	gotoxy(35,9);printf("Ingrese nombre de usuario:");
	gotoxy(35,9);scanf("&s",registro.usuario);
	gotoxy(35,10);printf("Ingrese contrase%ca:",164);
	gotoxy(35,10);scanf("&s",registro.contrasenia);	

	fread(&p, sizeof(p), 1, prof);
 	while(!feof(prof)){
 			if(strcmp(registro.usuario, p.datos.usuario)==0 && strcmp(registro.contrasenia, p.datos.contrasenia) == 0){
 				bien=true;
	gotoxy(40,23);printf("S E S I O N - I N I C I A D A");
	gotoxy(40,24);printf("--------------------------------");
	gotoxy(42,25);printf("%cBIENVENIDO%c", 175, 174);	
			 }
 		fread(&p, sizeof(p), 1, prof);
	 }
	 return bien;	
}


void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}