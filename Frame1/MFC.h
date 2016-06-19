#pragma once

#define BOOL int
#define TRUE 1
#define FALSE 0
#define LPCSTR LPSTR
typedef char* LPSTR;
#define UINT int
#define DWORD unsigned long 
#define BYTE unsigned char
#define WORD unsigned short
#define INT int
#define LONG long
#define PASCAL _stdcall

#define WM_COMMAND		0x0111
#define CObjectid		0xffff
#define CCmdTargetid	1
#define CWinThreadid	11
#define CWinAppid		111
#define CMyWinAppid		1111
#define CWndid			12
#define CFrameWndid		121
#define CMyFrameWndid	1211
#define CViewid			122
#define CMyViewid		1221
#define CDocmentid		13
#define CMyDocid		131

#include <iostream>
/////////////////////////////////
//Window message map handling
struct AFX_MSGMAP_ENTRY;	//declared below after wnd

struct AFX_MSGMAP
{
	AFX_MSGMAP *pBaseMessageMap;
	AFX_MSGMAP_ENTRY *lpEntries;
};

#define DECLARE_MESSAGE_MAP() \
		static AFX_MSGMAP_ENTRY _messageEntries[]; \
		static AFX_MSGMAP messageMap; \
		virtual AFX_MSGMAP* GetMessageMap() const;
#define BEGIN_MESSAGE_MAP(theClass, baseClass) \
		AFX_MSGMAP* theClass::GetMessageMap() const \
			{return &theClass::messageMap;} \
		AFX_MSGMAP theClass::messageMap = \
		{&(baseClass::messageMap), \
		(AFX_MSGMAP_ENTRY*) &(theClass::_messageEntries) }; \
		AFX_MSGMAP_ENTRY theClass::_messageEntries [] = \
		{

#define END_MESSAGE_MAP()  \
		{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }	 \
		};
// Message map signature values and macros in separate header
#include "afxmsg_.h"

class CObject
{
public:
	CObject() { }
	~CObject() { }
};

class CCmdTarget :public CObject
{
	//DECLARE_DYNAMIC(CCmdTarget)	//don't need a ";"!!!
public:
	CCmdTarget() { }
	~CCmdTarget() { }
	DECLARE_MESSAGE_MAP()	// base class - no {{}} macros
};

typedef void (CCmdTarget::*AFX_PMSG)(void);

struct AFX_MSGMAP_ENTRY		//MFC 4.0
{
	UINT nMessage;	// windows message
	UINT nCode;		// controls code or WM_NOTIFY
	UINT nID;		// controls ID (or 0 for windows messages)
	UINT nLastID;	// used for entries specifying a range of control id's
	UINT nSig;		// signature type  (action) or pointer to message
	AFX_PMSG pfn;	// routine to call (or special value)
};

class CWinThread :public CCmdTarget
{
	//DECLARE_DYNAMIC(CWinThread)	//don't need a ";"!!!
public:
	CWinThread() { }
	~CWinThread() { }
	virtual BOOL InitInstance()
	{
		return TRUE;
	}
	virtual int Run()
	{
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
	virtual BOOL InitApplication()
	{
		return TRUE;
	}
	virtual BOOL InitInstance()
	{
		return TRUE;
	}
	virtual int Run()
	{
		return CWinThread::Run();
	}
	DECLARE_MESSAGE_MAP()
};

typedef void (CWnd::*AFX_PMSGW) (void);
		// like 'AFX_PMSG' but for CWnd derived classes only
class CDocument :public CCmdTarget
{
	//DECLARE_DYNAMIC(CDocument) //don't need a ";"!!!
public:
	CDocument() { }
	~CDocument() { }
	DECLARE_MESSAGE_MAP()
};

class CWnd :public CCmdTarget
{
	//DECLARE_DYNAMIC(CWnd) //don't need a ";"!!!
	//DECLARE_DYNCREATE(CWnd)
public:
	CWnd() { }
	~CWnd() { }
	virtual BOOL Create();
	BOOL CreateEx();
	virtual BOOL PreCreateWindow();
	void SayHello() { cout << "Hello CWnd \n"; }
	DECLARE_MESSAGE_MAP()
};

class CFrameWnd :public CWnd
{
	//DECLARE_DYNAMIC(CFrameWnd)	//don't need a ";"!!!
	//DECLARE_DYNCREATE(CFrameWnd)
public:
	CFrameWnd() { }
	~CFrameWnd() { }
	BOOL Create();
	virtual BOOL PreCreateWindow();
	void SayHello() { cout << "Hello CFrameWnd \n"; }
	DECLARE_MESSAGE_MAP()
};

class CView : public CWnd
{
	//DECLARE_DYNAMIC(CView) //don't need a ";"!!!
public:
	CView() { }
	~CView() { }
	DECLARE_MESSAGE_MAP()
};

//global function
CWinApp *AfxGetApp();