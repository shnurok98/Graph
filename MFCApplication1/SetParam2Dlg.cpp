// SetParam2Dlg.cpp: файл реализации
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SetParam2Dlg.h"
#include "afxdialogex.h"


// диалоговое окно CSetParam2Dlg

IMPLEMENT_DYNAMIC(CSetParam2Dlg, CDialogEx)

CSetParam2Dlg::CSetParam2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_dstep(0.001)
	, m_iDlgP1(3)
	, m_iDlgL1(2)
{

}

CSetParam2Dlg::~CSetParam2Dlg()
{
}

void CSetParam2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dstep);
	DDX_Text(pDX, IDC_EDIT2, m_iDlgP1);
	DDX_Text(pDX, IDC_EDIT3, m_iDlgL1);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON2, m_crColorDlg1);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON1, m_crColorDlg2);
}


BEGIN_MESSAGE_MAP(CSetParam2Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSetParam2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CSetParam2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений CSetParam2Dlg


void CSetParam2Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
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


		//AfxMessageBox(fileDialog.GetPathName());  //GetPathName() возвращает имя и адрес выбранного файла
	}
}


void CSetParam2Dlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
	m_crColorDlg1 = ((CMFCColorButton*)GetDlgItem(IDC_MFCCOLORBUTTON1))->GetColor();
	m_crColorDlg2 = ((CMFCColorButton*)GetDlgItem(IDC_MFCCOLORBUTTON2))->GetColor();
}
