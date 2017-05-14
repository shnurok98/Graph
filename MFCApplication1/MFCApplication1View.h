
// MFCApplication1View.h : ��������� ������ CMFCApplication1View
//

#pragma once
struct FCOORD {
	float X, Y;
};

class CMFCApplication1View : public CView
{
protected: // ������� ������ �� ������������
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

// ��������
public:
	CMFCApplication1Doc* GetDocument() const;
	CMFCApplication1Doc* m_pDoc;
	CArray<double, double> m_cX;
	CArray<double, double> m_cY;
	CArray<double, double> mass;
	//int Rpnt = 3;
// ��������
public:
	
// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void CalcCoords(FCOORD cord, FCOORD *screen, RECT pRECT);
	BOOL DrawLine(CDC *cDC, HPEN hPen, FCOORD END);
	BOOL SetPoint(CDC *cDC, HPEN hPen, FCOORD PNT);
	void OnPlane(FCOORD coord1, FCOORD center, FCOORD *coord2);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSetpar();
};

#ifndef _DEBUG  // ���������� ������ � MFCApplication1View.cpp
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

