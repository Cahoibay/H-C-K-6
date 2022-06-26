#pragma once

class CLine
{
public:
	static void LineDDA(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	static void LineBresebham(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
public:
	static void _LineDDA1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	static void _LineDDA2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);

	static void _LineBresebham1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	static void _LineBresebham2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
};

