/* ****************************************************** *\
 * ga.h													  *
 * ------------------------------------------------------ *
 * AUthor: Daniel Staple								  *
 * Date : --\--\--										  *
 * Details: Contains the classes mouse(the creatures) and *
 * ga- which conatins mutation, crossover etc.....        *
\* ****************************************************** */

//#include "CLinkList.h" //uses link list functions
#include "CGAProb.h" //The CGA Problems header
#include <afxwin.h>  //MFC Bits
#ifndef CGA_H
#define CGA_H

class CMaze:public CGAProb  {
	friend class CGa;
public:
	CMaze();
	~CMaze();
	static char * geneType;
	static int nGenes;
	char * getgeneType();//returns the genetype
	int DAward, DPenalty, GAward, IPenalty;//Awards and penalties
	int getnGenes() {return nGenes;};//Returns number of genes
protected:
	char mazeRep[8][9];
	CPoint findNextDecision(CPoint pos, CPoint dir);
	CPoint static const north,south,
			east, west;
	int testIndiv(char *Genes);//Test an individual
	void Dump(CDumpContext & dc);//Dump to a printer
	void Serialize(CArchive & ar);//Store or retrieve from disk

};

class CMouse {//The individual population members class
friend class CGa;
protected:
	//Protected data members
	int fitness;  //A rating out of 100 for its fitness
	char genes[8]; //This mouse's genetic stock

	//Protected functions
	CGa * Parent;//Pointer to the parent GA- Needed
public:
	//Public functions
	CMouse();//Default constructor
	CMouse(CMouse parenta, CMouse parentb);//Construct new offspring
	~CMouse();//Destructor
	static char * geneType;//This can be set up by the GA constructor
	static int nGenes;//This as well.
	static int CrossType;//The current crossover methods.
	static int mutate;//The avarage mutation rate
	char * getGenes();//Returns a copy of the mouses genetic info
};

class CGa:public CDocument {
protected:
	CMouse * mice;//A dynamic list of mice.
	int generation;//The current generation
	int fitsum, bestFit; // Sum of all the fitnesses, best fitness
	int fitrcsum;//Reciprocal sum of fitnesses

	char * bestGenes;//The best genotype in the current generation
public:
	int population;//The number of members within the population
	CMaze * maze; //The current problem(polymorphic)(CGAProb)
	CGa(CMaze *);//Default constructor uses dialog box
	~CGa();//Object destructor
	void stepGeneration();//Step to a new generation
	int getBestFit();//Get the best fitness score
    int calcSumFitness();//Calculate the sum of all the fitnesses
	int calcRecip();//Calculate reciprocal sum of fitnesses
	float getMean();//Get mean fitness
	int selectMate();//Select a viable mate
	void testMice();//Test all the mice in one simple function
	int getGeneration();//Get the number of generations
	int selectReplace();//Function to select mice for replacement
	void breedMice();//Breed the mice together
	char * getBestFitGenes();//Get the genetic info of th best specimen
};
#endif