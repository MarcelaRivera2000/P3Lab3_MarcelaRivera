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
cout<<endl;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(j==0){
				cout<<"# ";
			}
			if(matrix[i][j]==1){
				cout<<" * ";	
			}else if(matrix[i][j]==0){
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
	
	int cont;
	for(int inicio=0;inicio<turnos;inicio++){	
		cout<<"matrix"<<endl;
		imprimir(matrix,x,y);
		for(int i=1;i<x;i++){
			for(int j=0;j<y;j++){
				cont=0;	
				if(j>0){
					if(matrix[i-1][j]==1){
						cont++;	
					//	cout<<"kpex1 "<< matrix[i-1][j]<<endl;
					}
				}
				if(i>0&&j<y-1){
				if(matrix[i-1][j+1]==1){
					cont++;
				//	cout<<"kpex2 "<< matrix[i-1][j+1]<<endl;
				}
			}

				if(i>0 &&j>0){
			
				if(matrix[i-1][j-1]==1){
					cont++;
				//	cout<<"kpex3 "<< matrix[i-1][j-1]<<endl;
				}
			}				
				if(matrix[i][j+1]==1 && j<y-1){
					cont++;
				//	cout<<"kpex4 "<< matrix[i][j+1]<<endl;
				}
				if(matrix[i][j-1]==1&& j>0){
					cont++;
				//	cout<<"kpex5 "<< matrix[i][j-1]<<endl;
				}
				if(i<x-1 &&j<y-1){
					if(matrix[i+1][j+1]==1){
					cont++;
				//	cout<<"kpex6 "<< matrix[i+1][j+1]<<endl;
					}	
				}
				
				if(i<x-1){
				if(matrix[i+1][j]==1){
					cont++;
				//	cout<<"kpex7 "<< matrix[i+1][j]<<endl;
				}
				}
				if(i<x-1 &&j>0){
				if(matrix[i+1][j-1]==1){
					cont++;
				//	cout<<"kpex8 "<< matrix[i+1][j-1]<<endl;
				}
				
			}
			
		//	cout<<"cont: "<<cont<<" a ver: "<<matrix[i][j]<<endl;
				if(matrix[i][j]==1){
					if(cont<2){
						aux[i][j]=0;
				}
				if(cont==2||cont==3){
					aux[i][j]=1;
				}
				if(cont>3){
					aux[i][j]=0;
				}
			}else{
				if(cont==3){
				aux[i][j]=1;
			}
			}
			}
		}
		cout<<endl;
		for(int e=0;e<x;e++){
			for(int r=0;r<y;r++){
				matrix[e][r]=aux[e][r];
				
				}
		}		
		
		cin.ignore();
	}
	cout<<"TERMINO"<<endl;
}






