// GaMType.cpp : implementation file
//

#include "stdafx.h"
#include "gamaze.h"
#include "GaMType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGaMType

IMPLEMENT_DYNCREATE(CGaMType, CDocument)

CGaMType::CGaMType()
{
	EnableAutomation();
}

BOOL CGaMType::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CGaMType::~CGaMType()
{
}

void CGaMType::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDocument::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CGaMType, CDocument)
	//{{AFX_MSG_MAP(CGaMType)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CGaMType, CDocument)
	//{{AFX_DISPATCH_MAP(CGaMType)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IGaMType to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {EE35EB81-7963-11D2-B9F1-952F5521C956}
static const IID IID_IGaMType =
{ 0xee35eb81, 0x7963, 0x11d2, { 0xb9, 0xf1, 0x95, 0x2f, 0x55, 0x21, 0xc9, 0x56 } };

BEGIN_INTERFACE_MAP(CGaMType, CDocument)
	INTERFACE_PART(CGaMType, IID_IGaMType, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGaMType diagnostics

#ifdef _DEBUG
void CGaMType::AssertValid() const
{
	CDocument::AssertValid();
}

void CGaMType::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGaMType serialization

void CGaMType::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGaMType commands
