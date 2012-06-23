// NGADlg.cpp : implementation file
//

#include "stdafx.h"
#include "gamaze.h"
#include "NGADlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NGADlg dialog


NGADlg::NGADlg(CWnd* pParent /*=NULL*/)
	: CDialog(NGADlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(NGADlg)
	m_Population = 0;
	m_Mutate = 0;
	m_CrossOverMethod = 0;
	m_DAward = 0;
	m_dPenalty = 0;
	m_GAward = 0;
	m_IPenalty = 0;
	//}}AFX_DATA_INIT
}


void NGADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(NGADlg)
	DDX_Text(pDX, IDC_NPOP, m_Population);
	DDV_MinMaxInt(pDX, m_Population, 50, 10000);
	DDX_Text(pDX, IDC_MUTATE, m_Mutate);
	DDV_MinMaxInt(pDX, m_Mutate, 50, 300);
	DDX_Text(pDX, IDC_DAW, m_DAward);
	DDX_Text(pDX, IDC_DPEN, m_dPenalty);
	DDX_Text(pDX, IDC_GOAL, m_GAward);
	DDX_Text(pDX, IDC_IDIR, m_IPenalty);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(NGADlg, CDialog)
	//{{AFX_MSG_MAP(NGADlg)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NGADlg message handlers

int NGADlg::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

void NGADlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void NGADlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}


void NGADlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_CrossOverMethod=0;
	
}

void NGADlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_CrossOverMethod=1;
}

void NGADlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	m_CrossOverMethod=2;
}

void NGADlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	m_CrossOverMethod=3;
}
