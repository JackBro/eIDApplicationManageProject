// HedCSP_PCSC.h : HedCSP_PCSC DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHedCSP_PCSCApp
// �йش���ʵ�ֵ���Ϣ������� HedCSP_PCSC.cpp
//

class CHedCSP_PCSCApp : public CWinApp
{
public:
	CHedCSP_PCSCApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
