#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <time.h>
void SetColor(short Color) 
{ 
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); // oppure system("COLOR E9"); SetColor();
SetConsoleTextAttribute(hCon,Color); 
}
using namespace std;
const int green=2, lightBlue=3, red=4, purple=5, white=7, yellow=14;
const int  /* dimensioni mappa */altezza = 16, base = 30, NUM_ORCHI = 7,  NUM_MURI = 39,  NUM_PAV = 22,  NUM_PORTE=1,  NUM_CHIAVI=1, NUM_SPADE=1, NUM_OGGETTI=2;
char   /* mappa */map[altezza][base],   /* comando(dx,sx..) */cmd,   /* mappa vuota */nulla=' ';
/* coordinate */ int x,y;
bool running = true, portachiusa=false, chiaveOttenuta=false, portaSbloccata=false, spadaOttenuta=false;
int random,random2,i;
const int CHIAVE1=0,SPADA=1;
void personaggi();

//Eroe
int herox=0,heroy=0;
char hero='@';

//Vite
int nvite=3;
char vita='§';

//Oggetti
bool zainetto[NUM_OGGETTI]={false,false};
int spadax[NUM_SPADE],spaday[NUM_SPADE];
char spada='%';


//Orchi
int orcox[NUM_ORCHI],orcoy[NUM_ORCHI];
int inizorcox[NUM_ORCHI],inizorcoy[NUM_ORCHI];
char orco='#';

//Muri
int murox[NUM_MURI],muroy[NUM_MURI];
char muro='|';

//Pavimenti
int pavx[NUM_PAV],pavy[NUM_PAV];
char pav='-';

//Porte
int portax[NUM_PORTE],portay[NUM_PORTE];
char porta='/';

//Chiavi
int chiavex[NUM_CHIAVI],chiavey[NUM_CHIAVI];
char chiave='F';

//Funzioni
void bloccoPorta();
void muoviOrizzontale(int,int,int);
void personaggi();
void bloccoPav ();
void bloccoPavOrco ();
void bloccoMuro ();
void bloccoMuroOrco ();
void posiziona(int , int , char);
void blocco (int&,int,int);
void creaMappa();
void stampaMappa();
void muoviEroe ();
void muoviOrco(int);

	int main ()
	{             
	
	//Crea mappa
	creaMappa();
	personaggi();
	srand (time(NULL));
	
		while (running)
		{
	//posiziona
		for (i=0; i<NUM_ORCHI; i++){
			posiziona(orcoy[i],orcox[i],orco);
		}
		for (i=0; i<NUM_MURI; i++){
			posiziona(muroy[i],murox[i],muro);
		}
		for (i=0; i<NUM_PAV; i++){
			posiziona(pavy[i],pavx[i],pav);
		}
		for (i=0; i<NUM_PORTE; i++){
			posiziona(portay[i],portax[i],porta);
		}
		for (i=0; i<NUM_CHIAVI; i++){
			posiziona(chiavey[i],chiavex[i],chiave);
		}
		for (i=0; i<NUM_SPADE; i++){
			posiziona(spaday[i],spadax[i],spada);
		}
		
		//imposta posizione eroe
		posiziona(heroy,herox,hero);
		
	//Stampa mappa 
		stampaMappa();
		for (i=0; i<NUM_ORCHI; i++)
		{
		if (heroy==orcoy[i]&&herox==orcox[i]) nvite--;
		}
		if (nvite==0) goto end;
	//Numero vite
		cout<<endl<<"Vite:      ";
		SetColor(red);
		for (int i=0;i<nvite;i++)
		{cout<<vita<<" ";}
		SetColor(white);
		cout<<"  |";
	//Avvertenze
		if (portaSbloccata==true){
			cout<<"   Porta sbloccata";
		} portaSbloccata=false;
		if(portachiusa==true) {
			cout<<"   Porta bloccata";
			portachiusa=false;
		}
		if(chiaveOttenuta==true){
			cout<<"   Chiave ottenuta";
			chiaveOttenuta=false;
		}
		if(spadaOttenuta==true){
			cout<<"   Spada ottenuta";
			spadaOttenuta=false;
		}
	//Zainetto
		cout<<endl<<"Zainetto: ";
		for (int i=0;i<NUM_OGGETTI;i++){
			
		}
		if (zainetto[SPADA]==true){
			SetColor(green);
			cout<<" %";
			SetColor(white);
		}
		if (zainetto[CHIAVE1]==true){
			SetColor(yellow);
			cout<<" F";
			SetColor(white);
		}
		
	//movimento
	 	muoviEroe();
	 	for(int i=0;i<NUM_ORCHI;i++){
	 		/*Crea numero casuale*/	random=rand()%4+1; random2=rand()%2+1;
	 		muoviOrco(i);
		 }
	 	
	//Blocco
	 	bloccoMuro();
	 	bloccoMuroOrco();
	 	bloccoPav ();
	 	bloccoPorta ();
	 	
	//Azioni
	for(int i=0; i<NUM_CHIAVI; i++){
		if (heroy==chiavey[i]&&herox==chiavex[i]){
			map[chiavey[i]][chiavex[i]]=
			chiavey[i]=altezza-1; chiavex[i]=5;
			chiaveOttenuta=true;
			zainetto[CHIAVE1]=true;
		}
	}
	for(int i=0; i<NUM_SPADE; i++){
		if (heroy==spaday[i]&&herox==spadax[i]){
			spaday[i]=altezza-1; spadax[i]=1;
			spadaOttenuta=true;
			zainetto[SPADA]=true;
		}
	}

		}
		end:
		system ("cls");
		cout << "HAI PERSO"<<endl;
		system ("PAUSE");
		return 0;
	}

