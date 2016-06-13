#include "stdafx.h"
#include "My.h"

CMyWinApp theApp;	//global object

BOOL CMyWinApp::InitInstance()
{
	//modifies the virtual function of base class
	cout << "CMyWinApp::InitInstance \n";
	//Triggers constructor of CMyFrameWnd
	m_pMainWnd = new CMyFrameWnd;
	return TRUE;
}

CMyFrameWnd::CMyFrameWnd()
{
	cout << "CMyFrameWnd::CMyFrameWnd \n";
	//Create() is virtual function, and CMyFrameWnd didn't override it,
	//so it triggers CFrameWnd::Create()
	Create();
}
//--------------------------------------------------
//main function
//--------------------------------------------------

int main()
{
	CWinApp *pApp = AfxGetApp();

	pApp->InitApplication();	//It will call CWinApp::InitApplication
	pApp->InitInstance();	//It will call CMyWinApp::InitInstance
							
	pApp->Run();
	return 0;
}

