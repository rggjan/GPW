#include <ClanLib/core.h>
#include <ClanLib/network.h>
using namespace clan;


#ifdef WIN32
#pragma comment(linker, "/SUBSYSTEM:CONSOLE")
#endif

#include "client.h"


int main(int, char**)
{
	try
	{
		SetupCore setup_core;
		SetupNetwork setup_network;

		ConsoleWindow console("Console", 160, 1000);
		ConsoleLogger logger;

		Client client;
		client.exec();

		return 0;
	}
	catch (Exception e)
	{
		Console::write_line("Unhandled exception: %1", e.get_message_and_stack_trace());

		return 1;
	}
}
