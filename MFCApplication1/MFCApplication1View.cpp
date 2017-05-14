
// MFCApplication1View.cpp : реализация класса CMFCApplication1View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include "SetParamsDlg.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define RED RGB(255, 0 , 0)
#define GRN RGB(0, 255, 0)
#define BLU RGB(0,0,255)
#define BLK RGB(0,0,0)
#define WHT RGB(255,255,255)

// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CMFCApplication1View

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: добавьте код создания
	//констр

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CMFCApplication1View

void CMFCApplication1View::OnSetpar()
{
	// объед 
	CSetParamsDlg dlg;
	//Rpnt = dlg.m_RPNT;
	//dlg.m_RPNT = Rpnt;
	if (dlg.DoModal() == IDOK) {
		//Rpnt = dlg.m_RPNT;
	}
	//m_cPointX.GetAt(1);
}

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	//CMFCApplication1Doc* pDoc = GetDocument();объявлен в конструкторе
	//pDoc->
	//m_pDoc->
	//CMFCApplication1Doc* m_pDoc = GetDocument();
	m_pDoc = GetDocument();
	ASSERT_VALID(m_pDoc);
	if (!m_pDoc)
		return;
	/*
	RECT pRECT = { 0 };
	GetClientRect(&pRECT);//вызывается при изменении размеров окна
	//pRECT.top
	
	HPEN RPEN = CreatePen(PS_SOLID, 2, RED);
	HPEN GPEN = CreatePen(PS_SOLID, 2, GRN);
	
	SelectObject(*pDC, RPEN);
	pDC->LineTo(100, 100);
	pDC->MoveTo(200, 200);
	SelectObject(*pDC, GPEN);
	pDC->LineTo(300, 300);
	*/
	HPEN    RedPEN = CreatePen(PS_SOLID, 2, RED);
	HPEN    GreenPEN = CreatePen(PS_SOLID, 2, GRN);
	HPEN    BluePEN = CreatePen(PS_SOLID, 2, BLU);
	HPEN    WhitePEN = CreatePen(PS_SOLID, 3, WHT);
	HPEN	BlackPEN = CreatePen(PS_SOLID, 2, BLK);

	RECT    pRECT = { 0 };
	FCOORD   end = { 0 };
	double OX;
	int NumPoints = 100;
	FCOORD CENTER = { 0 };
	
	//CSetParamsDlg dlg;
	//OnSetpar();
	
	GetClientRect(&pRECT);
	//SelectObject(*pDC, BluePEN);
	/*
	if (dlg.m_fx.GetSize() != NULL) {
		m_cX.Copy(dlg.m_fx);
	}
	if (m_cX.GetSize() != NULL) {
		AfxMessageBox(_T("массив не пуст"));
		CString A;
		//A.Format(L"%6.3f", dlg.m_fx.GetAt(0));
		//MessageBox(A);

	}*/
	/*
	int * Ar = new int[NumPoints];
	for (int i = 0; i < NumPoints; i++) {
		Ar[i] = rand() % pRECT.bottom;
		
	}
	*/
	//коорд пл
	pDC->SelectObject(BlackPEN);
	CENTER.X = pRECT.right / 2;
	CENTER.Y = pRECT.bottom / 2;
	pDC->MoveTo(0, CENTER.Y);
	pDC->LineTo(pRECT.right, CENTER.Y);
	pDC->MoveTo(CENTER.X, 0);
	pDC->LineTo(CENTER.X, pRECT.bottom);

	if (m_pDoc->m_cPointX.GetCount() > 0) {
		FCOORD pt, scpt;
		pt.X = m_pDoc->m_cPointX[0];
		pt.Y = -m_pDoc->m_cPointY[0];
		CalcCoords(pt, &scpt, pRECT);
		//scpt.X += CENTER.X;
		//scpt.Y += CENTER.Y;
		OnPlane(scpt, CENTER, &scpt);
		pDC->MoveTo(scpt.X, scpt.Y);
		SetPoint(pDC, BlackPEN, scpt);
		for (int i = 1; i < m_pDoc->m_cPointX.GetCount(); i++) {
			pt.X = m_pDoc->m_cPointX[i];
			pt.Y = -m_pDoc->m_cPointY[i];
			CalcCoords(pt, &scpt, pRECT);
			//pDC->LineTo(scpt.X + CENTER.X, scpt.Y + CENTER.Y);
			//scpt.X += CENTER.X;
			//scpt.Y += CENTER.Y;
			OnPlane(scpt, CENTER, &scpt);
			SetPoint(pDC, BlackPEN, scpt);
			DrawLine(pDC, BluePEN, scpt);
		}
		/*
		OX = 1.0*m_pDoc->m_cPointX.GetCount() / pRECT.right;
		if (m_pDoc->m_Rpnt) {
			//pDC->MoveTo(0, m_pDoc->m_cPointY.GetAt(0));
			for (int i = 0; i < NumPoints; i++)
			{
				end.X = i / OX;
				end.Y = Ar[i];
				SelectObject(*pDC, RPEN);
				Ellipse(*pDC, end.X - Rpnt, end.Y + Rpnt, end.X + Rpnt, end.Y - Rpnt);
				SelectObject(*pDC, BPEN);
				LineTo(*pDC, end.X, end.Y);
				st = end;
			}
		}*/
		double max = 0;
		double b = 0;
		double R = 0;
		
		for (int i = 0; i < m_pDoc->m_cPointX.GetCount(); i++){
			if (max < fabs(m_pDoc->m_cPointX[i])) {
				max = fabs(m_pDoc->m_cPointX[i]);
			}
			if (max < fabs(m_pDoc->m_cPointY[i])) {
				max = fabs(m_pDoc->m_cPointY[i]);
			}
		}

		for (double i = 0; i< max;i += 0.01)
		{
			b = 0;
			for (int j = 0; j < m_pDoc->m_cPointX.GetCount(); j++)
			{
				b += (i*i - m_pDoc->m_cPointY[j]*m_pDoc->m_cPointY[j] - m_pDoc->m_cPointX[j]*m_pDoc->m_cPointX[j])*(i*i - m_pDoc->m_cPointY[j]*m_pDoc->m_cPointY[j] - m_pDoc->m_cPointX[j]*m_pDoc->m_cPointX[j]);
			}
			mass.Add(b);
		}
		 int Num = mass.GetSize();

		double Rm = mass[0];
		for (int i = 1; i < Num; i++)
		{
			if (Rm > mass[i])
				Rm = mass[i];
		}
		for (double i = 0; i<max; i += 0.01)
		{
			b = 0;
			for (int j = 0; j < m_pDoc->m_cPointX.GetCount(); j++)
			{
				b += (i*i - m_pDoc->m_cPointY[j]* m_pDoc->m_cPointY[j] - m_pDoc->m_cPointX[j]*m_pDoc->m_cPointX[j])*(i*i - m_pDoc->m_cPointY[j]*m_pDoc->m_cPointY[j] - m_pDoc->m_cPointX[j]*m_pDoc->m_cPointX[j]);
			}
			if (b == Rm)
				R = i;
		}

		FCOORD zaz = { 0 };
		//zaz.X = 0;
		//zaz.Y = R;
		//CalcCoords(zaz, &zaz, pRECT);
		//OnPlane(zaz, CENTER, &zaz);
		//pDC->MoveTo(CENTER.X, CENTER.Y);
		//DrawLine(pDC, GreenPEN, zaz);
		//SetPoint(pDC, BlackPEN, zaz);
		pDC->MoveTo(CENTER.X, CENTER.Y);

		zaz.X = -R;

		zaz.Y = sqrt(R*R - R*R);
		CalcCoords(zaz, &zaz, pRECT);
		OnPlane(zaz, CENTER, &zaz);
		pDC->MoveTo(zaz.X, zaz.Y);
		for (double i = -R; i < R; i += 0.1) {
			zaz.X = i;
			
			zaz.Y = sqrt(R*R - i*i);
			CalcCoords(zaz, &zaz, pRECT);
			OnPlane(zaz, CENTER, &zaz);
			SetPoint(pDC, RedPEN, zaz);
			DrawLine(pDC, RedPEN, zaz);
		}
		
		for (double i = R; i > -R; i -= 0.1) {
			zaz.X = i;
			zaz.Y = -sqrt(R*R - i*i);
			CalcCoords(zaz, &zaz, pRECT);
			OnPlane(zaz, CENTER, &zaz);
			SetPoint(pDC, RedPEN, zaz);
			DrawLine(pDC, RedPEN, zaz);
		}
		zaz.X = -R;
		zaz.Y = -sqrt(R*R - R*R);
		CalcCoords(zaz, &zaz, pRECT);
		OnPlane(zaz, CENTER, &zaz);
		SetPoint(pDC, RedPEN, zaz);
		DrawLine(pDC, RedPEN, zaz);
	}
	else {
		int * Ar = new int[NumPoints];
		for (int i = 0; i < NumPoints; i++) {
			Ar[i] = -pRECT.bottom/2 + rand() % (pRECT.bottom);
		}
		OX = 1.0 * NumPoints / pRECT.right;

		pDC->MoveTo(0, Ar[0] + CENTER.Y);
		for (int i = 0; i < NumPoints; i++)
		{
			end.X = i / OX;
			end.Y = Ar[i] + CENTER.Y;
			SetPoint(pDC, RedPEN, end);
			DrawLine(pDC, BluePEN, end);
		}
	}


	//SelectObject(*pDC, GPEN);
	/*
	радиус точки
	интерполир точки
	выдел интерп точки
	шаг для интерп точки
	цвет линий и толщина
	
	
	*/
	// TODO: добавьте здесь код отрисовки для собственных данных
}

