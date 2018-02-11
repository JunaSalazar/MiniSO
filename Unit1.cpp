//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;
bool entrada = true;
int p_actual[6];
int memoria = 1;
int cpu = 1;
int t_actual;
//vector <int> ;//
//vector <vector<int>> ;//
//vector <vector<vector<int>>> ;//
int max_pa;


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm1::CambiarClick(TObject *Sender)
{
	memoria++;
	switch(memoria)
	{
		case 1:
		t_algoritmo->Caption = "FIFO";
		break;

		case 2:
		t_algoritmo->Caption = "LRU";
		break;

		case 3:
		t_algoritmo->Caption = "LFU";
		break;

		case 4:
		t_algoritmo->Caption = "NUR";
		break;

		case 5:
		t_algoritmo->Caption = "FIFO";
		memoria = 1;
		break;
	}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::CambiarAClick(TObject *Sender)
{
	cpu++;
	switch(cpu)
	{
		case 1:
		cpu_algoritmo->Caption = "FIFO";
		break;

		case 2:
		cpu_algoritmo->Caption = "Round Robin";
		break;

		case 3:
		cpu_algoritmo->Caption = "SRT";
		break;

		case 4:
		cpu_algoritmo->Caption = "HRRN";
		break;

		case 5:
		cpu_algoritmo->Caption = "FIFO";
		cpu = 1;
		break;
	}
}
//---------------------------------------------------------------------------

void llenarInicial()
{
	ifstream archivo("input.txt");
	//----------------VARIABLES--GLOBALES------------------------
	max_pa;//NÚMERO MÁXIMO DE PÁGINAS EJECUTÁNDOSE POR PROCESO.
	t_actual;//TIEMPO ACTUAL DEL RELOJ.
	//----------------VARIABLES--GLOBALES------------------------

	//----------------VARIABLES--LOCALES------------------------
	int pags = 0;//CANTIDAD DE PÁGINAS POR PROCESOS.
	int proc = 0;//NÚMERO DE PROCESOS.
	int dato = 0; //SE USA PARA ALMACENAR LOS NÚEROS Y SE DECIDE SI SE USAN O NO.
	String c;//ESTA VARIABLE SERÁ LA QUE SE EVALÚE SI ES COMA O NO.
	//----------------VARIABLES--LOCALES------------------------

	if (!archivo.is_open()) {
		ShowMessage("ERROR DE LECTURA");
	}

	archivo >> max_pa;
	c = archivo.get();
	if (c != ",") {
	archivo >> t_actual;
	}
    archivo >> proc;

	//CICLO PARA DAR VUELTAS A CADA DATO DE LOS PROCESOS
	for(int p = 1;p <= proc;p++){

	//CICLO PARA AGARRAR LOS TRES DATOS DE CPU DE CADA PROCESO
	//llegada, tiempo total estimado, y estado (1-running, 2-blocked, 3-ready)
		for (int d = 0; d < 3; d++) {
			c = archivo.get();
			if (c != ",") {
				archivo >> dato;
				if (d == 0) {
				/*
					llegada = dato;
					llegadas.push_back(llegada);
					*/
				}
				if (d == 1) {
				/*
					tTotal = dato;
					totales.push_back(tTotal);
					*/
				}
				if (d == 2) {
					   /*
					estado = dato;
					estados.push_back(estado);
					if (estado == 1) {
						running.push_back(p);
					}
					if (estado == 2) {
						blocked.push_back(p);
					}
					if (estado == 3) {
						ready.push_back(p);
					}
				   */
				}
			}
		}

		archivo >> pags;

		//
		//CICLO DE LLENADO DE VECTORES UNI, BI Y TRIDIMENSIONAL
        //
		for(int pag = 0; pag < pags; pag++){

		}

	}


	/*
	maxi; // Señala el número máximo de páginas por proceso
	int pags = 0; // Señala el número de procesos
	int n = 0; // Señala cuantas páginas tiene cada proceso.
	int dato = 0; // Se usa para almacenar los número y se decide si se usan o no.
	int llegada = 0; // Es la llegada.
	int estado = 0;
	int tTotal = 0; // Es el tiempo total.
	String c; // Esta variable será la que se evalúe si es coma o no.

	llegadaMax = 0;

	if (!archivo.is_open()) {
		ShowMessage("ERROR DE LECTURA");
	}

	archivo >> maxi;
	archivo >> pags;

	for (int z = 0; z < pags; z++) {
		cpuasi.push_back(0);
		enveje.push_back(0);
		cpurest.push_back(0);
		quantums.push_back(5);
		for (int x = 0; x < 3; x++) {
			c = archivo.get();
			if (c != ",") {
				archivo >> dato;
				if (x == 0) {
					llegada = dato;
					llegadas.push_back(llegada);
				}
				if (x == 1) {
					tTotal = dato;
					totales.push_back(tTotal);
				}
				if (x == 2) {
					estado = dato;
					estados.push_back(estado);
					if (estado == 1) {
						running.push_back(z + 1);
					}
					if (estado == 2) {
						blocked.push_back(z + 1);
					}
					if (estado == 3) {
						ready.push_back(z + 1);
					}

				}
			}
		}

		archivo >> n;
		//
		// AQUÍ EMPIEZA EL LLENADO DEL VECTOR
		//
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < 6; y++) {
				c = archivo.get();
				if (c != ",") {
					archivo >> dato;
					f.push_back(dato);
					if (y == 6) {
						f.push_back(0);
					}
				}
			}
			bi.push_back(f);
			f.clear();
		}
		arr.push_back(bi);
		bi.clear();
	} // Aquí termina el ciclo para el número de procesos
	//
	// AQUÍ TERMINA EL LLENADO DEL VECTOR
	//
	*/

	archivo.close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
/////////////////////////*Tamaño de quantum*/////////////////////////
	UpDown1->Min = 0;
	UpDown1->Max = 255;
	UpDown1->Associate= Edit1;

/////////////////////////*Páginas*///////////////////////////////////
	UpDown2->Min = 0;
	UpDown2->Max = 255;
	UpDown2->Associate= Edit2;

/////////////////////////*Ejecución Total*///////////////////////////
	UpDown3->Min = 0;
	UpDown3->Max = 255;
	UpDown3->Associate= Edit3;

	llenarInicial();
}

