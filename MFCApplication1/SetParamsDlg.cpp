// SetParamsDlg.cpp: ���� ����������
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SetParamsDlg.h"
#include "afxdialogex.h"
#include "afxtempl.h"
#include "stdio.h"


// ���������� ���� CSetParamsDlg

IMPLEMENT_DYNAMIC(CSetParamsDlg, CDialog)

CSetParamsDlg::CSetParamsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	
	, m_iDlgP1(3)
	, m_iDlgL1(2)
{

}

CSetParamsDlg::~CSetParamsDlg()
{
}

void CSetParamsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDITSTEP, m_dStep);
	//  DDV_MinMaxDouble(pDX, m_dStep, 0.1000, DBL_MAX);
	//DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON1, m_crColorDlg1);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON2, m_crColorDlg2);
	DDX_Text(pDX, IDC_EDITT2, m_iDlgP1);
	DDX_Text(pDX, IDC_EDITT, m_iDlgL1);
}


BEGIN_MESSAGE_MAP(CSetParamsDlg, CDialog)
	ON_BN_CLICKED(IDC_IMPORTBTN, &CSetParamsDlg::OnBnClickedImportbtn)

	//ON_LBN_SELCHANGE(IDC_LIST2, &CSetParamsDlg::OnLbnSelchangeList2)
	ON_BN_CLICKED(IDOK, &CSetParamsDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ����������� ��������� CSetParamsDlg


void CSetParamsDlg::OnBnClickedImportbtn()
{
	UpdateData(TRUE);
	// TODO: �������� ���� ��� ����������� �����������
	/*������ �������� �����*/
	CFileDialog fileDialog(TRUE);	//�������� ������������ ��������� �� ��� ������� (save/open)
	if (fileDialog.DoModal() == IDOK)
	{
		FILE *fl;
		_tfopen_s(&fl, fileDialog.GetPathName(), _T("rt"));//_t cstring unicode
		if (!fl) {
			//exit(1);
			AfxMessageBox(_T("���� �� ������"));
		}
		char str[100];
		double x, y;//double float
		//CArray<double, double> m_fx;
		//CArray<double, double> m_fy;
		/*if (fgets(str, 100, fl) == NULL) {
			AfxMessageBox(_T("���� ����"));
		}*/
		while (fgets(str, 100, fl) != NULL) {
			if (sscanf_s(str, "%lf %lf", &x, &y) == 2) {
				m_fx.Add(x*20);
				m_fy.Add(y*20);
			}
			else {
				AfxMessageBox(_T("������ ������ �����"));
				return;
			}
		}
		
		
		//AfxMessageBox(fileDialog.GetPathName());  //GetPathName() ���������� ��� � ����� ���������� �����
	}
}




/*
void CSetParamsDlg::OnLbnSelchangeList2()
{
	// TODO: �������� ���� ��� ����������� �����������
}
*/

void CSetParamsDlg::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	CDialog::OnOK();
	m_crColorDlg1 = ((CMFCColorButton*)GetDlgItem(IDC_MFCCOLORBUTTON1))->GetColor();
	m_crColorDlg2 = ((CMFCColorButton*)GetDlgItem(IDC_MFCCOLORBUTTON2))->GetColor();
}
