/* ******************************************************* *\
 * ga.cpp-                                                 *
 * ------------------------------------------------------- *
 * Implementation for ga creatures, crossover, mutation    *
 * fitness testing etc.....    This contains fn defs  for  *
 * classes cmouse, cga.									   *
\* ******************************************************* */

#include <stdafx.h>
#include "ga.h"
#include "NGADlg.h" //The dialog box for a new GA
#include <string.h>

#include <stdlib.h>  //Random function

inline int random(int __num)
                 { return(int)(((long)rand()*__num)/(RAND_MAX+1)); }



CMouse::CMouse()//Default mouse constructor
{
	fitness=0;//not been ranked yet
	char gtemp[9];//temporary for genes
	for (int count=0; count<8; count++)
	{
		gtemp[count]=geneType[random(strlen(geneType))];
	}
	gtemp[8]='\0';
	strcpy(genes,gtemp);
}

CMouse::~CMouse()//
{}

CMouse::CMouse(CMouse parenta,CMouse parentb)//Breeding constructor
{
	int count;
	//Crossover code
	fitness=0;//Not yet ranked
	char gtemp[9];//Temporary genestore
	switch (CrossType)
	{
	case 0:
		//standard AAAA/BBBB code
		strncpy(gtemp,parenta.genes,4);//Copy first half
		strncpy(&gtemp[4],&parentb.genes[4],4);//Copy second half
		break;
	case 1:
		//ABABABAB code
		for (count=0; count<8; count+=2)
		{
			gtemp[count]=parenta.genes[count];//Copy gene from first parent
			gtemp[count+1]=parentb.genes[count+1];//Copy gene from second parent
		}
		break;
	default://Third case just in case
		//standard AA/BBBBBB code
		strncpy(gtemp,parenta.genes,2);//Copy first segment
		strncpy(&gtemp[2],&parentb.genes[2],6);//copy second segment
		break;

	}
		gtemp[8]='\0';


	//Mutation
	if(random(mutate)==1)//Some number between one and mutation rate
	{
		gtemp[random(7)]=geneType[random(3)];//mutate a gene
	}
	strcpy(genes,gtemp);
}

int CMouse::nGenes;
char * CMouse::geneType;
int CMouse::CrossType;//The current crossover methods.
int CMouse::mutate;//The avarage mutation rate


char * CMouse::getGenes()
{
	char * temp=" ";//Give this a default for allocation purposes
	strcpy(temp,genes);
	return temp;
}

CGa::CGa(CMaze * nPr)//The default constructor
{
	maze=nPr;//Set the maze problem variable
	NGADlg * d=new NGADlg();//Make sure it is instanciated
	//char * tempch, * tempch2;
	CMouse::geneType=maze->getgeneType();//copy string over
	//strcpy(tempch,
	//	tempch2);
	//tempch;
	CMouse::nGenes=maze->getnGenes();
	int stat;
	TRACE0("**** *** Displaying Dialog *** ****\r\n");
	stat=d->DoModal();
	TRACE0("*** **** Creating Mice **** ***\r\n");
	if (stat==IDOK)
	{
		CMouse::CrossType=d->m_CrossOverMethod;//Set the current breeding style
		CMouse::mutate=d->m_Mutate;
		population=d->m_Population;
		mice=new CMouse[population];
		TRACE1("Population %i",population);
		TRACE1("Mouse 1: %s",mice[1].getGenes());
		generation=0;
		maze->DAward=d->m_DAward;
		maze->DPenalty=d->m_dPenalty;
		maze->GAward=d->m_GAward;
		maze->IPenalty=d->m_IPenalty;
	};
	TRACE0("Done!\r\n");
}

