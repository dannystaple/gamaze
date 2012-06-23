// gamazeDoc.cpp : implementation of the CGamazeDoc class
//

#include "stdafx.h"
#include "gamaze.h"
#include "ga.h"
#include "CreateNewDlg.h"

#include "gamazeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGamazeDoc

IMPLEMENT_DYNCREATE(CGamazeDoc, CDocument)

BEGIN_MESSAGE_MAP(CGamazeDoc, CDocument)
	//{{AFX_MSG_MAP(CGamazeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGamazeDoc construction/destruction

CGamazeDoc::CGamazeDoc()
{
	// TODO: add one-time construction code here

}

CGamazeDoc::~CGamazeDoc()
{
	delete theSim;
	delete mainMaze;
//	if(	mainSim!=NULL)
//	{
//		mainSim->SuspendThread();//Attemp to suspend
		//delete mainSim;//Kill it
//	}
}

BOOL CGamazeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	//Mazes and Ga problems
	
	char buffer[10];//Buffer for numeric to text conversions
	CCreateNewDlg newDlg;
	newDlg.DoModal();//create the modal dialog display
	if(newDlg.m_DocType==0)
	{
		//New GA code
		mainMaze=new CMaze();//Create a maze instance
		TRACE0("*#*#*# Creating Simulation #*#*#*\r\n");
		//create beginning of csv file
		TRACE0(" Created first line of output\r\n");
		//CGa temp(mainMaze);//Create sim instance
		theSim=new CGa(mainMaze);//& temp;//And the CGA simulation#
		itoa(CMouse::CrossType,buffer, 10);
		outFile="Ga Maze Run.  Crossover: ";
		outFile+=buffer;
		itoa(theSim->population,buffer, 10);
		outFile+="\r\nPopulaton :";
		outFile+=buffer;
		itoa(CMouse::mutate,buffer, 10);
		outFile+=" Mutation:";
		outFile+=buffer;
		itoa(theSim->maze->DAward,buffer, 10);
		outFile+="\r\nNew D Award:";
		outFile+=buffer;
		itoa(theSim->maze->DPenalty,buffer, 10);
		outFile+="\r\nOld D Penalty:";
		outFile+=buffer;
		itoa(theSim->maze->GAward,buffer, 10);
		outFile+="\r\nGoal Award:";
		outFile+=buffer;
		itoa(theSim->maze->IPenalty,buffer, 10);
		outFile+="\r\nInvalid Direction Penalty:";
		outFile+=buffer;
		outFile+="\r\nGeneration, Fitness,,\r\n, Mean, Max\r\n";
		nToStep=10;//The default step number
	}
	else
	{
		//New Maze code
	}
	docName=newDlg.m_FileName;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGamazeDoc serialization

void CGamazeDoc::Serialize(CArchive& ar)
{
//	Simulation->Serialize(ar);//Use CGA's own storage methods
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << outFile;
	}
	else
	{
		// TODO: add loading code here
		ar >> outFile;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGamazeDoc diagnostics

#ifdef _DEBUG
void CGamazeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGamazeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGamazeDoc commands
CSize CGamazeDoc::GetSize()//Get the height and width
{
	CSize temp;
	temp.cx=320;
	temp.cy=40+20*theSim->getGeneration();
	return temp;
}