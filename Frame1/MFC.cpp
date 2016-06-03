#include "stdafx.h"
#include "My.h"

extern CMyWinApp theApp;
CWinApp * AfxGetApp()
{
	return theApp.m_pCurrentWinApp;
}
