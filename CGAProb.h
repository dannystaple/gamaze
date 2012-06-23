//CGA Prob- The problem class- a base class for all GA problems posed
//Note- this has no C++ code- as it has no implementation
#ifndef CGAPROB_H
#define CGAPROB_H

class CGAProb:public CDocument {//Abstract GA Problem class
public:
	//Public members 
	virtual char * getgeneType()=0;
	virtual int getnGenes()=0;//0 if variable

//    virtual char * getName()=0;//Returns a string holding name of this type
	virtual int testIndiv(char * Genes)=0;//Performs a fitness test on an individual
//	virtual void draw(CDC * OutWnd)=0;//Draws a representation of the object
	virtual void Serialize(CArchive& ar)=0;//Save load
	virtual void Dump(CDumpContext & dc)=0;//Printer dump
};

#endif