#include "stdafx.h"
#include "My.h"

extern CMyWinApp theApp;

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

//global function
CWinApp *AfxGetApp()
{
	return theApp.m_pCurrentWinApp;
}

AFX_MSGMAP* CCmdTarget::GetMessageMap() const
{
	return &CCmdTarget::messageMap;
}
AFX_MSGMAP CCmdTarget::messageMap =
{
	NULL,
	&CCmdTarget::_messageEntries[0]
};

AFX_MSGMAP_ENTRY CCmdTarget::_messageEntries[] = 
{
	// { 0, 0, 0, 0, AfxSig_end, 0 }	// nothing here
	{ 0, 0, CCmdTargetid, 0, AfxSig_end, 0 }
};

BEGIN_MESSAGE_MAP(CWnd, CCmdTarget)
	ON_COMMAND(CWndid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CFrameWnd, CWnd)
	ON_COMMAND(CFrameWndid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CDocument, CCmdTarget)
	ON_COMMAND(CDocmentid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CView, CWnd)
	ON_COMMAND(CViewid, 0)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CWinApp, CCmdTarget)
	ON_COMMAND(CWinAppid, 0)
END_MESSAGE_MAP()