//funzione blocco pav
void bloccoPav ()
{
	for (i=0; i<NUM_PAV; i++)
		{
			if (heroy==pavy[i]&&herox==pavx[i])
			{
				if (cmd==72)
				{
				heroy++;
				}
				if (cmd==80)
				{
				heroy--;
				}
				if (cmd==75)
				{
				herox++;
				}
				if (cmd==77)
				{
				herox--;
				}
			}
		}
}
//funzione blocco pav orco
void bloccoPavOrco()
{
	for (i=0; i<NUM_PAV; i++)
		{
			for (int j=0; j<NUM_ORCHI; i++)
			{
				if (orcoy[j]==pavy[i]&&orcox[j]==pavx[i])
				{
				if (random==1)
				{
				orcoy[j]++;
				}
				if (random==2)
				{
				orcoy[j]--;
				}
				if (random==3)
				{
				orcox[j]++;
				}
				if (random==4)
				{
				orcox[j]--;
				}
				}
			}
			
		}
}
//funzione blocco muro
void bloccoMuro ()
{
	for (i=0; i<NUM_MURI; i++)
		{
			if (heroy==muroy[i]&&herox==murox[i])
			{
				if (cmd==72)
				{
				heroy++;
				}
				if (cmd==80)
				{
				heroy--;
				}
				if (cmd==75)
				{
				herox++;
				}
				if (cmd==77)
				{
					herox--;
				}
			}
		}
}
//funzione blocco muro orco
void bloccoMuroOrco ()
{
	for (i=0; i<NUM_MURI; i++)
		{
			for (int j=0;i<NUM_ORCHI;i++)
			{
				if (orcoy[j]==muroy[i]&&orcox[j]==murox[i])
				{
				if (random==1)
				{
				orcoy[j]++;
				}
				if (random==2)
				{
				orcoy[j]--;
				}
				if (random==3)
				{
				orcox[j]++;
				}
				if (random==4)
				{
				orcox[j]--;
				}
				}	
			}
			
		}
}
void verificaSpada(){
	for (i=0; i<NUM_SPADE; i++)
		{
			
			if (heroy==spaday[i]&&herox==spadax[i]){
				spaday[i]=altezza-1; spadax[i]=2;
				zainetto[SPADA]=true;
			}
			
		}
}
void bloccoPorta ()
{
	for (i=0; i<NUM_PORTE; i++)
		{
			if ((heroy==portay[i]&&herox==portax[i])&&zainetto[CHIAVE1]==false)
			{
				if (cmd==72)
				{
				heroy++;
				}
				if (cmd==80)
				{
				heroy--;
				}
				if (cmd==75)
				{
				herox++;
				}
				if (cmd==77)
				{
					herox--;
				}
				portachiusa=true;
			}
			else if ((heroy==portay[i]&&herox==portax[i])&&zainetto[CHIAVE1]==true){
				portay[i]=altezza-1; portax[i]=1;
				zainetto[CHIAVE1]=false;
				portaSbloccata=true;
			}
			
		}
}
//funzione muovi eroe
void muoviEroe ()
{
	map [heroy][herox]= nulla;
	cmd=getch();
	if (cmd==72)
	{
	heroy--;
	blocco (heroy,0,altezza-2);
	}
	if (cmd==80)
	{
	heroy++;
	blocco (heroy,0,altezza-2);
	}
	if (cmd==75)
	{
	herox--;
	blocco (herox,0,base-1);
	}
	if (cmd==77)
	{
	herox++;
	blocco (herox,0,base-1);
	}
	if (zainetto[SPADA]==true){
		if (cmd=='w')
		{
			for (int i=0;i<NUM_ORCHI;i++){
				if (heroy-1==orcoy[i]&&herox==orcox[i]){
					map[orcoy[i]][orcox[i]]=nulla;
					orcoy[i]=altezza-1;
					orcox[i]=2;
				}
			}
		}
		if (cmd=='s')
		{
			for (int i=0;i<NUM_ORCHI;i++){
				if (heroy+1==orcoy[i]&&herox==orcox[i]){
					map[orcoy[i]][orcox[i]]=nulla;
					orcoy[i]=altezza-1;
					orcox[i]=2;
				}
			}
		}
		if (cmd=='a')
		{
			for (int i=0;i<NUM_ORCHI;i++){
				if (heroy==orcoy[i]&&herox-1==orcox[i]){
					map[orcoy[i]][orcox[i]]=nulla;
					orcoy[i]=altezza-1;
					orcox[i]=2;
				}
			}
		}
		if (cmd=='d')
		{
			for (int i=0;i<NUM_ORCHI;i++){
				if (heroy==orcoy[i]&&herox+1==orcox[i]){
					map[orcoy[i]][orcox[i]]=nulla;
					orcoy[i]=altezza-1;
					orcox[i]=2;
				}
			}
		}
	}
		
		
		
	if (cmd=='q')
	{
	running=false; 
	}
	system ("cls");
}
//funzione Crea Mappa
void creaMappa()
{
	for (y=0; y<altezza; y++){
		for (x=0; x<base; x++)
		{
			map [y][x] = nulla;
		}
	}
	map [heroy][herox]= hero;
}
//funzione posiziona personaggi
void posiziona(int y, int x, char personaggio)
{
	map [y][x]= personaggio;
}
//Funzione stampa mappa
void stampaMappa()
{
	for (y=0; y<altezza-1; y++){
		for (x=0; x<base; x++)
		{
			if(map[y][x]==chiave) {SetColor(yellow);}
			cout << map [y][x];
			SetColor(white);
		}
		cout<<endl;
	}
}
//funzione per non uscire dalla mappa
void blocco (int& valore, int min, int max)
{
	if (valore<min)
	{
		valore=min;
		return;
	}
	if (valore>max)
	{
		valore=max;
		return;
	}
}
//funzione per muovere gli orchi
void muoviOrco(int i)
{
	if (orcoy[i]!=altezza-1){
		int ymin=inizorcoy[i]-2;
		int ymax=inizorcoy[i]+2;
		int xmin=inizorcox[i]-2;
		int xmax=inizorcox[i]+2;
	 	map [orcoy[i]][orcox[i]]=nulla;
	 	if (random==1)
		{
		orcoy[i]=orcoy[i]-random2;
		blocco (orcoy[i],ymin,ymax);
		blocco (orcoy[i],0,altezza-2);
		}
		else if (random==2)
		{
		orcoy[i]=orcoy[i]+random2;
		blocco (orcoy[i],ymin,ymax);
		blocco (orcoy[i],0,altezza-2);
		}
		else if (random==3)
		{
		orcox[i]=orcox[i]-random2;
		blocco (orcox[i],xmin,xmax);
		blocco (orcox[i],0,base-1);
		}
		else if (random==4)
		{
		orcox[i]=orcox[i]+random2;
		blocco (orcox[i],xmin,xmax);
		blocco (orcox[i],0,base-1);
		}
	}
	
}
//funzione per muovere gli orchi in verticale
void muoviOrizzontale(int i, int ymin, int ymax)
{
 	map [orcoy[i]][orcox[i]]=nulla;
 	if (random==1||random==2)
	{
	orcoy[i]--;
	blocco (orcoy[i],ymin,ymax);
	}
	else if (random==3||random==4)
	{
	orcoy[i]++;
	blocco (orcoy[i],ymin,ymax);
	}
}

