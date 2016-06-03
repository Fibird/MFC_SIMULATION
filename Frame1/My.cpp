#include "stdafx.h"
#include "My.h"

CMyWinApp theApp;	//global object

bool CMyWinApp::InitInstance()
{
	cout << "CMyWinApp::InitInstance \n";
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
	return 0;
}

