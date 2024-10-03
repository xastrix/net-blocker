#include "utils.h"

BOOL utils::IsAdminRights()
{
	BOOL   elevated = 0;
	HANDLE h        = 0;

	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &h))
	{
		DWORD size = 0;
		GetTokenInformation(h, TokenElevation, NULL, 0, &size);

		TOKEN_ELEVATION* elevation = (TOKEN_ELEVATION*)malloc(size);
		if (GetTokenInformation(h, TokenElevation, elevation, size, &size))
		{
			elevated = elevation->TokenIsElevated;
		}
		free(elevation);
	}

	if (h)
		CloseHandle(h);

	return elevated == TRUE;
}