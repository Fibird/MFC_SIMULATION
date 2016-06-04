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
public:
	CMyFrameWnd();
	~CMyFrameWnd() { }
};

class CMydoc : public CDocument
{
public:
	CMydoc::CMydoc() {}
	CMydoc::~CMydoc() {}
};

class CMyView :public CView
{
public:
	CMyView::CMyView() {}
	CMyView::~CMyView() {}
};

// global function
void PrintAllClasses();
