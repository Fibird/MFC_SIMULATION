#include "stdafx.h"
#include "My.h"

extern CMyWinApp theApp;

static char szCObject[] = "CObject";
struct CRuntimeClass CObject::classCObject =
{ szCObject, sizeof(CObject), 0xffff, NULL, NULL };
static AFX_CLASSINIT _init_CObject(&CObject::classCObject);

CRuntimeClass* CRuntimeClass::pFirstClass = NULL;

AFX_CLASSINIT::AFX_CLASSINIT(CRuntimeClass* pNewClass)
{
	pNewClass->m_pNextClass = CRuntimeClass::pFirstClass;
	CRuntimeClass::pFirstClass = pNewClass;
}

CRuntimeClass* CObject::GetRuntimeClass() const
{
	return &CObject::classCObject;
}

bool CObject::IsKindOf(const CRuntimeClass * pClass) const
{
	CRuntimeClass* pClassThis = GetRuntimeClass();
	while (pClassThis != NULL)
	{
		if (pClassThis == pClass)
			return true;
		pClassThis = pClassThis->m_pBaseClass;
	}
	return false;		//walk to the top, no match
}

bool CWnd::Create()
{
	//cout << "CWnd::Create \n";
	return true;
}

bool CWnd::CreateEx()
{
	//cout << "CWnd::CreateEx \n";
	return true;
}

bool CWnd::PreCreateWindow()
{
	//cout << "CWnd::PreCreateWindow \n";
	return 0;
}

bool CFrameWnd::Create()
{
	//cout << "CFrameWnd::Create \n";
	CreateEx();
	return true;
}

bool CFrameWnd::PreCreateWindow()
{
	//cout << "CFrameWnd::PreCreateWindow \n";
	return false;
}

IMPLEMEN_DYNAMIC(CCmdTarget, CObject)
IMPLEMEN_DYNAMIC(CWinThread, CCmdTarget)
IMPLEMEN_DYNAMIC(CWinApp, CWinThread)
IMPLEMEN_DYNAMIC(CWnd, CCmdTarget)
IMPLEMEN_DYNAMIC(CFrameWnd, CWnd)
IMPLEMEN_DYNAMIC(CDocument, CCmdTarget)
IMPLEMEN_DYNAMIC(CView, CWnd)
IMPLEMEN_DYNAMIC(CMyFrameWnd, CFrameWnd)
IMPLEMEN_DYNAMIC(CMyDoc, CDocument)
IMPLEMEN_DYNAMIC(CMyView, CView)

//global function
CWinApp *AfxGetApp()
{
	return theApp.m_pCurrentWinApp;
}

/*AFX_CLASSINIT::AFX_CLASSINIT(CRuntimeClass * pNewClass)
{
	pNewClass->m_pNextClass = CRuntimeClass::pFirstClass;
	CRuntimeClass::pFirstClass = pNewClass;
}

CRuntimeClass * CObject::GetRuntimeClass() const
{
	return &CObject::classCObject;
}*/
