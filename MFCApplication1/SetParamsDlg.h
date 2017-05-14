#pragma once
#include "afxwin.h"


// диалоговое окно CSetParamsDlg

class CSetParamsDlg : public CDialog
{
	DECLARE_DYNAMIC(CSetParamsDlg)

public:
	CSetParamsDlg(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CSetParamsDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedImportbtn();
	double m_dStep;
	CArray<double, double> m_fx;
	CArray<double, double> m_fy;
	//afx_msg void OnLbnSelchangeList2();
	//CListBox m_list;
};
