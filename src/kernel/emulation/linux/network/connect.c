#include "connect.h"
#include "../base.h"
#include "../errno.h"
#include <asm/unistd.h>
#include "../../../../../platform-include/sys/socket.h"
#include "../../../../../platform-include/sys/errno.h"

extern void *memcpy(void *dest, const void *src, unsigned long n);

long sys_connect(int fd, const void* name, int socklen)
{
	int ret;
	int linux_domain;
	struct sockaddr_fixup* fixed;

	if (socklen > 512)
		return -EINVAL;

	fixed = __builtin_alloca(socklen);
	memcpy(fixed, name, socklen);

	fixed->linux_family = fixed->bsd_family;

#ifdef __NR_socketcall
	ret = LINUX_SYSCALL(__NR_socketcall, LINUX_SYS_CONNECT, fd, fixed, socklen);
#else
	ret = LINUX_SYSCALL(__NR_connect, fd, fixed, socklen);
#endif

	if (ret < 0)
		ret = errno_linux_to_bsd(ret);

	return ret;
}

