#pragma once


// диалоговое окно CSetParam2Dlg

class CSetParam2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetParam2Dlg)

public:
	CSetParam2Dlg(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CSetParam2Dlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CArray<double, double> m_fx;
	CArray<double, double> m_fy;
	double m_dstep;
	int m_iDlgP1;
	int m_iDlgL1;
	COLORREF m_crColorDlg1;
	COLORREF m_crColorDlg2;
	afx_msg void OnBnClickedOk();
};
