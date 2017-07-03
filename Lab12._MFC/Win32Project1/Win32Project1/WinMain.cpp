#include <afxwin.h> 

class CMyMainWnd : public CFrameWnd
{ 
public: 
	bool Growing; 
	int FigureIDToDraw; 

	CMyMainWnd()
	{
		Create(NULL, L"WindowName"); 
		FigureIDToDraw = 0; 
		Growing = true; 
		SetTimer(1, 3000, NULL); 
		SetTimer(2, 2000, NULL); 
	} 

	~CMyMainWnd()
	{ 
		KillTimer(1); 
		KillTimer(2); 
	} 

		afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT uCtlColor); 
		afx_msg void OnRButtonDown(UINT, CPoint); 
		afx_msg void OnLButtonDblClk(UINT, CPoint); 
		afx_msg void OnPaint(); 
		afx_msg void OnTimer(UINT); 
		DECLARE_MESSAGE_MAP(); 
}; 

BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd) 
ON_WM_LBUTTONDOWN() 
ON_WM_RBUTTONDOWN() 
ON_WM_LBUTTONDBLCLK() 
ON_WM_PAINT() 
ON_WM_TIMER() 
END_MESSAGE_MAP() 

	class CMyApp : public CWinApp
	{ 
		public: 
			CMyApp(){}; 
			virtual BOOL InitInstance()
			{ 
				m_pMainWnd = new CMyMainWnd(); 
				m_pMainWnd->ShowWindow(SW_SHOW); 
				return TRUE; 
			} 
	}; 
CMyApp App; 

void CMyMainWnd::OnRButtonDown(UINT, CPoint)
{ 
	AfxMessageBox(L"Правая кнопка мыши");
} 

HBRUSH CMyMainWnd::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{ 
	pDC->SetBkColor(RGB(255, 0, 0)); 
	return (HBRUSH)::GetStockObject(GRAY_BRUSH); 
} 

void CMyMainWnd::OnLButtonDblClk(UINT, CPoint)
{ 
	RECT Rect; 
	this->GetWindowRect(&Rect); 

	int CurrentSizeX = Rect.right - Rect.left; 
	int CurrentSizeY = Rect.bottom - Rect.top; 

	int MaxSizeX = 1366; 
	int MaxSizeY = 786; 
	int MinSizeX = 300; 
	int MinSizeY = 300; 

	if (CurrentSizeX >= MaxSizeX || CurrentSizeY >= MaxSizeY) 
		this->Growing = false; 

	else if (CurrentSizeX <= MinSizeX || CurrentSizeY <= MinSizeY) 
		this->Growing = true; 

	if (Growing == true)
		this->SetWindowPos(0, 0, 0, CurrentSizeX + 100, CurrentSizeY + 100, SWP_NOMOVE | SWP_NOZORDER); 
	else 
		this->SetWindowPos(0, 0, 0, CurrentSizeX - 100, CurrentSizeY - 100, SWP_NOMOVE | SWP_NOZORDER); 
} 

void CMyMainWnd::OnPaint()
{ 
	CPaintDC* PaintDC = new CPaintDC(this); 

	switch (this->FigureIDToDraw % 6)
	{ 
		case 0:
			{ 
				PaintDC->Rectangle(50, 50, 300, 300); 
				PaintDC->TextOutW(10, 10, L"Quad"); 
			}break; 

		case 1:
			{ 
				PaintDC->Rectangle(50, 50, 300, 150); 
				PaintDC->TextOutW(10, 10, L"Rectangle"); 
			}break; 

		case 2:
			{ 
				PaintDC->Ellipse(50, 50, 200, 200); 
				PaintDC->TextOutW(10, 10, L"Circle"); 
			}break; 

		case 3:
			{ 
				PaintDC->Ellipse(50, 50, 400, 200); 
				PaintDC->TextOutW(10, 10, L"Ellipse"); 
			}break; 

		case 4:
			{ 
				PaintDC->Chord(50, 50, 400, 400, 200, 50, 500, 200); 
				PaintDC->TextOutW(10, 10, L"Segment"); 
			}break; 

		case 5:
			{ 
				PaintDC->Pie(50, 50, 400, 400, 50, 200, 200, 50); 
				PaintDC->TextOutW(10, 10, L"Sector"); 
			}break; 
	} 
	this->FigureIDToDraw++; 
} 

void CMyMainWnd::OnTimer(UINT IdEvent){ 
if (IdEvent == 1){ 

} 
else if (IdEvent == 2){ 
this->Invalidate(); 
} 
}