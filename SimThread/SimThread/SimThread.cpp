// SimThread.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>

using namespace std;


DWORD WINAPI StartAddress(LPVOID lpParam)
{
	cout << "Hi,i am a simple thread..." << endl << "I am used to show how to create a new thread" << endl;
	return 0;
}




int main(int argc,char * argv[])
{
	//Create a thread
	HANDLE hThread = CreateThread(NULL,0,StartAddress,NULL,0,NULL);


	//Create a process
	STARTUPINFO startupInfo = {0};
	PROCESS_INFORMATION proc_info = {0};

#ifdef _DEBUG
	BOOL bSuccess = CreateProcess(
		L"..//Debug//tmpProcess.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &proc_info);

#else

	BOOL bSuccess = CreateProcess(
		L"..//Release//tmpProcess.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &proc_info);

#endif

	//
	WaitForSingleObject(hThread,INFINITE);
	CloseHandle(hThread);
	return system("pause");

}



