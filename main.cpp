 // FileName:        main .c
 // Program version: Dev-C++ 6.3
 // Company:         TECNM - ITCH
 // Description:     Laboratorio 3.
 // Authors:         LUIS ALEJANDRO OLIVAS MARRUFO 19060735
 // Updated:         10/2022
 //Nota:  Convertidor ADC


#include <iostream>
#include<stdlib.h> 
#include<stdio.h>
using namespace std; 

class ConvertidorADC{
	
	private:   //Atributos
		
		int res,ncanales,frec,*canales;   //resolucion,no. de canales,frescuencia de muestreo, vector de memoria dinamica donde se almacenan numeros de canales
		float *voltaje,*resolucion_salida;//vectores de memoria dinamica donde se almacenara el voltaje que leerá el convertidor,y la salida del convertidor
	
	public: 
	
		ConvertidorADC(int,int,int);  //no. de canales,resolucion de los canales,frecuencia de muestreo,canales
		void setncanales(int _ncanales,int _res,int _frec);
		virtual void calculador(); //metodo para polimorfismo
		
		int getncanales(); 
		int getfrec(); 
		int getres();
};  

class ConvertidorADC2 : public ConvertidorADC{
	private: 	
	static const int f_osc=8; 
	int ack; 
	
	public:  
	ConvertidorADC2(int,int,int); 
	void calculador(int,int);
	
	
};

/********************Metodos*********************************/ 

ConvertidorADC::ConvertidorADC(int _ncanales=0,int _res=0,int _frec=0): ncanales(_ncanales),res(_res),frec(_frec)//Constructor
{
  canales= new int[ncanales]; 
  voltaje= new float[ncanales];
  resolucion_salida= new float[ncanales];
}  

ConvertidorADC2::ConvertidorADC2(int ,int ,int){
	

	cout<<"se ha creado un objeto de una clase heredada"<<endl; 
	
}

void ConvertidorADC::calculador(){
	
		for(int i=0; i<ncanales; i++){
		cout<<"Seleccione el canal a usar (max 32): AN";
		cin>>canales[i];
	}   
	
		for(int i=0; i<ncanales; i++){
		
			int resl;
			cout<<"Ingresa el voltaje (max 3.3v) del AN"<<canales[i]<<":";
			cin>> voltaje[i];
			
			switch(res)
			{
				case 8:
					 resl=255; 
					 resolucion_salida[i]=(voltaje[i]/3.3)*resl;
					break; 
					
				case 10:
					 resl=1023;
					 resolucion_salida[i]=(voltaje[i]/3.3)*resl;
					break;
				
				case 12: 
					 resl=4095;
					 resolucion_salida[i]=(voltaje[i]/3.3)*resl;
					break;
					
				default: break;
			}
	} 
	
	cout<<"\nMostrando datos";
	cout<<"\nResolucion "<<res<<" bits "<<endl;
	cout<<"\nFrecuencia "<<frec<<"Khz "<<endl;
	
	for(int i=0; i<ncanales; i++){ 
	    
		cout<<"Canal AN"<<canales[i]<<endl; 
		cout<<"Voltaje de entrada: "<<voltaje[i]<<"V"<<endl;
		cout<<"Dato digital: "<<resolucion_salida[i]<<endl; 
	}
	
	delete[] canales; 
	delete[] voltaje;
	delete[] resolucion_salida;
}

