
// TextOutDemoView.cpp: CTextOutDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "TextOutDemo.h"
#endif

#include "TextOutDemoDoc.h"
#include "TextOutDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextOutDemoView

IMPLEMENT_DYNCREATE(CTextOutDemoView, CView)

BEGIN_MESSAGE_MAP(CTextOutDemoView, CView)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CTextOutDemoView 생성/소멸

CTextOutDemoView::CTextOutDemoView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTextOutDemoView::~CTextOutDemoView()
{
}

BOOL CTextOutDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTextOutDemoView 그리기

void CTextOutDemoView::OnDraw(CDC* /*pDC*/)
{
	CTextOutDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CTextOutDemoView 진단

#ifdef _DEBUG
void CTextOutDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CTextOutDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextOutDemoDoc* CTextOutDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextOutDemoDoc)));
	return (CTextOutDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CTextOutDemoView 메시지 처리기


void CTextOutDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	int nY = 0;
	CFont Font;
	CFont* pOldFont;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 36;
	wsprintf(lf.lfFaceName, TEXT("%s"), TEXT("Arial"));
	Font.CreateFontIndirectW(&lf);
	pOldFont = dc.SelectObject(&Font);
		//
		//TextOut을 이용하여 그냥 출력 '\t'가 반영되지 않는다.
	dc.TextOutW(20, 20, TEXT("\tTest String"));
		//
		//TabbedTextOut 이용하여 '\t'가 들어간 문자열 출력
	int nTabStop = 40;
	dc.TabbedTextOutW(20, 70, TEXT("\tTest String"),1,&nTabStop,20);
	dc.TabbedTextOutW(20, 120, TEXT("\t\tTest String"), 1, &nTabStop, 20);
	dc.SelectObject(pOldFont);
	//
	// 10 ~ 24 폰트까지 출력
	//LOGFONT lf;
	//::ZeroMemory(&lf, sizeof(lf));
	//wsprintf(lf.lfFaceName, TEXT("%s"), TEXT("Italic"));
	//for (int i= 10; i < 25; i++)
	//{
	//	lf.lfHeight = i;	
	//	nY += i;
	//	//Arial, 크기 10 ~ 24 까지 폰트 객체를 생성한다.
	//	Font.CreateFontIndirectW(&lf);
	//	//생성된 폰트로 Test String이라는 문자열을 출력한다.
	//	pOldFont = dc.SelectObject(&Font);
	//	dc.TextOutW(10, nY, TEXT("Test String"));
	//	dc.SelectObject(pOldFont);
	//	//폰트 객체를 삭제한다.
	//	Font.DeleteObject();
	//}
}
