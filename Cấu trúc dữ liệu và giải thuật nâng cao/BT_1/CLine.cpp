#include "pch.h"
#include "CLine.h"
#define Round(x)(int)(x+0.5)

using namespace std;

void CLine::_LineDDA1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	pDC->SetPixel(x1, y1, color);
	float m = (float)(y2 - y1) / (x2 - x1);
	float y = y1;

	while (x1 < x2)
	{
		x1++;
		y += m;
		pDC->SetPixel(x1, Round(y), color);
	}

}

void CLine::_LineDDA2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	pDC->SetPixel(x1, y1, color);
	float k = (float)(x2 - x1) / (y2 - y1);
	float x = x1;

	while (y1 < y2)
	{
		y1++;
		x += k;
		pDC->SetPixel(Round(x), y1, color);
	}

}

void CLine::LineDDA(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	if ((x1 == x2) && (y1 == y2))
	{
		pDC->SetPixel(x1, y1, color);
		return;
	}
	if (abs(x2 - x1) >= abs(y2 - y1))
	{
		if (x1 <= x2)
			_LineDDA1(pDC, x1, y1, x2, y2, color);
		else
			_LineDDA1(pDC, x2, y2, x1, y1, color);
	}
	else
	{
		if (y1 <= y2)
			_LineDDA2(pDC, x1, y1, x2, y2, color);
		else
			_LineDDA2(pDC, x2, y2, x1, y1, color);
	}

}


void CLine::LineBresebham(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	if ((x1 == x2) && (y1 == y2))
	{
		pDC->SetPixel(x1, y1, color);
		return;
	}

	if (abs(x2 - x1) >= abs(y2 - y1))
	{
		if (x1 <= x2)
			_LineBresebham1(pDC, x1, y1, x2, y2, color);
		else
			_LineBresebham1(pDC, x2, y2, x1, y1, color);
	}
	else
	{
		if (y1 <= y2)
			_LineBresebham2(pDC, x1, y1, x2, y2, color);
		else
			_LineBresebham2(pDC, x2, y2, x1, y1, color);
	}
}

void CLine::_LineBresebham1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	int Dx = x2 - x1; //DentaX
	int Dy = y2 - y1; //DentaY

	Dx = abs(Dx);
	Dy = abs(Dy);

	int Const1 = Dy << 1;//2DY
	int Const2 = (Dy - Dx) << 1;//2(DY-DX)
	int p = Const1 - Dx;//p1 = 2DY-DX

	pDC->SetPixel(x1, y1, color);

	for (int i = 0; i < Dx; i++)
	{
		if (p < 0)
		{
			p += Const1;//p(i+1) = pi  + 2DY
			y1 = y1;
		}
		else
		{
			p += Const2;//p(i+1) = pi + 2(DY-DX)
			y1 ++;
		}

		++x1;
		pDC->SetPixel(x1, y1, color);

	}

}

void CLine::_LineBresebham2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	int Dx = x2 - x1; //DentaX
	int Dy = y2 - y1; //DentaY

	Dx = abs(Dx);
	Dy = abs(Dy);

	int Const1 = Dx << 1;//2DX
	int Const2 = (Dx- Dy) << 1;//2(DX-DY)
	int p = Const1 - Dy;//p1 = 2DX-DY

	pDC->SetPixel(x1, y1, color);

	for (int i = 0; i < Dy; i++)
	{
		if (p < 0)
		{
			p += Const1;//p(i+1) = pi  + 2DX
			x1 = x1;
		}
		else
		{
			p += Const2;//p(i+1) = pi + 2(DX-DY)
			x1++;
		}

		++y1;
		pDC->SetPixel(x1, y1, color);
	}
}


