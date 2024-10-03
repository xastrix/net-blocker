#include "inetfw.h"
#include "utils.h"

int wmain(int argc, const wchar_t** argv)
{
	if (!utils::IsAdminRights()) {
		printf("You need administrator rights\n");
		return 0;
	}

	if (argc == 3 && wcscmp(argv[2], L"--net-on") == 0) {
		if (InetFW::setUnblock(argv[1])) {
			printf("The internet for this application has been turned back on\n");
		}
	}
	else if (argc == 4 && wcscmp(argv[3], L"--net-off") == 0) {
		if (InetFW::setRule(argv[1], argv[2])) {
			wprintf(L"The internet for \"%ls\" is down successful\n", argv[2]);
		}
	}
	else {
		printf("net-blocker\n");
		printf("  Is an utility that allows you to prevent a specific application from using the Internet\n\n");

		printf("Usage\n");
		printf("  net-blocker <RuleID> <PathToTheDubiousApplication> --net-off\n");
		printf("  net-blocker <RuleID> --net-on\n\n");
		
		printf("Example\n");
		printf("  net-blocker test123 \"C:\\MalwareFiles\\Malware.exe\" --net-off\n");
		printf("  net-blocker test123 --net-on\n\n");

		printf("Copyright <c> xastrix 2024\n");
	}

	return 0;
}