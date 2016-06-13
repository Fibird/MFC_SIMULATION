#include "stdafx.h"
#include "My.h"

extern CMyWinApp theApp;

BOOL CWnd::Create()
{
	cout << "CWnd::Create \n";
	return TRUE;
}

BOOL CWnd::CreateEx()
{
	cout << "CWnd::CreateEx \n";
	PreCreateWindow();
	return TRUE;
}

BOOL CWnd::PreCreateWindow()
{
	cout << "CWnd::PreCreateWindow \n";
	return 0;
}

BOOL CFrameWnd::Create()
{
	cout << "CFrameWnd::Create \n";
	CreateEx();	//This is a virtual function, and CFrameWnd didn't override it
				//so it triggers CWnd::CreateEx()
	return TRUE;
}

BOOL CFrameWnd::PreCreateWindow()
{
	cout << "CFrameWnd::PreCreateWindow \n";
	return FALSE;
}

CWinApp *AfxGetApp()
{
	return theApp.m_pCurrentWinApp;
}
