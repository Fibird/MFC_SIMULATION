#pragma once
#include <iostream>

using namespace std;

class CObject
{
public:
	CObject() { }
	~CObject() { }
};

class CCmdTarget :public CObject
{
public:
	CCmdTarget() { }
	~CCmdTarget() { }
};

class CWinThread :public CCmdTarget
{
public:
	CWinThread() { }
	~CWinThread() { }
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

class CWnd;

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
	CDocument() { }
	~CDocument() { }
};

class CWnd :public CCmdTarget
{
public:
	CWnd() { }
	~CWnd() { }
	virtual bool Create();
	bool CreateEx();
	virtual bool PreCreateWindow();
};

class CFrameWnd :public CWnd
{
public:
	CFrameWnd() { }
	~CFrameWnd() { }
	bool Create();
	virtual bool PreCreateWindow();
};

class CView :public CWnd
{
public:
	CView() { }
	~CView() { }
};

//global function

CWinApp *AfxGetApp();