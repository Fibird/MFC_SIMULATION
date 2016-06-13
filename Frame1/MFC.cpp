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

BOOL CObject::IsKindOf(const CRuntimeClass * pClass) const
{
	CRuntimeClass* pClassThis = GetRuntimeClass();
	while (pClassThis != NULL)
	{
		if (pClassThis == pClass)
			return TRUE;
		pClassThis = pClassThis->m_pBaseClass;
	}
	return FALSE;		//walk to the top, no match
}

BOOL CWnd::Create()
{
	//cout << "CWnd::Create \n";
	return TRUE;
}

BOOL CWnd::CreateEx()
{
	//cout << "CWnd::CreateEx \n";
	return TRUE;
}

BOOL CWnd::PreCreateWindow()
{
	//cout << "CWnd::PreCreateWindow \n";
	return 0;
}

BOOL CFrameWnd::Create()
{
	//cout << "CFrameWnd::Create \n";
	CreateEx();
	return TRUE;
}

BOOL CFrameWnd::PreCreateWindow()
{
	//cout << "CFrameWnd::PreCreateWindow \n";
	return FALSE;
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

