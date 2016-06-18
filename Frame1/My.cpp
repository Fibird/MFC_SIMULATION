#include "stdafx.h"
#include "My.h"

CMyWinApp theApp;	//global object

BOOL CMyWinApp::InitInstance()
{
	//cout << "CMyWinApp::InitInstance \n";
	m_pMainWnd = new CMyFrameWnd;
	return TRUE;
}

CMyFrameWnd::CMyFrameWnd()
{
	cout << "CMyFrameWnd::CMyFrameWnd \n";
	Create();
}
IMPLEMENT_DYNCREATE(CMyFrameWnd, CFrameWnd)
IMPLEMENT_DYNCREATE(CMyDoc, CDocument)
IMPLEMENT_DYNCREATE(CMyView, CView)
//--------------------------------------------------
//main function
//--------------------------------------------------

int main()
{
	CWinApp *pApp = AfxGetApp();
	pApp->InitApplication();
	pApp->InitInstance();
	pApp->Run();
	//PrintAllClasses();
	CMyDoc* pMyDoc = new CMyDoc;
	CMyView* pMyView = new CMyView;

	//Test Dynamic Creation
	CRuntimeClass* pClassRef;
	CObject* pOb;
	while (1)
	{
		if ((pClassRef = CRuntimeClass::Load()) == NULL)
			break;
		pOb = pClassRef->CreateObject();
		if (pOb != NULL)
			pOb->SayHello();
	}
	return 0;
}

void PrintAllClasses()
{
	CRuntimeClass* pClass;
	// just walk through the simple list of registered classes
	for (pClass = CRuntimeClass::pFirstClass; pClass != NULL; 
		pClass = pClass->m_pNextClass)
	{
		cout << pClass->m_lpszClassName << "\n";
		cout << pClass->m_nObjectSize << "\n";
		cout << pClass->m_wSchema << "\n";
	}
}
