#include<Windows.h>
#include<stdio.h>
#include "res.h"
#include <cstdlib>
#include <ctime>
int liczbaprob = 0, liczbapodana,liczba;
bool gra(HWND hwndDig);
CHAR szText[5];
/*INT_PTR CALLBACK DialogProc(HWND hwndDig, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hwndEditBox = GetDlgItem(hwndDig, IDC_STATIC2);
	SetWindowText(hwndEditBox, "Podaj liczbe z zakresu 1-40");
  switch (uMsg)
  {
  case WM_COMMAND:
    switch (HIWORD(wParam))
    {
    case BN_CLICKED://zdarzenie klikniecia na UI
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON2://klikniecie na nasz przycisk
       /* MessageBox(hwndDig, TEXT("Ok"), TEXT("Klikniecie"), MB_OK);
        HWND hwndEditBox = GetDlgItem(hwndDig, IDC_EDIT1);//pobieranie uchwytu kontrolki  IDC_EDIT1
        int iTextLength = GetWindowTextLength(hwndEditBox);//pobieranie dlugosci tekstu
        CHAR szText[500];
        GetWindowText(hwndEditBox, szText, iTextLength + 1);//pobieranie tekstu

        SetWindowText((HWND)lParam, szText);//przypisanie go do przycisku

        return TRUE;
      }
      return FALSE;
    case EN_CHANGE:
      switch (LOWORD(wParam))
      {
      case IDC_EDIT1:
        HWND hwndEditBox = GetDlgItem(hwndDig, IDC_EDIT1);//
       // int iTextLength = GetWindowTextLength(hwndEditBox);//
        CHAR szText[2];
        GetWindowText(hwndEditBox, szText, 3);//
       // HWND hwndEditBox1 = GetDlgItem(hwndDig, IDC_BUTTON2);//
       // SetWindowText(hwndEditBox1, szText);//
        return TRUE;
      }
      return FALSE;
    }
    return FALSE;
  case WM_LBUTTONDOWN:
   /* CHAR szText[200];
    wsprintf(szText, "Kliknales myszka x=%d, y=%d", LOWORD(lParam), HIWORD(lParam));
    MessageBox(hwndDig, szText, TEXT("Klikniecie"), MB_OK);
    return TRUE;
  case WM_CLOSE:
    DestroyWindow(hwndDig);//zniszczenie okienka
    PostQuitMessage(0);//umieszczenie w petli komunikatow polecenia zakonczenia aplikacji 
    return TRUE;
  }
  return FALSE;
}*/
INT_PTR CALLBACK DialogProc(HWND hwndDig, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		switch (HIWORD(wParam))
		{
		case BN_CLICKED:
			switch (LOWORD(wParam))
			{
			case IDC_BUTTON2:
				gra(hwndDig);
			}
			return FALSE;
		case EN_CHANGE:
			switch (LOWORD(wParam))
			{
			case IDC_EDIT1:
				HWND hwndEditBox = GetDlgItem(hwndDig, IDC_EDIT1);
				GetWindowText(hwndEditBox, szText, 3);
				return TRUE;
			}
			return FALSE;
		}
		return FALSE;
	case WM_CLOSE:
		DestroyWindow(hwndDig);
		PostQuitMessage(0);
		return TRUE;
	}
	return FALSE;
}


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance, PSTR szCmdLIne, int iCmdShow)
{
	srand((unsigned int)time(NULL));
	liczba = (std::rand() % 40) + 1;
	HWND hwndMainWindow = CreateDialog(hinstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
	ShowWindow(hwndMainWindow, iCmdShow);
	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}


bool gra(HWND hwndDig)
{
	srand((unsigned int)time(NULL));
	liczbaprob++;
	CHAR Text[20];
	HWND hwndEditBox = GetDlgItem(hwndDig, IDC_EDIT1), hwndStatic1 = GetDlgItem(hwndDig, IDC_STATIC1);
	int iTextLength = GetWindowTextLength(hwndEditBox);
	liczbapodana = atoi(szText);
	if ((iTextLength > 0) & (iTextLength < 3) & (liczbapodana > 0) & (liczbapodana < 41))
	{
		if (liczba == liczbapodana)
		{
			wsprintf(Text, "Wygrana za %d razem", liczbaprob);
			SetWindowText(hwndStatic1, Text);
			liczba = (std::rand() % 40) + 1;
			liczbaprob = 0;
		}
		else
		{
			if (liczbapodana > liczba) SetWindowText(hwndStatic1, "Liczba wylosowana jest mniejsza");
			else SetWindowText(hwndStatic1, "Liczba wylosowana jest wiêksza");
		}
	}
	else SetWindowText(hwndStatic1, "B³êdna liczba!!!");
	return TRUE;
}