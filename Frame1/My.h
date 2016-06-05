#pragma once
#include <iostream>

using namespace std;
#include "MFC.h"

class CMyWinApp :public CWinApp
{
public:
	CMyWinApp() { }
	~CMyWinApp() { }
	virtual bool InitInstance();
};

class CMyFrameWnd :public CFrameWnd
{
	//DECLARE_DYNAMIC(CMyFrameWnd) // 在MFC 程序中这里其实是DECLARE_DYNCREATE()
	DECLARE_DYNCREATE(CMyFrameWnd)
public:
	CMyFrameWnd();
	~CMyFrameWnd() { }
	void SayHello() { cout << "Hello CMyFrameWnd \n"; }
};

class CMyDoc : public CDocument
{
	//DECLARE_DYNAMIC(CMyDoc)
	DECLARE_DYNCREATE(CMyDoc)
public:
	CMyDoc() {}
	~CMyDoc() {}
	void SayHello() { cout << "Hello CMyDoc \n"; }
};

class CMyView :public CView
{
	//DECLARE_DYNAMIC(CMyView)
	DECLARE_DYNCREATE(CMyView)
public:
	CMyView() {}
	~CMyView() {}
	void SayHello() { cout << "Hello CMyView \n"; }
};

// global function
void PrintAllClasses();
