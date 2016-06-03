#include "stdafx.h"
#include "My.h"

extern CMyWinApp theApp;

bool CWnd::Create()
{
	cout << "CWnd::Create \n";
	return true;
}

bool CWnd::CreateEx()
{
	cout << "CWnd::CreateEx \n";
	return true;
}

bool CWnd::PreCreateWindow()
{
	cout << "CWnd::PreCreateWindow \n";
	return 0;
}

bool CFrameWnd::Create()
{
	cout << "CFrameWnd::Create \n";
	CreateEx();
	return true;
}

bool CFrameWnd::PreCreateWindow()
{
	cout << "CFrameWnd::PreCreateWindow \n";
	return false;
}

CWinApp *AfxGetApp()
{
	return theApp.m_pCurrentWinApp;
}
