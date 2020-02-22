#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <TlHelp32.h>
#include "offsets.h"

class c_memory {

	//PUBLIC BEGINS
	public:

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



		//Get the Base Address
		uintptr_t get_base_address()
		{
			return m_process_base;
		}


		// See if process is Open
		bool opened()
		{
			return m_has_process;
		}


		//Read
		__forceinline void write(uintptr_t address, void* value, size_t size)
		{
			WriteProcessMemory(m_process_handle, (LPVOID)address, (LPCVOID)value, size, 0);
		}
		//Write
		__forceinline void read(uintptr_t address, void* buffer, size_t size) {
			ReadProcessMemory(m_process_handle, (LPVOID)address, buffer, size, 0);
		}

		//Template Read Func
		template< typename type = uintptr_t > __forceinline type read(uintptr_t address, size_t size)
		{
			unsigned long buffer;
			ReadProcessMemory(m_process_handle, (LPVOID)address, &buffer, size, 0);
			return (type)buffer;
		}

		//Template Write Func
		template< typename type = uintptr_t > __forceinline type write(uintptr_t address, size_t size)
		{
			unsigned long buffer;
			WriteProcessMemory(m_process_handle, (LPVOID)address, &buffer, size, 0);
			return (type)buffer;
		}

		// PRIVATE BEGINS
		private:

			int m_process_index{};

			HANDLE m_process_handle{};

			uintptr_t m_process_size{};
			uintptr_t m_process_base{};

			bool m_has_process = false;


			//Get the Process ID
			uintptr_t get(const char* process_) {
				HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
				PROCESSENTRY32 pe32;
				if (snap == INVALID_HANDLE_VALUE) {
					return 0;
				}
				else {
					pe32.dwSize = sizeof(PROCESSENTRY32);

					if (!Process32First(snap, &pe32)) {
						CloseHandle(snap);
						return 0;
					}

					do {
						if (!std::strcmp(pe32.szExeFile, process_)) {
							CloseHandle(snap);
							return pe32.th32ProcessID;
						}
					} while (Process32Next(snap, &pe32));
					CloseHandle(snap);
					return 0;
				}
			}
};



extern c_memory g_memory;
