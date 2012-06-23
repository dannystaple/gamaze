#if !defined(AFX_SETSTEP_H__FF3F3B23_7D2D_11D2_B9F1_CCEAE26E9955__INCLUDED_)
#define AFX_SETSTEP_H__FF3F3B23_7D2D_11D2_B9F1_CCEAE26E9955__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SetStep.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetStep dialog

class CSetStep : public CDialog
{
// Construction
public:
	CSetStep(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetStep)
	enum { IDD = IDD_DIALOG1 };
	int		m_Value;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetStep)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetStep)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSTEP_H__FF3F3B23_7D2D_11D2_B9F1_CCEAE26E9955__INCLUDED_)
