#pragma once


// диалоговое окно CSetParamsDlg2

class CSetParamsDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CSetParamsDlg2)

public:
	CSetParamsDlg2(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CSetParamsDlg2();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
