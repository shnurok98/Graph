
// MFCApplication1Doc.h : ��������� ������ CMFCApplication1Doc
//


#pragma once


class CMFCApplication1Doc : public CDocument
{
protected: // ������� ������ �� ������������
	CMFCApplication1Doc();
	DECLARE_DYNCREATE(CMFCApplication1Doc)

// ��������
public:
	int m_iNum = 30;
	double m_dX[30];
	double m_dY[30];
	double m_dDocStep;
	double X, Y;
	CArray<double, double> m_cPointX;
	CArray<double, double> m_cPointY;
	CArray<double, double> m_cPointXi;
	CArray<double, double> m_cPointYi;
	int nDlg;

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CMFCApplication1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnSetpar();
	void action();
	double polinom(double x);
	afx_msg void OnSetParam2();
};
