#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int criaVetor(int *n, int m);
int excluirZ(int *l, int *n, int m);
int excluirY(int *l, int *n, int m);
int somaVetor(int *k, int *l, int *n,int m);

int main(){
	int a[4],a2[4],b[4],c[4],ab[4],bc[4],abbc[4],x,y,z;
	
	criaVetor(a, 4);	
	criaVetor(b, 4);
	criaVetor(c, 4);
		
	for(int i=0;i<4;i++){
		a2[i] = a[i];
	}
	
	if(b[2]==0){
		excluirZ(a,c,4);
		somaVetor(a,c,ab,4);
		excluirZ(c,b,4);
		somaVetor(c,b,bc,4);
		excluirY(ab, bc, 4);
		somaVetor(ab,bc,abbc,4);	
	}else{
		excluirZ(a,b,4);
		somaVetor(a,b,ab,4);	
		excluirZ(b,c,4);	
		somaVetor(b,c,bc,4);
		excluirY(ab, bc, 4);
		somaVetor(ab,bc,abbc,4);
	}
	
	
	printf("v=(%d,%d,%d) = v1=(%d,%d,%d); v2=(%d,%d,%d); v3=(%d,%d,%d).\n", a[3],b[3],c[3],a[2],b[2],c[2],a[1],b[1],c[1],a[0],b[0],c[0]);
	printf("v = a1.v1 + a2.v2 + a3.v3\n");
	printf("(%d,%d,%d) = a1.(%d,%d,%d) + a2.(%d,%d,%d) + a3.(%d,%d,%d)\n\n",a[3],b[3],c[3],a[2],b[2],c[2],a[1],b[1],c[1],a[0],b[0],c[0]);
	
	
	getch();
	x = abbc[3]/abbc[0];	
	y = (bc[3]-(bc[0]*x))/bc[1];	
	z = ((a2[3]-(a2[0]*x))-(a2[1]*y))/a2[2];
	printf("S = {(%d,%d,%d)}", x,y,z);
	
	getch();
}




int criaVetor(int *n, int m){
	int i;
	for(i=0;i<m;i++){	
		printf("Digite o %do valor da equacao:\n", i+1);
		scanf("%d", &n[i]);
		if(i==m-1){
			printf("----------------------\n\n");
		}
	}
}
int excluirZ(int *l, int *n, int m){
	int aux = l[2];
	int aux2 = n[2];
for(int i=0;i<m;i++){
	aux,aux2;	
	//if (l[2]!=0 && n[2]!=0){	
		l[i] *= -(aux2);
		n[i] *= aux;
	//	}
	}	
}
int excluirY(int *l, int *n, int m){
	int aux = l[1];
	int aux2 = n[1];
for(int i=0;i<m;i++){
	aux,aux2;	
	//if (l[1]!=0 && n[1]!=0){	
		l[i] *= -(aux2);
		n[i] *= aux;
	//	}
	}	
}

int somaVetor(int *k, int *l, int *n,int m){
	for(int i=0;i<m;i++){
		n[i] = k[i] + l[i];	
	}
	return *n;
}
