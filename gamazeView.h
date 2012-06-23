// gamazeView.h : interface of the CGamazeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMAZEVIEW_H__E31FBE51_6F79_11D2_B9F1_A20BD43CE868__INCLUDED_)
#define AFX_GAMAZEVIEW_H__E31FBE51_6F79_11D2_B9F1_A20BD43CE868__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CGamazeView : public CScrollView
{
protected: // create from serialization only
	CGamazeView();
	DECLARE_DYNCREATE(CGamazeView)

// Attributes
public:
	CGamazeDoc* GetDocument();
	CToolBar m_wndToolBar;//A toolbar


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGamazeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGamazeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGamazeView)
	afx_msg void OnSetstep();
	afx_msg void OnStepGen();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in gamazeView.cpp
inline CGamazeDoc* CGamazeView::GetDocument()
   { return (CGamazeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMAZEVIEW_H__E31FBE51_6F79_11D2_B9F1_A20BD43CE868__INCLUDED_)
