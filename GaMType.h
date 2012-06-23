#if !defined(AFX_GAMTYPE_H__EE35EB82_7963_11D2_B9F1_952F5521C956__INCLUDED_)
#define AFX_GAMTYPE_H__EE35EB82_7963_11D2_B9F1_952F5521C956__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GaMType.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGaMType document

class CGaMType : public CDocument
{
protected:
	CGaMType();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CGaMType)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaMType)
	public:
	virtual void OnFinalRelease();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGaMType();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CGaMType)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CGaMType)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMTYPE_H__EE35EB82_7963_11D2_B9F1_952F5521C956__INCLUDED_)
