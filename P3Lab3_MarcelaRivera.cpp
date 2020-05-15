#include<iostream>
#include<stdlib.h>
#include<time.h>

using std::cin;
using std::endl;
using std::cout;

void ejercicio1();
void ejercicio2();
void imprimir(int ** matrix,int x,int y);

int main(){
		while(true){
		int op;
		srand(time(NULL));
		cout<<"1#Jugar con un tablero aleatorio"<<endl<<"2#Jugar con el tablero predefinido"<<endl<<"3#Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:
				ejercicio1();
				break;
			case 2:
				ejercicio2();
				break;				
			case 3:
				exit (EXIT_FAILURE);
				break;
		}
	}
	return 0; 
}

void imprimir(int ** matrix,int x,int y){
	for(int i=0;i<x;i++){
		cout<<" # ";
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			
			if(matrix[i][j]==1){
			cout<<" * ";	
			}else{
				cout<<"   ";
			}
		}
		cout<<endl;
	}
	for(int i=0;i<x;i++){
		cout<<" # ";
	}
	cout<<endl;
}

void ejercicio1(){
	int x,y,turnos;
	cout<<"Ingrese el tamaño de x"<<endl<<": ";
	cin>>x;
	cout<<"Ingrese el tamaño de y"<<endl<<": ";
	cin>>y;
	cout<<"Ingrese la cantidad de turnos"<<endl<<": ";
	cin>>turnos;
	int ** matrix=new int*[y];
	int ** auxmatrix=new int*[y];
	int num;
	for(int i=0;i<x;i++){
		matrix[i]=new int[x];
		auxmatrix[i]=new int[x];
		for(int j=0;j<y;j++){
			num=0+rand()%(2-0);
			if(num==0){
				matrix[i][j]=0;
			}else{
			matrix[i][j]=1;	
			}
			auxmatrix[i][j]=0;
		}
	}
	imprimir(matrix,x,y);
	
	
}

void ejercicio2(){
int x = 20;
int y = 20;
int temp_mat [20][20] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0},
{0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

	int ** mat = new int*[y];
	for(int i = 0; i < y ; i++){
		mat[i] = new int[x];
		for(int j = 0; j < x ; j++){
			mat[i][j] = temp_mat[i][j];
		}
	}
	imprimir(mat,x,y);
	
	
	
}












































