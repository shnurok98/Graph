#pragma once
#include "afxwin.h"


// ���������� ���� CSetParamsDlg

class CSetParamsDlg : public CDialog
{
	DECLARE_DYNAMIC(CSetParamsDlg)

public:
	CSetParamsDlg(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CSetParamsDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedImportbtn();
//	double m_dStep;
	CArray<double, double> m_fx;
	CArray<double, double> m_fy;
	//afx_msg void OnLbnSelchangeList2();
	//CListBox m_list;
	COLORREF m_crColorDlg1;
	COLORREF m_crColorDlg2;
	int m_iDlgP1;
	int m_iDlgL1;
	afx_msg void OnBnClickedOk();
};
