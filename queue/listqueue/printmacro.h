#ifndef __PRINTMACRO__
#define __PRINTMACRO__
#include <syslog.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define _DEBUG  1
#define TOSYSLOG 0
#define TOFILE   0

#if (_DEBUG)
#define MYDEBUG(format,...) printf("FILE: "__FILE__", LINE: %d: "format"", __LINE__, ##__VA_ARGS__)
#if (TOSYSLOG)
#define MYPRINT(format,...) do { \
	syslog(LOG_ERR|LOG_USER,""format"",##__VA_ARGS__); \
	closelog(); \
}while(0);
#elif (TOFILE)
#define MYPRINT(format,...) printf("FILE: "__FILE__", LINE: %d: "format"", __LINE__, ##__VA_ARGS__)
#define DUPSTDIN(logfd) do { \
	if ( dup2((logfd),1) < 0 ) \
	{ \
		perror("dup2 error\n"); \
	} \
}while(0);
#else
#define MYPRINT(format,...) printf("FILE: "__FILE__", LINE: %d: "format"", __LINE__, ##__VA_ARGS__)
#endif
#else
#define MYDEBUG(format,...) do { \
}while(0);
#if (TOSYSLOG)
#define MYPRINT(format,...) do { \
	syslog(LOG_ERR|LOG_USER,""format"",##__VA_ARGS__); \
	closelog(); \
}while(0);
#elif (TOFILE)
#define MYPRINT(format,...) printf("FILE: "__FILE__", LINE: %d: "format"", __LINE__, ##__VA_ARGS__)
#define DUPSTDIN(logfd) do { \
	if ( dup2((logfd),1) < 0 ) \
	{ \
		perror("dup2 error\n"); \
	} \
}while(0);
#else
#define MYPRINT(format,...) printf("FILE: "__FILE__", LINE: %d: "format"", __LINE__, ##__VA_ARGS__)
#endif
#endif
#endif
