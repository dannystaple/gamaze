#if !defined(AFX_NGADLG_H__36C3DE01_73D5_11D2_B9F1_BA8FA8FE6654__INCLUDED_)
#define AFX_NGADLG_H__36C3DE01_73D5_11D2_B9F1_BA8FA8FE6654__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// NGADlg.h : header file
//
#include "Resource.h"

/////////////////////////////////////////////////////////////////////////////
// NGADlg dialog

class NGADlg : public CDialog
{
// Construction
public:
	NGADlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(NGADlg)
	enum { IDD = IDD_NEWDIALOG1 };
	int		m_Population;
	int		m_Mutate;
	int		m_DAward;
	int		m_dPenalty;
	int		m_GAward;
	int		m_IPenalty;
	//}}AFX_DATA
	int     m_CrossOverMethod;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NGADlg)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(NGADlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NGADLG_H__36C3DE01_73D5_11D2_B9F1_BA8FA8FE6654__INCLUDED_)
