#ifndef __LINUX_CPROCESSINF_H
#define __LINUX_CPROCESSINF_H
#include <linux/linkage.h>
#include <linux/types.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <asm/uaccess.h>
struct prcdata{
	long prio;
	long weight;
	long rank;
	pid_t uid;
	pid_t gid;
	pid_t pid;
	pid_t pidparent;
	int processcount;
	int gtickets;
	unsigned long volatile gtime;
	int available;
};
#endif