void ConvertidorADC2::calculador(int _ncanales, int _res ){  

    int _ack,*canales;  
    int ncanales=_ncanales;
    int res=_res;
    float frecuencia_calculada; 
    float *voltaje,*resolucion_salida; 
    
    canales= new int[ncanales]; 
  voltaje= new float[ncanales];
  resolucion_salida= new float[ncanales];
    
	cout<<"Ingrese ack prescaler"<<endl; 
	cin>>_ack; 
	ack=_ack; 
	frecuencia_calculada=f_osc/ack; 
	cout<<"Frecuencia: "<<frecuencia_calculada<<"Khz"<<endl; 
	
	
	for(int i=0; i<ncanales; i++){
		cout<<"Seleccione el canal a usar (max 32): AN";
		cin>>canales[i];
	}   
	
		for(int i=0; i<ncanales; i++){
		
			int resl;
			cout<<"Ingresa el voltaje (max 3.3v) del AN"<<canales[i]<<":";
			cin>> voltaje[i];
			
			switch(res)
			{
				case 8:
					 resl=255; 
					 resolucion_salida[i]=(voltaje[i]/3.3)*resl;
					break; 
					
				case 10:
					 resl=1023;
					 resolucion_salida[i]=(voltaje[i]/3.3)*resl;
					break;
				
				case 12: 
					 resl=4095;
					 resolucion_salida[i]=(voltaje[i]/3.3)*resl;
					break;
					
				default: break;
			}
	} 
	
	cout<<"\nMostrando datos";
	cout<<"\nResolucion :"<<res<<" bits "<<endl;
	cout<<"Frecuenia:"<<frecuencia_calculada<<"KHz"<<endl;
	
	for(int i=0; i<ncanales; i++){ 
	    
		cout<<"Canal AN"<<canales[i]<<endl; 
		cout<<"Voltaje de entrada: "<<voltaje[i]<<"V"<<endl;
		cout<<"Dato digital: "<<resolucion_salida[i]<<endl; 
	}
	
	delete[] canales; 
	delete[] voltaje;
	delete[] resolucion_salida;
}

///Setter
void ConvertidorADC::setncanales(int _ncanales,int _res,int _frec){
  ncanales=_ncanales; 
  res=_res; 
  frec=_frec;
}

//getter 
int ConvertidorADC::getncanales()
{
	return ncanales;
} 

int ConvertidorADC::getfrec()
{
	return frec;
} 

int ConvertidorADC::getres()
{
	return res;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) { 
	
	int validador,ncanales,res,frec,opc;
	

	
	do{
    	
		cout<<"Que opcion desea\nOpcion 1 Convertidor ADC(sin herenia ni polimorfismo)\n Opcion 2 Calcular Convertidor ADC calcular frecuencia(Con herencia y polimorfismo)"<<endl;
		cout<<"Ingrese numero de su opcion"<<endl;
    	if(scanf("%i", &opc) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;
		}
		
		else
		validador=0;
		
	}while(validador==1); 
	
	if(opc==1)
	{
	  do{
    	
		cout<<"Ingrese resolucion (8,10,12)"<<endl;
    	if(scanf("%i", &res) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;
		}
		
		else
		validador=0;
		
	}while(validador==1); 
	
	    do{
    	
		cout<<"Ingrese  frecuencia"<<endl;
    	if(scanf("%i", &frec) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;	
		}
		
		else
		validador=0;
		
	}while(validador==1);   
	
		do{
    	
		cout<<"Ingrese no. de canales"<<endl;
    	if(scanf("%i", &ncanales) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;	
		}
		else
		validador=0;
		
	}while(validador==1);  
	
	ConvertidorADC convertidor; //Se crea el objeto convertidor 
	convertidor.setncanales(ncanales,res,frec); 
	convertidor.calculador(); 
	}
	
	if(opc==2)
	{
		do{
    	
		cout<<"Ingrese resolucion (8,10,12)"<<endl;
    	if(scanf("%i", &res) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;
		}
		
		else
		validador=0;
		
	}while(validador==1); 
	
  
	
		do{
    	
		cout<<"Ingrese no. de canales"<<endl;
    	if(scanf("%i", &ncanales) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;	
		}
		else
		validador=0;
		
	}while(validador==1);  
	
	ConvertidorADC convertidor; //Se crea el objeto convertidor 
	convertidor.setncanales(ncanales,res,frec);  
	
	ConvertidorADC2 convertidor2(convertidor.getncanales(),convertidor.getres(),convertidor.getfrec());// Se crea el objeto de la clase heredada
	convertidor2.calculador(convertidor.getncanales(),convertidor.getres());

	}
    

	return 0;
}