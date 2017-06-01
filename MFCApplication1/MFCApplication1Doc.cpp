
// MFCApplication1Doc.cpp : реализация класса CMFCApplication1Doc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MainFrm.h"
#include "MFCApplication1View.h"
#include "MFCApplication1Doc.h"
#include "SetParamsDlg.h"
#include "SetParam2Dlg.h"
#include "afxtempl.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication1Doc

IMPLEMENT_DYNCREATE(CMFCApplication1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication1Doc, CDocument)
	ON_COMMAND(ID_SETPAR, &CMFCApplication1Doc::OnSetpar)
	ON_COMMAND(ID_32773, &CMFCApplication1Doc::OnSetParam2)
END_MESSAGE_MAP()


// создание/уничтожение CMFCApplication1Doc

CMFCApplication1Doc::CMFCApplication1Doc()
{
	// TODO: добавьте код для одноразового вызова конструктора
	m_dDocStep = 0.001;
	//m_cPointX.RemoveAll();
	//m_cPointY.RemoveAll();
}

CMFCApplication1Doc::~CMFCApplication1Doc()
{
}

BOOL CMFCApplication1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)
	srand(time(0));
	for (int i = 0; i < m_iNum; i++) {
		m_dX[i] = i;
		//ctime(0);
		m_dY[i] = rand() % 99;
	}
	
	return TRUE;
}




// сериализация CMFCApplication1Doc

void CMFCApplication1Doc::Serialize(CArchive& ar)
{
	
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
		ar << m_iNum;
		for (int i = 0; i < m_iNum; i++) {
			ar << m_dX[i];
			ar << m_dY[i];
		}
	}
	else
	{
		// TODO: добавьте код загрузки
		//ar >> ver;
		//if(ver==1){
		//}
		ar >> m_iNum;
		for (int i = 0; i < m_iNum; i++) {
			ar >> m_dX[i];
			ar >> m_dY[i];
		}
	}
	
	
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CMFCApplication1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CMFCApplication1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CMFCApplication1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// диагностика CMFCApplication1Doc

#ifdef _DEBUG
void CMFCApplication1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды CMFCApplication1Doc


void CMFCApplication1Doc::OnSetpar()
{
	// TODO: добавьте свой код обработчика команд
	CMFCApplication1View *pV1;
	pV1 = (CMFCApplication1View*)((CMainFrame*)AfxGetMainWnd())->GetActiveView();
	CSetParamsDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_cPointX.RemoveAll();
		m_cPointY.RemoveAll();
		m_cPointX.Append(dlg.m_fx);
		m_cPointY.Append(dlg.m_fy);
		m_crColorDlg1 = dlg.m_crColorDlg1;
		m_crColorDlg2 = dlg.m_crColorDlg2;
		m_iDlgP = dlg.m_iDlgP1;
		m_iDlgL = dlg.m_iDlgL1;
		nDlg = 1;
		if (m_cPointX.GetSize()>0)
		action();
	}
	pV1->Invalidate(TRUE);
	m_cPointX.GetAt(1);
}

