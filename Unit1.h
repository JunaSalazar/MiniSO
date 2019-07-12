//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TGroupBox *ProcesoA;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TComboBox *Procesos;
	TButton *Desplegar;
	TGroupBox *Tabla;
	TListView *ListView1;
	TGroupBox *Solicitud;
	TButton *Interrumpir;
	TComboBox *Interrupciones;
	TGroupBox *Memoria;
	TLabel *t_algoritmo;
	TButton *Cambiar;
	TButton *Reseteo;
	TGroupBox *CPU;
	TLabel *cpu_algoritmo;
	TButton *CambiarA;
	TLabel *Label9;
	TEdit *AsignacionQuantum;
	TUpDown *UpDown1;
	TGroupBox *NuevoProceso;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TButton *Crear;
	TEdit *Paginas;
	TEdit *EjecucionTotal;
	TUpDown *UpDown2;
	TUpDown *UpDown3;
	TLabel *tiempo_Actual;
	TLabel *Nombre;
	TLabel *Llegada;
	TLabel *Envejecimiento;
	TLabel *Cpu_restante;
	TLabel *Quantum_restante;
	TListView *ListViewRunning;
	TListView *ListViewBlocked;
	TListView *ListViewReady;
	TComboBox *Pagina;
	TButton *Ejecutar;
	TLabel *nuevoProcesoNombre;
	void __fastcall CambiarClick(TObject *Sender);
	void __fastcall CambiarAClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DesplegarClick(TObject *Sender);
	void __fastcall InterrumpirClick(TObject *Sender);
	void __fastcall ReseteoClick(TObject *Sender);
	void __fastcall CrearClick(TObject *Sender);
	void __fastcall EjecutarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
