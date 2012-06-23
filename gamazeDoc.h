// gamazeDoc.h : interface of the CGamazeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMAZEDOC_H__E31FBE4F_6F79_11D2_B9F1_A20BD43CE868__INCLUDED_)
#define AFX_GAMAZEDOC_H__E31FBE4F_6F79_11D2_B9F1_A20BD43CE868__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "ga.h"

class CGamazeDoc : public CDocument
{
protected: // create from serialization only
	CGamazeDoc();
	DECLARE_DYNCREATE(CGamazeDoc)

// Attributes
public:
	CGa * theSim;//The main simulation attribute
	CMaze * mainMaze;//The maze variable
	CString outFile;//The output log file
	CString docName;//The document name
	int nToStep; //Number of generations to step
	//CWinThread * mainSim;//#The thread address
// Operations
public:
	
	CSize GetSize();//Returns the current document size
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGamazeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGamazeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGamazeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMAZEDOC_H__E31FBE4F_6F79_11D2_B9F1_A20BD43CE868__INCLUDED_)