void CMFCApplication1Doc::action()
{
	if (nDlg == 1) {
		m_cPointXi.RemoveAll();
		m_cPointYi.RemoveAll();
		for (int i = m_cPointX[0]; i <= m_cPointX[m_cPointX.GetSize() - 1]; i++)
		{
			m_cPointYi.Add(polinom(i));
			m_cPointXi.Add(i);
		}
	}
	else {
		m_cPointXi.RemoveAll();
		m_cPointYi.RemoveAll();
		double maxx, maxy, minx, miny;
		maxx = m_cPointX.GetAt(0);
		for (int i = 1; i < m_cPointX.GetSize(); i++)
		{
			if (maxx<m_cPointX.GetAt(i))
				maxx = m_cPointX.GetAt(i);
		}
		maxy = m_cPointY.GetAt(0);
		for (int i = 1; i < m_cPointY.GetSize(); i++)
		{
			if (maxy<m_cPointY.GetAt(i))
				maxy = m_cPointY.GetAt(i);
		}

		minx = m_cPointX.GetAt(0);
		for (int i = 1; i < m_cPointX.GetSize(); i++)
		{
			if (minx>m_cPointX.GetAt(i))
				minx = m_cPointX.GetAt(i);
		}
		miny = m_cPointY.GetAt(0);
		for (int i = 1; i < m_cPointX.GetSize(); i++)
		{
			if (miny>m_cPointY.GetAt(i))
				miny = m_cPointY.GetAt(i);
		}

		double x0, y0, R, SumD, SumF;
	

		x0 = (maxx + minx) / 2;
		y0 = (maxy + miny) / 2;



		R = 0;
		X = minx;
		Y = miny;
		SumD = m_dDocStep*m_dDocStep*m_cPointX.GetSize();
		do
		{
			R += m_dDocStep;
			SumF = 0;
			for (int i = 0; i < m_iNum; i++)
			{
				SumF += ((m_cPointX[i] - x0)*(m_cPointX[i] - x0) + (m_cPointY[i] - y0)*(m_cPointY[i] - y0) - R*R);
			}


		} while (SumF > SumD);
		int d1=0;
		do
		{
			d1++;
			X += m_dDocStep;
			SumF = 0;
			for (int i = 0; i < m_cPointX.GetSize(); i++)
			{
				SumF += ((m_cPointX[i] - X)*(m_cPointX[i] - X) + (m_cPointY[i] - y0)*(m_cPointY[i] - y0) - R*R);
			}
			if (d1 > 2000000 * m_dDocStep)
				break;

		} while (SumF > SumD);
		d1 = 0;
		do
		{
			d1++;
			Y += m_dDocStep;
			SumF = 0;
			for (int i = 0; i < m_cPointX.GetSize(); i++)
			{
				SumF += ((m_cPointX[i] - X)*(m_cPointX[i] - X) + (m_cPointY[i] - Y)*(m_cPointY[i] - Y) - R*R);
			}
			if (d1 > 2000000 * m_dDocStep)
				break;

		} while (SumF > SumD);

		double xf, yf;
		double PI = 3.14;
		for (double i = 0; i <= 360; i += 5)
		{
			xf = R*cos(i * PI / 180) + X;
			yf = R*sin(i * PI / 180) + Y;

			m_cPointXi.Add(xf);
			m_cPointYi.Add(yf);
		}


	}
}

double CMFCApplication1Doc::polinom(double x)
{
	CArray<double, double> m_fCl;
	double l = 1, L = 0;

	for (int i = 0; i < m_cPointX.GetSize(); i++)
	{
		for (int j = 0; j < m_cPointX.GetSize(); j++)
		{
			if (i != j)
			{
				l *= (x - m_cPointX[j]) / (m_cPointX[i] - m_cPointX[j]);
			}
		}
		m_fCl.Add(l);
		l = 1;
	}

	for (int i = 0; i < m_cPointX.GetSize(); i++)
	{
		L += m_cPointY[i] * m_fCl[i];
	}
	return L;
}


void CMFCApplication1Doc::OnSetParam2()
{
	// TODO: добавьте свой код обработчика команд
	CMFCApplication1View *pV;
	pV = (CMFCApplication1View*)((CMainFrame*)AfxGetMainWnd())->GetActiveView();
	CSetParam2Dlg dlg;
	dlg.m_dstep = m_dDocStep;
	if (dlg.DoModal() == IDOK) {
		m_cPointX.RemoveAll();
		m_cPointY.RemoveAll();
		m_cPointX.Append(dlg.m_fx);
		m_cPointY.Append(dlg.m_fy);
		m_dDocStep = dlg.m_dstep;
		nDlg = 2;
		m_crColorDlg1 = dlg.m_crColorDlg1;
		m_crColorDlg2 = dlg.m_crColorDlg2;
		m_iDlgP = dlg.m_iDlgP1;
		m_iDlgL = dlg.m_iDlgL1;
		if (m_cPointX.GetSize()>0)
			action();
		pV->Invalidate(TRUE);
	}
}
