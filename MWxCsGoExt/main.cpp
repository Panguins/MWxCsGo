#include "memory.h"
#include "offset.h"
#include "player.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

int main() {
	CGame my_player;
	Offset offset;

	//open process if doesnt return true than exception
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

	// Get Modules
	g_memory.getmodule("client_panorama.dll", &client_module, &module_size);
	g_memory.getmodule("engine.dll", &engine_module, &module_size);


	//setting the ent list addr
	offset.getEntList();

	while (1) {
		//while (GetKeyState(VK_XBUTTON1) & 0x8000)
		//{
			// get the player address of selected entity in the list
		Sleep(10);
		//}
	}

	//for (int i = 0; i < 64; i++)
	//{ }


	return 0;
};
