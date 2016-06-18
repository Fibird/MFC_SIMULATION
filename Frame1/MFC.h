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
#define CMWinAppid		1111
#define CWndid			12
#define CFrameWndid		121
#define CMyFrameWndid	1211
#define CViewid			122
#define CMyViewid		1221
#define CDocmentid		13
#define CMydocid		131

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

class CObject;

struct CRuntimeClass
{
	//Attributes
	LPCSTR m_lpszClassName;
	int m_nObjectSize;
	UINT m_wSchema;	//schema number of the loaded class
	CObject* (PASCAL* m_pfnCreateObject) ();	//NULL=>abstract class
	CRuntimeClass* m_pBaseClass;
	CObject* CreateObject();
	static CRuntimeClass* PASCAL Load();

	//CRuntimeClass objects linked together in simple list
	static CRuntimeClass* pFirstClass;	//start of class list
	CRuntimeClass* m_pNextClass;	//linked list of registered classes
};

struct AFX_CLASSINIT
{
	AFX_CLASSINIT(CRuntimeClass* pNewClass);
};

#define RUNTIME_CLASS(class_name) \
	(&class_name::class##class_name)

#define DECLARE_DYNAMIC(class_name) \
public: \
	static CRuntimeClass class##class_name;\
	virtual CRuntimeClass* GetRuntimeClass() const;

#define DECLARE_DYNCREATE(class_name) \
		DECLARE_DYNAMIC(class_name) \
		static CObject* PASCAL CreateObject();

#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew)	\
	static char _lpsz##class_name[] = #class_name;	\
	CRuntimeClass class_name::class##class_name = { \
		_lpsz##class_name, sizeof(class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL}; \
	static AFX_CLASSINIT _init_##class_name(&class_name::class##class_name); \
	CRuntimeClass* class_name::GetRuntimeClass() const \
	{ return &class_name::class##class_name; }	\

#define IMPLEMEN_DYNAMIC(class_name, base_class_name) \
		_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL)

#define IMPLEMENT_DYNCREATE(class_name, base_class_name) \
		CObject* PASCAL class_name::CreateObject() \
		{ return new class_name; } \
		_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, \
						class_name::CreateObject)

class CObject
{
public:
	CObject() { }
	~CObject() { }
	virtual CRuntimeClass* GetRuntimeClass() const;
	BOOL IsKindOf(const CRuntimeClass* pClass) const;
public:
	static CRuntimeClass classCObject;
	virtual void SayHello() { cout << "Hello CObject \n"; }
};

class CCmdTarget :public CObject
{
	DECLARE_DYNAMIC(CCmdTarget)	//don't need a ";"!!!
public:
	CCmdTarget() { }
	~CCmdTarget() { }
};

class CWinThread :public CCmdTarget
{
	DECLARE_DYNAMIC(CWinThread)	//don't need a ";"!!!
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
	DECLARE_DYNAMIC(CWinApp)
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
};

class CDocument :public CCmdTarget
{
	DECLARE_DYNAMIC(CDocument) //don't need a ";"!!!
public:
	CDocument() { }
	~CDocument() { }
};

class CWnd :public CCmdTarget
{
	//DECLARE_DYNAMIC(CWnd) //don't need a ";"!!!
	DECLARE_DYNCREATE(CWnd)
public:
	CWnd() { }
	~CWnd() { }
	virtual BOOL Create();
	BOOL CreateEx();
	virtual BOOL PreCreateWindow();
	void SayHello() { cout << "Hello CWnd \n"; }
};

class CFrameWnd :public CWnd
{
	//DECLARE_DYNAMIC(CFrameWnd)	//don't need a ";"!!!
	DECLARE_DYNCREATE(CFrameWnd)
public:
	CFrameWnd() { }
	~CFrameWnd() { }
	BOOL Create();
	virtual BOOL PreCreateWindow();
	void SayHello() { cout << "Hello CFrameWnd \n"; }
};

class CView : public CWnd
{
	DECLARE_DYNAMIC(CView) //don't need a ";"!!!
public:
	CView() { }
	~CView() { }
};

//global function

CWinApp *AfxGetApp();