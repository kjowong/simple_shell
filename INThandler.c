#include "shell.h"

void INThandler(int sig)
{
	signal(sig, SIG_IGN);
	signal(SIGINT, INThandler);
}
