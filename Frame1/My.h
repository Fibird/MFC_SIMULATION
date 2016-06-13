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
public:
	CMyFrameWnd();
	~CMyFrameWnd() { }
};
