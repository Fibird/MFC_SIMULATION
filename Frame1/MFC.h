#pragma once
#include <iostream>

using namespace std;

class CObject
{
public:
	CObject() { cout << "CObject Constructor \n"; }
	~CObject() { cout << "CObject Destructor \n"; }
};

class CCmdTarget :public CObject
{
public:
	CCmdTarget() { cout << "CCmdTarget Constructor \n"; }
	~CCmdTarget() { cout << "CObject Destructor \n"; }
};

class CWinThread :public CCmdTarget
{
public:
	CWinThread() { cout << "CWinThread Constructor \n"; }
	~CWinThread() { cout << "CWinThread Destructor \n"; }
	virtual bool InitInstance()
	{
		cout << "CWinThread::InitInstance \n";
		return true;
	}
	virtual int Run()
	{
		cout << "CWinThread::Run \n";
		return 1;
	}
};

class CWinApp :public CWinThread
{
public:
	CWinApp* m_pCurrentWinApp;
	CWnd* m_pMainWnd;
public:
	CWinApp() 
	{ 
		m_pCurrentWinApp = this;
	}
	~CWinApp()
	{
		cout << "CWinApp Destructor \n";
	}
	virtual bool InitApplication()
	{
		cout << "CWinApp::InitApplication \n";
		return true;
	}
	virtual bool InitInstance()
	{
		cout << "CWinApp::InitInstance \n";
		return true;
	}
	virtual int Run()
	{
		cout << "CWinApp::Run \n";
		return CWinThread::Run();
	}
};

class CDocument :public CCmdTarget
{
public:
	CDocument() { cout << "CDocument Constructor \n"; }
	~CDocument() { cout << "CDocument Destructor \n"; }
};

class CWnd :public CCmdTarget
{
public:
	CWnd() { cout << "CWnd Constructor \n"; }
	~CWnd() { cout << "CWnd Destructor \n"; }
	virtual bool Create();
	bool CreateEx();
	virtual bool PreCreateWindow();
};

class CFrameWnd :public CWnd
{
public:
	CFrameWnd() { cout << "CFrameWnd Constructor \n"; }
	~CFrameWnd() { cout << "CFrameWnd Destructor \n"; }
	bool Create();
	virtual bool PreCreateWindow();
};

class CView
{
public:
	CView() { cout << "CView Constructor \n"; }
	~CView() { cout << "CView Destructor \n"; }
};

//global function

CWinApp *AfxGetApp();