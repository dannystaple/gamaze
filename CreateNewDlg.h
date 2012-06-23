#if !defined(AFX_CREATENEWDLG_H__E9D2EF63_7CAC_11D2_B9F1_D3E1FE94F155__INCLUDED_)
#define AFX_CREATENEWDLG_H__E9D2EF63_7CAC_11D2_B9F1_D3E1FE94F155__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CreateNewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCreateNewDlg dialog

class CCreateNewDlg : public CDialog
{
// Construction
public:
	CCreateNewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateNewDlg)
	enum { IDD = IDD_NEWDIALOG };
	CString	m_FileName;
	//}}AFX_DATA
	int m_DocType;
	/*An integer specifying the type of document being creaed 
	in this initialiser.*/


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateNewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCreateNewDlg)
	afx_msg void OnButton1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATENEWDLG_H__E9D2EF63_7CAC_11D2_B9F1_D3E1FE94F155__INCLUDED_)