//funzione per mettere i personaggi INIZIALMENTE sulla mappa
void personaggi()
{                  
//Orchi
orcox[0]=2,orcoy[0]=4; inizorcox[0]=2,inizorcoy[0]=5;
orcox[1]=3,orcoy[1]=9; inizorcox[1]=3,inizorcoy[1]=9;
orcox[2]=2,orcoy[2]=11; inizorcox[2]=2,inizorcoy[2]=11;
orcox[5]=11,orcoy[5]=1; inizorcox[5]=11,inizorcoy[5]=1;
orcox[6]=27,orcoy[6]=2; inizorcox[6]=27,inizorcoy[6]=2;
orcox[3]=27,orcoy[3]=8; inizorcox[3]=27,inizorcoy[3]=8;
orcox[4]=27,orcoy[4]=12; inizorcox[4]=27,inizorcoy[4]=12;

chiavex[0]=2,chiavey[0]=14;
spadax[0]=10,spaday[0]=3;


//Porte
portax[0]=6,portay[0]=1;    
//Muri
i=0;
murox[0]=6,muroy[0]=2;
murox[1]=6,muroy[1]=3;
murox[2]=6,muroy[2]=4;
murox[3]=6,muroy[3]=5;
murox[4]=6,muroy[4]=6;
murox[5]=6,muroy[5]=7;
murox[6]=6,muroy[6]=8;
murox[7]=6,muroy[7]=9;
murox[8]=6,muroy[8]=10;
murox[9]=6,muroy[9]=11;
murox[10]=6,muroy[10]=12;
murox[11]=6,muroy[11]=13;
murox[12]=6,muroy[12]=14;

i=13; murox[i]=15,muroy[i]=3;
i++; murox[i]=15,muroy[i]=4;
i++; murox[i]=15,muroy[i]=5;
i++; murox[i]=15,muroy[i]=6;
i++; murox[i]=15,muroy[i]=7;
i++; murox[i]=15,muroy[i]=8;

i++; murox[i]=15,muroy[i]=11;
i++; murox[i]=15,muroy[i]=12;
i++; murox[i]=15,muroy[i]=13;
i++; murox[i]=15,muroy[i]=14;

i++; murox[i]=24,muroy[i]=0;
i++; murox[i]=24,muroy[i]=1;
i++; murox[i]=24,muroy[i]=4;
i++; murox[i]=24,muroy[i]=5;
i++; murox[i]=24,muroy[i]=6;

i++; murox[i]=24,muroy[i]=9;
i++; murox[i]=24,muroy[i]=10;
i++; murox[i]=24,muroy[i]=13;
i++; murox[i]=24,muroy[i]=14;

i++; murox[i]=11,muroy[i]=7;
i++; murox[i]=11,muroy[i]=8;
i++; murox[i]=11,muroy[i]=9;
i++; murox[i]=11,muroy[i]=10;
i++; murox[i]=11,muroy[i]=11;
i++; murox[i]=11,muroy[i]=12;
i++; murox[i]=6,muroy[i]=0;

//Pavimenti
i=0; pavx[i]=0,pavy[i]=2;
i++; pavx[i]=1,pavy[i]=2;
i++; pavx[i]=2,pavy[i]=2;
i++; pavx[i]=3,pavy[i]=2;

i++; pavx[i]=7,pavy[i]=4;
i++; pavx[i]=8,pavy[i]=4;
i++; pavx[i]=9,pavy[i]=4;
i++; pavx[i]=10,pavy[i]=4;
i++; pavx[i]=11,pavy[i]=4;
i++; pavx[i]=12,pavy[i]=4;
i++; pavx[i]=13,pavy[i]=4;
i++; pavx[i]=14,pavy[i]=4;

i++; pavx[i]=25,pavy[i]=5;
i++; pavx[i]=26,pavy[i]=5;
i++; pavx[i]=27,pavy[i]=5;
i++; pavx[i]=28,pavy[i]=5;
i++; pavx[i]=29,pavy[i]=5;

i++; pavx[i]=25,pavy[i]=10;
i++; pavx[i]=26,pavy[i]=10;
i++; pavx[i]=27,pavy[i]=10;
i++; pavx[i]=28,pavy[i]=10;
i++; pavx[i]=29,pavy[i]=10;
}




