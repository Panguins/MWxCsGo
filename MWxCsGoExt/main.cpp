#include <Windows.h>
#include "mem.h"
#include "player.h"
#include "offsets.h"
#include <iostream>



int main() {
	CGame my_player;

	if (g_memory.open("csgo.exe"))
	{
		printf("The process has been found.\n");
	}
	else
	{
		printf("No Process Found.\n");
		getchar();
		return 0;
	}

	g_memory.getmodule("client_panorama.dll", &client_module, &module_size);
	g_memory.getmodule("engine.dll", &engine_module, &module_size);

	//setting the ent list addr
	offset.getEntList();

	return 0;
}