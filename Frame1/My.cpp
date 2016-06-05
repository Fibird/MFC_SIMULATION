#include "stdafx.h"
#include "My.h"

CMyWinApp theApp;	//global object

bool CMyWinApp::InitInstance()
{
	//cout << "CMyWinApp::InitInstance \n";
	m_pMainWnd = new CMyFrameWnd;
	return true;
}

CMyFrameWnd::CMyFrameWnd()
{
	cout << "CMyFrameWnd::CMyFrameWnd \n";
	Create();
}
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

	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CMyDoc))\t" << pMyDoc->IsKindOf(RUNTIME_CLASS(CMyDoc)) << endl; //It should be TRUE
	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CDocument))\t" << pMyDoc->IsKindOf(RUNTIME_CLASS(CDocument)) << endl; // It should be TRUE
	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CCmdTarget))\t" << pMyDoc->IsKindOf(RUNTIME_CLASS(CCmdTarget)) << endl; // It should be TRUE
	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CObject))\t" << pMyDoc->IsKindOf(RUNTIME_CLASS(CObject)) << endl; // It should be TRUE
	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CWinApp))\t" << pMyDoc->IsKindOf(RUNTIME_CLASS(CWinApp)) << endl; // It should be FALSE
	cout << "pMyDoc->IsKindOf(RUNTIME_CLASS(CView))\t" << pMyDoc->IsKindOf(RUNTIME_CLASS(CView)) << endl; // It should be FALSE
	cout << "pMyView->IsKindOf(RUNTIME_CLASS(CView))\t" << pMyView->IsKindOf(RUNTIME_CLASS(CView)) << endl; // It should be TRUE
	cout << "pMyView->IsKindOf(RUNTIME_CLASS(CObject))\t" << pMyView->IsKindOf(RUNTIME_CLASS(CObject)) << endl; // It should be TRUE
	cout << "pMyView->IsKindOf(RUNTIME_CLASS(CWnd))\t" << pMyView->IsKindOf(RUNTIME_CLASS(CWnd)) << endl; // It should be TRUE
	cout << "pMyView->IsKindOf(RUNTIME_CLASS(CFrameWnd))\t" << pMyView->IsKindOf(RUNTIME_CLASS(CFrameWnd)) << endl; // It should be FALSE
	
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
