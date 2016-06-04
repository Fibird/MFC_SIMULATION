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
	/*CWinApp *pApp = AfxGetApp();
	pApp->InitApplication();
	pApp->InitInstance();
	pApp->Run();
	PrintAllClasses();*/
	CMyDoc* pMyDoc = new CMyDoc;
	CMyView* pMyView = new CMyView;
	cout << pMyDoc->IsKindOf(RUNTIME_CLASS(CMyDoc)); // ��ԓ�@�� TRUE
	cout << pMyDoc->IsKindOf(RUNTIME_CLASS(CDocument)); // ��ԓ�@�� TRUE
	cout << pMyDoc->IsKindOf(RUNTIME_CLASS(CCmdTarget)); // ��ԓ�@�� TRUE
	cout << pMyDoc->IsKindOf(RUNTIME_CLASS(CObject)); // ��ԓ�@�� TRUE
	cout << pMyDoc->IsKindOf(RUNTIME_CLASS(CWinApp)); // ��ԓ�@�� FALSE
	cout << pMyDoc->IsKindOf(RUNTIME_CLASS(CView)); // ��ԓ�@�� FALSE
	cout << pMyView->IsKindOf(RUNTIME_CLASS(CView)); // ��ԓ�@�� TRUE
	cout << pMyView->IsKindOf(RUNTIME_CLASS(CObject)); // ��ԓ�@�� TRUE
	cout << pMyView->IsKindOf(RUNTIME_CLASS(CWnd)); // ��ԓ�@�� TRUE
	cout << pMyView->IsKindOf(RUNTIME_CLASS(CFrameWnd)); // Ӧ�û��FALSE
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