void CGa::breedMice()//Function to breed the mice
{
	int ntosel=population /2;//Breed 50% of the population
	int current=0;
	CMouse a , b,  c, d;
	int iD;//The index of the mouse to be replaced
	CMouse * temp;
	do 
	{
		a=mice[selectMate()];//select parent a
		b=mice[selectMate()];//select parent b
		iD=selectReplace();//select a mouse to be replaced
		d=mice[iD];
		TRACE1("Mouse D genetics before:%s .... \r\n",d.genes);
		temp=new CMouse(a,b);//Breed mice
		memcpy(&mice[iD],temp, sizeof(CMouse));//Replcae old mouse with new
		delete temp;
		current++;
		TRACE1("Mouse D genetics after:%s .\r\n",d.genes);
	}
	while(current<ntosel);
}

int CGa::getBestFit()
{
	return bestFit;
}

int CGa::selectReplace()//Function to select mice for replacement
{
	return random(population-1);
}

int CGa::calcRecip()//Calculate reciprocal sum
{
	fitrcsum=0;
	int current=0;
	do
	{
		fitrcsum+=20/mice[current++].fitness;
	}
	while(current<population);
	return fitrcsum;
}


int CGa::selectMate()
{
	int roulette=random(fitsum);
	int accum=0, current=-1;
	accum=0;
	do {
		accum+=mice[++current].fitness;
	} while ( current<population&&accum<roulette);
	if (current==population)
		current--;
	return current;
}

int CGa::calcSumFitness()
{
	fitsum=0;
	int current=0;
	do {
		fitsum+=mice[current++].fitness;
	} while (current<population);
	return fitsum;
}

void CGa::stepGeneration()//Step to the next generation
{
	testMice();
	calcSumFitness();
	breedMice();
	generation++;
}

char * CGa::getBestFitGenes()//Return a char pointer to the best genetic code
{
	return bestGenes;
}

float CGa::getMean()//Return the mean average of the fitness
{
	return fitsum/(population*1.0);
}

void CGa::testMice()//Test the mice
{
	int current=0, fitness;
	bestFit=0;//Set the best fitness to nil
	do 
	{
		fitness=maze->testIndiv(mice[current].getGenes());//Test in maze
		if (fitness>bestFit) 
		{
			bestFit=fitness;//Test for fitest gene
			bestGenes=mice[current].genes;//Set pointer to the genetic info
		}
		mice[current].fitness=fitness;//Set the fitness
		current++;
	} while(current<population);
}

CGa::~CGa()
{
	delete [] mice;//deallocate memory
}

CMaze::CMaze()
{
	strcpy(mazeRep[0],"d D D  #");
	strcpy(mazeRep[1]," # # ###");
	strcpy(mazeRep[2]," ### ## ");
	strcpy(mazeRep[3],"D # D  D");
	strcpy(mazeRep[4]," ## ### ");
	strcpy(mazeRep[5],"  # # D ");
	strcpy(mazeRep[6],"#D D # #");
	strcpy(mazeRep[7],"  ## # G");
}

char * CMaze::getgeneType()//Returns the genetic options
{
	char * temp=" ";//give it a null
	strcpy(temp,CMaze::geneType);//Create a copy of this static variable
	return temp;//Return the temp
}
	
CMaze::~CMaze()
{}

void CMaze::Serialize(CArchive &ar)//Dummy function for now
{
  	if (ar.IsStoring())
	{
		// TODO: add storing code here
		
	}
	else
	{
		// TODO: add loading code here
	}
}

char * CMaze::geneType="NSEW";//Set geneType
int CMaze::nGenes=8;

const CPoint CMaze::north=CPoint(0,-1), 
CMaze::south=CPoint(0,1),
CMaze::east=CPoint(1,0), 
CMaze::west=CPoint(-1,0);

void CMaze::Dump(CDumpContext & dc)//Dump to a printer
{
	CDocument::Dump(dc);
}

