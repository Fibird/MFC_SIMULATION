#pragma once
#include <iostream>

using namespace std;
#include "MFC.h"

class CMyWinApp :public CWinApp
{
public:
	CMyWinApp() { cout << "CMyWinApp Constructor \n"; }
	~CMyWinApp() { cout << "CMyWinApp Destructor \n"; }
	virtual bool InitInstance();
};

class CMyFrameWnd :public CFrameWnd
{
public:
	CMyFrameWnd();
	~CMyFrameWnd() { cout << "CMyFrameWnd Destructor \n"; }
};
