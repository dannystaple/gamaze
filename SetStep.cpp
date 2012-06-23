// SetStep.cpp : implementation file
//

#include "stdafx.h"
#include "gamaze.h"
#include "SetStep.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetStep dialog


CSetStep::CSetStep(CWnd* pParent /*=NULL*/)
	: CDialog(CSetStep::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetStep)
	m_Value = 0;
	//}}AFX_DATA_INIT
}


void CSetStep::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetStep)
	DDX_Text(pDX, IDC_EDIT1, m_Value);
	DDV_MinMaxInt(pDX, m_Value, 10, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetStep, CDialog)
	//{{AFX_MSG_MAP(CSetStep)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetStep message handlers
