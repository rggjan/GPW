#include "server.h"

#ifdef WIN32
#pragma comment(linker, "/SUBSYSTEM:CONSOLE")
#endif

int main(int, char**)
{
	try
	{
		SetupCore setup_core;
		SetupNetwork setup_network;

		ConsoleWindow console("Console", 160, 1000);
		ConsoleLogger logger;

		Server server;
		server.exec();

		return 0;
	}
	catch (Exception e)
	{
		Console::write_line("Unhandled exception: %1", e.get_message_and_stack_trace());

		return 1;
	}
}
