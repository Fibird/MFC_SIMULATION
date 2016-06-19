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
	DECLARE_MESSAGE_MAP()
};

class CMyFrameWnd :public CFrameWnd
{
public:
	CMyFrameWnd();
	~CMyFrameWnd() { }
	void SayHello() { cout << "Hello CMyFrameWnd \n"; }
	DECLARE_MESSAGE_MAP()
};

class CMyDoc : public CDocument
{
public:
	CMyDoc() {}
	~CMyDoc() {}
	void SayHello() { cout << "Hello CMyDoc \n"; }
	DECLARE_MESSAGE_MAP()
};

class CMyView : public CView
{
public:
	CMyView() {}
	~CMyView() {}
	void SayHello() { cout << "Hello CMyView \n"; }
	DECLARE_MESSAGE_MAP()
};

