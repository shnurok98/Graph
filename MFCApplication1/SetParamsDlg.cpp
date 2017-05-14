// SetParamsDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SetParamsDlg.h"
#include "afxdialogex.h"
#include "afxtempl.h"
#include "stdio.h"


// диалоговое окно CSetParamsDlg

IMPLEMENT_DYNAMIC(CSetParamsDlg, CDialog)

CSetParamsDlg::CSetParamsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_dStep(0)
{

}

CSetParamsDlg::~CSetParamsDlg()
{
}

void CSetParamsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITSTEP, m_dStep);
	DDV_MinMaxDouble(pDX, m_dStep, 0.1000, DBL_MAX);
	//DDX_Control(pDX, IDC_LIST2, m_list);
}


BEGIN_MESSAGE_MAP(CSetParamsDlg, CDialog)
	ON_BN_CLICKED(IDC_IMPORTBTN, &CSetParamsDlg::OnBnClickedImportbtn)

	//ON_LBN_SELCHANGE(IDC_LIST2, &CSetParamsDlg::OnLbnSelchangeList2)
END_MESSAGE_MAP()


// обработчики сообщений CSetParamsDlg


void CSetParamsDlg::OnBnClickedImportbtn()
{
	//UpdateData();
	// TODO: добавьте свой код обработчика уведомлений
	/*Диалог открытия файла*/
	CFileDialog fileDialog(TRUE);	//параметр конструктора указывает на тип диалога (save/open)
	if (fileDialog.DoModal() == IDOK)
	{
		FILE *fl;
		_tfopen_s(&fl, fileDialog.GetPathName(), _T("rt"));//_t cstring unicode
		if (!fl) {
			//exit(1);
			AfxMessageBox(_T("Файл не найден"));
		}
		char str[100];
		double x, y;//double float
		//CArray<double, double> m_fx;
		//CArray<double, double> m_fy;
		/*if (fgets(str, 100, fl) == NULL) {
			AfxMessageBox(_T("Файл пуст"));
		}*/
		while (fgets(str, 100, fl) != NULL) {
			if (sscanf_s(str, "%lf %lf", &x, &y) == 2) {
				m_fx.Add(x);
				m_fy.Add(y);
			}
			else {
				AfxMessageBox(_T("Ошибка чтения файла"));
				return;
			}
		}
		
		int g = m_fx.GetSize();
		CString A;
		A.Format(L"%i", g);
		MessageBox(A);
		
		
		//AfxMessageBox(fileDialog.GetPathName());  //GetPathName() возвращает имя и адрес выбранного файла
	}
}




/*
void CSetParamsDlg::OnLbnSelchangeList2()
{
	// TODO: добавьте свой код обработчика уведомлений
}
*/