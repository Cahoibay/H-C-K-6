
// BT_1View.cpp : implementation of the CBT1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "BT_1.h"
#endif

#include "BT_1Doc.h"
#include "BT_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBT1View

IMPLEMENT_DYNCREATE(CBT1View, CView)

BEGIN_MESSAGE_MAP(CBT1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBT1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CBT1View construction/destruction

CBT1View::CBT1View() noexcept
{
	// TODO: add construction code here

}

CBT1View::~CBT1View()
{
}

BOOL CBT1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CBT1View drawing
#include "CLine.h"

void CBT1View::OnDraw(CDC* pDC)
{
	CBT1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
#define DDA			1
#define BRESENHAM	2

	int choice = DDA;

	switch (choice)
	{
	case DDA:
		CLine::LineDDA(pDC, 100, 100, 700, 300, RGB(255, 0, 0));
		break;
	case BRESENHAM:
		CLine::LineBresebham(pDC, 10, 10, 200, 500, RGB(150, 0, 255));
		break;
	}
}


// CBT1View printing


void CBT1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBT1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBT1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBT1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CBT1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBT1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBT1View diagnostics

#ifdef _DEBUG
void CBT1View::AssertValid() const
{
	CView::AssertValid();
}

void CBT1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBT1Doc* CBT1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBT1Doc)));
	return (CBT1Doc*)m_pDocument;
}
#endif //_DEBUG


// CBT1View message handlers
