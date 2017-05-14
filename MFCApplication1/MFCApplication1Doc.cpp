
// MFCApplication1Doc.cpp : ���������� ������ CMFCApplication1Doc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "SetParamsDlg.h"
#include "afxtempl.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication1Doc

IMPLEMENT_DYNCREATE(CMFCApplication1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication1Doc, CDocument)
	ON_COMMAND(ID_SETPAR, &CMFCApplication1Doc::OnSetpar)
END_MESSAGE_MAP()


// ��������/����������� CMFCApplication1Doc

CMFCApplication1Doc::CMFCApplication1Doc()
{
	// TODO: �������� ��� ��� ������������ ������ ������������
	m_dDocStep = 0.1f;
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

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)
	srand(time(0));
	for (int i = 0; i < m_iNum; i++) {
		m_dX[i] = i;
		//ctime(0);
		m_dY[i] = rand() % 99;
	}
	return TRUE;
}




// ������������ CMFCApplication1Doc

void CMFCApplication1Doc::Serialize(CArchive& ar)
{
	
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
		ar << m_iNum;
		for (int i = 0; i < m_iNum; i++) {
			ar << m_dX[i];
			ar << m_dY[i];
		}
	}
	else
	{
		// TODO: �������� ��� ��������
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

// ��������� ��� �������
void CMFCApplication1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
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

// ��������� ������������ ������
void CMFCApplication1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
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

// ����������� CMFCApplication1Doc

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


// ������� CMFCApplication1Doc


void CMFCApplication1Doc::OnSetpar()
{
	// TODO: �������� ���� ��� ����������� ������
	CSetParamsDlg dlg;
	dlg.m_dStep = m_dDocStep;
	if (dlg.DoModal() == IDOK) {
		m_cPointX.RemoveAll();
		m_cPointY.RemoveAll();
		m_dDocStep = dlg.m_dStep;
		m_cPointX.Append(dlg.m_fx);
		m_cPointY.Append(dlg.m_fy);
		
	}
	//m_cPointX.GetAt(1);
}
