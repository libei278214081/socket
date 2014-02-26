#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;
HANDLE hMutex;
HANDLE hThead;
DWORD WINAPI Fun(LPVOID lpParamter)
{
	while(1) { 
		WaitForSingleObject(hMutex, INFINITE);
		cout<<"Fun display!"<<endl; 
		Sleep(1000);
		ReleaseMutex(hMutex);
}

int main()
{
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	hMutex = CreateMutex(NULL, FALSE, "screen");
	CloseHandle(hThread);
	while(1) {
		WaitForSingleObject(hMutex, INFINITE);
		cout<<"main display!"<<endl;  
		Sleep(2000);
		ReleaseMutex(hMutex);
	}
	return 0;
}