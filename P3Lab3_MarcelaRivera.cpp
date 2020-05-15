#include<iostream>
#include<stdlib.h>
#include<time.h>

using std::cin;
using std::endl;
using std::cout;

void ejercicio1();
void ejercicio2();
void imprimir(int ** matrix,int x,int y);
void juego(int**matrix ,int x, int y,int turnos);

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
for(int i=0;i<x+1;i++){
	cout<<"#  ";
}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(j==0){
				cout<<"# ";
			}
			if(matrix[i][j]==1){
				cout<<" * ";	
			}else{
				cout<<"   ";
			}
		}
		
		cout<<" #"<<endl;
	}
	for(int i=0;i<x+1;i++){
	cout<<"#  ";
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
	int num;
	for(int i=0;i<x;i++){
		matrix[i]=new int[x];
		
		for(int j=0;j<y;j++){
			num=0+rand()%(2-0);
			if(num==0){
				matrix[i][j]=0;
			}else{
			matrix[i][j]=1;	
			}
		
		}
	}
	imprimir(matrix,x,y);
	juego(matrix,x,y,turnos);	
}

void ejercicio2(){
int turnos;
cout<<"Ingrese la cantidad de turnos"<<endl<<": ";
cin>>turnos;
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
	juego(mat,x,y,turnos);
}

void juego(int**matrix ,int x, int y,int turnos){
	int ** aux=new int*[y];
	for(int i=0;i<x;i++){
		aux[i]=new int[x];
		for(int j=0;j<y;j++){
			aux[i][j]=0;
		}
	}
	for(int inicio=0;inicio<turnos;inicio++){	
		int cont=0;
		for(int i=1;i<x;i++){
			for(int j=0;j<y;j++){
				
				if(y>0){
					if(matrix[i--][j]==1){
						cont++;	
					}
				}
				if(i>0&&j<y-1){
				if(matrix[i--][j++]==1){
					cont++;
				}
			}
				if(i>0 &&j>0){
			
				if(matrix[i--][j--]==1){
					cont++;
				}
			}
				
				if(matrix[i][j++]==1 && j<y-1){
					cont++;
				}
				if(matrix[i][j--]==1&& j>0){
					cont++;
				}
				
				if(i<x-1 &&j<y-1){
					if(matrix[i++][j++]==1){
					cont++;
					}	
				}
				
				if(i<x-1){
				if(matrix[i++][j]==1){
					cont++;
				}
				}
				if(i<x-1 &&j>0){
				if(matrix[i++][j--]==1){
					cont++;
				}
			}
				if(cont<2&&matrix[i][j]==1){
					aux[i][j]=0;
				}
				if((cont==2||cont==3) && matrix[i][j]==1){
					aux[i][j]=1;
				}
				if(cont>3&&matrix[i][j]==1){
					aux[i][j]=0;
				}
				if(cont==3&&matrix[i][j]==0){
					aux[i][j]=1;
				}
			
				cont=0;	
			}
		}
				
		imprimir(aux,x,y);
		cin.ignore();
	}
	cout<<"TERMINO"<<endl;
}

/*	for(int e=0;e<x;e++){
			for(int r=0;r<y;r++){
				matrix[e][r]=aux[e][r];
				aux[e][r]=0;
				}
		}*/


