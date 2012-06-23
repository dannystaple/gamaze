// gamazeView.cpp : implementation of the CGamazeView class
//

#include "stdafx.h"
#include "gamaze.h"

#include "gamazeDoc.h"
#include "gamazeView.h"
#include "SetStep.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGamazeView

IMPLEMENT_DYNCREATE(CGamazeView, CView)

BEGIN_MESSAGE_MAP(CGamazeView, CView)
	//{{AFX_MSG_MAP(CGamazeView)
	ON_COMMAND(ID_SETSTEP, OnSetstep)
	ON_COMMAND(ID_StepGen, OnStepGen)
	ON_COMMAND(ID_Stop, OnStop)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGamazeView construction/destruction

CGamazeView::CGamazeView()
{
	// TODO: add construction code here

}

CGamazeView::~CGamazeView()
{
}

BOOL CGamazeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGamazeView drawing

void CGamazeView::OnDraw(CDC* pDC)
{
	CGamazeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


	// TODO: add draw code for native data here
	int x=0,y=0,row=0, column=0;
	TEXTMETRIC tSize;//Text metrics
	pDC->GetTextMetrics(&tSize);//Get the metrics
	row=tSize.tmHeight;//The text height
	column=tSize.tmAveCharWidth;//Average character width
	for(int count=0; count< pDoc->outFile.GetLength(); count++)
	{
		if(pDoc->outFile[count]=='\n') 
		{
			x=0; y+=row;
		}
		else
		{
			pDC->TextOut(x,y,pDoc->outFile[count]);
			x+=pDC->GetTextExtent(pDoc->outFile[count]).cx;
		}
	}	
}

/////////////////////////////////////////////////////////////////////////////
// CGamazeView printing

BOOL CGamazeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CGamazeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGamazeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGamazeView diagnostics

#ifdef _DEBUG
void CGamazeView::AssertValid() const
{
	CView::AssertValid();
}

void CGamazeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGamazeDoc* CGamazeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGamazeDoc)));
	return (CGamazeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGamazeView message handlers

void CGamazeView::OnSetstep() 
{
	// TODO: Add your command handler code here
	CGamazeDoc * pDoc=GetDocument();
	CSetStep stepWnd;
	stepWnd.m_Value=10;
	stepWnd.DoModal();
	pDoc->nToStep=stepWnd.m_Value;
}

void CGamazeView::OnStepGen() 
{
	// TODO: Add your command handler code here
	int gen, best;
	float avg;
	char buffer[6];
	CGamazeDoc * pDoc=GetDocument();

	//pDoc->UpdateAllViews();//Redraw Document
		for(int count=0; count<pDoc->nToStep; count++)
		{
			pDoc->theSim->stepGeneration();
			gen=pDoc->theSim->getGeneration();
			best=pDoc->theSim->getBestFit();//Best fitness
			avg=pDoc->theSim->getMean();//Mean fitness
			itoa(gen,buffer,10);
			pDoc->outFile=pDoc->outFile+buffer+", ";
			itoa(best,buffer,10);
			pDoc->outFile=pDoc->outFile+buffer+", ";
			gcvt(avg,7,buffer);
			pDoc->outFile=pDoc->outFile+buffer+", "; 
			best=pDoc->theSim->calcSumFitness();
			itoa(best,buffer,10);
			pDoc->outFile=pDoc->outFile+buffer+"\n";
			Invalidate(TRUE);
		}

}


void CGamazeView::OnStop() 
{
	// TODO: Add your command handler code here
	CGamazeDoc * pDoc=GetDocument();
	//pDoc->mainSim->SuspendThread();
	Invalidate(TRUE);

}

void CGamazeView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	SetScrollSizes(MM_TEXT,GetDocument()->GetSize());//Setup the scrollbar size
}

void CGamazeView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CSize st(320,400);//Initial Size
	SetScrollSizes(MM_TEXT,st);//Setup the scrollbar size
}
