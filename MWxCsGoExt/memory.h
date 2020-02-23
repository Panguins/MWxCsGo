#pragma once
#include <windows.h>
#include <TlHelp32.h>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

class c_memory {
	int m_process_index{};

	HANDLE m_process_handle{};

	uintptr_t m_process_size{};
	uintptr_t m_process_base{};

	bool m_has_process = false;

public:
	c_memory() {}

	~c_memory() { if (m_process_handle) CloseHandle(m_process_handle); }


	//Open Process
	bool open(const char* target_name) {
		m_process_index = get(target_name);
		m_process_handle = OpenProcess(PROCESS_ALL_ACCESS, false, m_process_index);

		if (!base(target_name, &m_process_base, &m_process_size))
			return false;

		printf("> process ID: %X | process base: 0x%X | process size: 0x%X \n", m_process_index, m_process_base, m_process_size);
		m_has_process = true;

		return !!m_process_index && !!m_process_handle && !!m_process_base && m_process_handle != INVALID_HANDLE_VALUE;
	}

	//Grab the module
	__forceinline bool base(const char* module_name, uintptr_t* base, uintptr_t* size) {
		MODULEENTRY32  me32;
		HANDLE         snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_process_index);

		if (snap == INVALID_HANDLE_VALUE)
			return 0;

		me32.dwSize = sizeof(MODULEENTRY32);

		if (!Module32First(snap, &me32)) {
			CloseHandle(snap);
			return false;
		}

		do
		{
			if (!std::strcmp(me32.szModule, module_name))
			{
				*base = uintptr_t(me32.modBaseAddr);
				*size = uintptr_t(me32.modBaseSize);
				CloseHandle(snap);
				return true;
			}
		} while (Module32Next(snap, &me32));

		CloseHandle(snap);
		return false;

	}

	bool opened()
	{
		return m_has_process;
	}

	//Get Module Function
	bool getmodule(const char* moduleName, uintptr_t* moduleVar, uintptr_t* moduleSize) {
		if (base(moduleName, moduleVar, moduleSize))
		{
			printf("we got the module!\n");
			printf("> Module Address?: 0X%X \n", *moduleVar);
		}
		else
		{
			printf("Module not found!\n");
			getchar();

			return false;
		}
		return true;
	}

	uintptr_t get_base_address()
	{
		return m_process_base;
	}

	__forceinline void write(uintptr_t address, void* value, size_t size)
	{
		WriteProcessMemory(m_process_handle, (LPVOID)address, (LPCVOID)value, size, 0);
	}

	__forceinline void read(uintptr_t address, void* buffer, size_t size) {
		ReadProcessMemory(m_process_handle, (LPVOID)address, buffer, size, 0);
	}

	template< typename type = uintptr_t > __forceinline type read(uintptr_t address, size_t size)
	{
		unsigned long buffer;
		ReadProcessMemory(m_process_handle, (LPVOID)address, &buffer, size, 0);
		return (type)buffer;
	}


private:
	__forceinline int get(const char* process_)
	{
		PROCESSENTRY32 pe32;
		HANDLE         snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		if (snap == INVALID_HANDLE_VALUE)
			return 0;

		pe32.dwSize = sizeof(PROCESSENTRY32);

		if (!Process32First(snap, &pe32))
		{
			CloseHandle(snap);
			return 0;
		}

		do
		{
			if (!std::strcmp(pe32.szExeFile, process_))
			{
				CloseHandle(snap);
				return pe32.th32ProcessID;
			}

		} while (Process32Next(snap, &pe32));

		CloseHandle(snap);
		return 0;
		//MessageBoxA(nullptr, "couldnt find target", "NIGGA", MB_OK);
	}


};
extern c_memory g_memory;