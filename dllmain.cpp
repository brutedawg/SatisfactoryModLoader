// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "import.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <Windows.h>

//Main DLL for loading mod DLLs
BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		MessageBoxA(NULL, "Attempting to load mod DLLs!", "Satisfactory Mod Loader", NULL);

		// get application path
		char p[MAX_PATH];
		GetModuleFileNameA(NULL, p, MAX_PATH);

		// split the path
		std::string appPath(p);
		size_t pos = appPath.find_last_of('\\');
		std::string path = appPath.substr(0, pos) + "\\mods";
		std::string pathExact = path + "\\";

		for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
			if (entry.path().extension().string() == ".dll") {
				std::string file = pathExact + entry.path().filename().string();
				std::wstring stemp = std::wstring(file.begin(), file.end());
				LPCWSTR sw = stemp.c_str();

				HMODULE dll = LoadLibrary(sw);

				FARPROC valid = GetProcAddress(dll, "isMod");
				if (!valid) {
					FreeLibrary(dll);
					continue;
				}

				// use valid mod if needed
			}
		}
	}
    return TRUE;
}