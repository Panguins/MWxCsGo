#pragma once

class c_memory {

	public:
		c_memory() {}

		~c_memory() { if (m_process_handle) CloseHandle(m_process_handle); }

		bool open(const char* target_name);
		bool opened() {};
		bool getmodule(const char* moduleName, uintptr_t* moduleVar, uintptr_t* moduleSize);

		uintptr_t get_base_address();

		__forceinline bool base(const char* module_name, uintptr_t* base, uintptr_t* size);
		__forceinline void write(uintptr_t address, void* value, size_t size);
		__forceinline void read(uintptr_t address, void* buffer, size_t size);

		template< typename type = uintptr_t > __forceinline type read(uintptr_t address, size_t size);
		template< typename type = uintptr_t > __forceinline type write(uintptr_t address, size_t size);

	private:
		uintptr_t get(const char* process_);
		int m_process_index{};

		HANDLE m_process_handle{};

		uintptr_t m_process_size{};
		uintptr_t m_process_base{};

		bool m_has_process = false;
};


extern c_memory g_memory;