void CMFCApplication1View::CalcCoords(FCOORD cord, FCOORD *screen, RECT pRECT)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
	//*screen = cord;
	//double Ox = m_pDoc->m_cPointX.GetCount() / pRECT.right;
	//double Oy = 
	double MaxOX = 0;
	double MaxOY = 0;
	for (int i = 0; i < m_pDoc->m_cPointX.GetCount(); i++) {
		if (fabs(m_pDoc->m_cPointX[i]) > MaxOX) {
			MaxOX = fabs(m_pDoc->m_cPointX[i]);
		}
		if (fabs(m_pDoc->m_cPointY[i]) > MaxOY) {
			MaxOY = fabs(m_pDoc->m_cPointY[i]);
		}
	}
	double OX = (pRECT.right / 2) / MaxOX;
	double OY = (pRECT.bottom / 2) / MaxOY;
	double E;
	if (OX > OY) {
		E = OY;
	}
	else {
		E = OX;
	}
	//if ((OX < 1.25*OY) && (1.25*OX > OY)) {
		//cord.X *= OX;
		//cord.Y *= OY;
	//}
	//else {
		cord.X *= E;
		cord.Y *= E;
	//}
	//cord.X *= E;
	//cord.Y *= E;
	//cord.X /= 20;
	//cord.Y /= 20;
	*screen = cord;
	//end.Y = Ar[i] + CENTER.Y;
}
/*
for (int i = 1; i < m_pDoc->m_cPointX.GetCount(); i++) {
	pt.X = m_pDoc->m_cPointX[i];
	pt.Y = m_pDoc->m_cPointY[i];
	CalcCoords(pt, &scpt, pRECT);
	pDC->LineTo(scpt.X, scpt.Y);
}
*/
BOOL CMFCApplication1View::DrawLine(CDC *cDC, HPEN hPen, FCOORD END)
{
	SelectObject(*cDC, hPen);
	return LineTo(*cDC, END.X, END.Y);
}

BOOL CMFCApplication1View::SetPoint(CDC *cDC, HPEN hPen, FCOORD PNT)
{
	EXTLOGPEN PenINFO;
	GetObject(hPen, sizeof(EXTLOGPEN), &PenINFO);
	SelectObject(*cDC, hPen);
	return Ellipse(*cDC, PNT.X - PenINFO.elpWidth, PNT.Y + PenINFO.elpWidth, PNT.X + PenINFO.elpWidth, PNT.Y - PenINFO.elpWidth);
}

void CMFCApplication1View::OnPlane(FCOORD coord1,FCOORD center, FCOORD *coord2)
{
	coord1.X += center.X;
	coord1.Y += center.Y;
	*coord2 = coord1;
}

// печать CMFCApplication1View

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CMFCApplication1View

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CMFCApplication1View
