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
//IMPLEMEN_DYNAMIC(CWnd, CCmdTarget)
IMPLEMENT_DYNCREATE(CWnd, CCmdTarget)
//IMPLEMEN_DYNAMIC(CFrameWnd, CWnd)
IMPLEMEN_DYNAMIC(CDocument, CCmdTarget)
IMPLEMEN_DYNAMIC(CView, CWnd)
//IMPLEMEN_DYNAMIC(CMyFrameWnd, CFrameWnd)
//IMPLEMEN_DYNAMIC(CMyDoc, CDocument)
//IMPLEMEN_DYNAMIC(CMyView, CView)
IMPLEMENT_DYNCREATE(CFrameWnd, CWnd)

//global function
CWinApp *AfxGetApp()
{
	return theApp.m_pCurrentWinApp;
}

CObject* CRuntimeClass::CreateObject()
{
	if (m_pfnCreateObject == NULL)
	{
		printf("Error: Trying to create object which is not "
			"DECLARE_DYNCREATE \nor DECLARE_SERIAL: %hs.\n",
			m_lpszClassName);
		return NULL;
	}
	CObject* pObject = NULL;
	pObject = (*m_pfnCreateObject)();
	return pObject;
}

CRuntimeClass* PASCAL CRuntimeClass::Load()
{
	char szClassName[64];
	CRuntimeClass* pClass;
	// JJHOU : instead of Load from file, we Load from cin.
	cout << "enter a class name... ";
	cin >> szClassName;
	for (pClass = pFirstClass; pClass != NULL; pClass = pClass->m_pNextClass)
	{
		if (strcmp(szClassName, pClass->m_lpszClassName) == 0)
			return pClass;
	}
	printf("Error: Class not found: %s \n", szClassName);
	return NULL; // not found
}
