#pragma once
#include <iostream>

using namespace std;
#include "MFC.h"

class CMyWinApp :public CWinApp
{
public:
	CMyWinApp() { }
	~CMyWinApp() { }
	virtual BOOL InitInstance();
};

class CMyFrameWnd :public CFrameWnd
{
	DECLARE_DYNAMIC(CMyFrameWnd) // ��MFC ������������ʵ��DECLARE_DYNCREATE()
public:
	CMyFrameWnd();
	~CMyFrameWnd() { }
};

class CMyDoc : public CDocument
{
	DECLARE_DYNAMIC(CMyDoc)
public:
	CMyDoc() {}
	~CMyDoc() {}
};

class CMyView :public CView
{
	DECLARE_DYNAMIC(CMyView)
public:
	CMyView() {}
	~CMyView() {}
};

// global function
void PrintAllClasses();
