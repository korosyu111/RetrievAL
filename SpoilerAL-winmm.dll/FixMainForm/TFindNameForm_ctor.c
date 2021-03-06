#include <windows.h>
#include "TWinControl.h"
#include "..\SnapWindow\Attach_SnapWindow.h"
#if SNAP_WINDOW
#include "..\SnapWindow\SnapWindow.h"
#endif

static void __fastcall ctor(LPVOID this);

__declspec(naked) void __cdecl TFindNameForm_ctor()
{
	__asm
	{
		#define this (ebp - 4H)

		mov     ecx, dword ptr [this]
		jmp     ctor

		#undef this
	}
}

static void __fastcall ctor(LPVOID this)
{
	HWND hWnd;

	hWnd = TWinControl_GetHandle(this);
	SetWindowLongA(hWnd, GWL_STYLE, GetWindowLongA(hWnd, GWL_STYLE) & ~WS_MINIMIZEBOX);

#if SNAP_WINDOW
	AttachSnapWindow(hWnd);
#endif
}