CPoint CMaze::findNextDecision(CPoint pos, CPoint dir)
{
	CPoint temp, newdir;
	char curmaze;//Current maze character
	newdir=dir;//Set the new direction to the current one
	do
	{
		temp=pos+newdir;
		if(temp.x>=0&&temp.y>=0&&temp.x<8&&temp.y<8)
		{
			curmaze=mazeRep[temp.y][temp.x];
			if(curmaze!='#')
			{
				pos=temp;
				memcpy(&dir,&newdir,sizeof(CPoint));
			}
		}
		else
			curmaze='#';//Out of bounds hits wall
		if(curmaze=='#')//If a wall is hit
		{
			if(dir==north)
			{
				if(newdir==north)
					memcpy(&newdir,&east,sizeof(CPoint));
				else if (newdir==east)
					memcpy(&newdir,&west,sizeof(CPoint));
				else if (newdir==west)
					memcpy(&newdir,&south,sizeof(CPoint));
			}
			if(dir==east)
			{
				if (newdir==east)
					memcpy(&newdir,&north,sizeof(CPoint));
				else if (newdir==north)
					memcpy(&newdir,&south,sizeof(CPoint));
				else if (newdir==south)
					memcpy(&newdir,&west,sizeof(CPoint));
			}
			if(dir==south)
			{
				if (newdir==south)
					memcpy(&newdir,&west,sizeof(CPoint));
				else if (newdir==west)
					memcpy(&newdir,&east,sizeof(CPoint));
				else if (newdir==east)
					memcpy(&newdir,&north,sizeof(CPoint));
			}
			if(dir==west)
			{
				if (newdir==west)
					memcpy(&newdir,&north,sizeof(CPoint));
				else if (newdir==north)
					memcpy(&newdir,&south,sizeof(CPoint));
				else if (newdir==south)
					memcpy(&newdir,&east,sizeof(CPoint));
			}

			curmaze=' ';
		}
	}
	while(curmaze==' '||curmaze=='#');
	return pos;
}

int CGa::getGeneration() 
{return generation;}//Get the number of generations


int CMaze::testIndiv(char *Genes)
{
	CPoint pos(0,0);
	int n=0, fitness=0;
	mazeRep[0][0]='d';//Make sure base decision is set as visited
	do {
		if((pos.y==0&&Genes[n]=='N')||
			(pos.y==7&&Genes[n]=='S')||
			(pos.x==0&&Genes[n]=='W')||
			(pos.x==7&&Genes[n]=='E'))
			//Boundary testing
		{ fitness-=IPenalty; //Penalise(0 at mo)
		}
		else
		{
			switch(Genes[n])
			{
			case 'N':
				if(mazeRep[pos.y-1][pos.x]!='#')//Make sure there is no wall	
					pos=findNextDecision(pos, north);//Find the next decision spot
				break;
			case 'S':
				if(mazeRep[pos.y+1][pos.x]!='#')//Make sure there is no wall	
					pos=findNextDecision(pos, south);
				break;
			case 'E':
				if(mazeRep[pos.y][pos.x+1]!='#')//Make sure there is no wall	
					pos=findNextDecision(pos, east);
				break;
			case 'W':
				if(mazeRep[pos.y][pos.x-1]!='#')//Make sure there is no wall	
					pos=findNextDecision(pos, west);
			}
			if(mazeRep[pos.y][pos.x]=='D') 
			{
				fitness+=DAward;//Reward if it gets to new decision point
				mazeRep[pos.y][pos.x]='d';
			}
			else
			{
				if (mazeRep[pos.y][pos.x]=='G')
					fitness+=GAward;//Reward three for reaching goal
				if (mazeRep[pos.y][pos.x]=='d')
				{
					if(fitness>0)
					  fitness-=DPenalty;//Penalty for returning to the same decision point.
				}
			}
		}
		n++;//Increment the gen counter
	}
	while (n<8&&mazeRep[pos.x][pos.y]!='G');//While there is still
	//genetic information left to process and the goal has not been reached
    for(int x=0;  x<8; x++)//Reset decsision points
		for(int y=0; y<8; y++)
		{
			if(mazeRep[x][y]=='d')
				mazeRep[x][y]='D';
		}
	return fitness;//Return the fitness value
}

