#include <linux/cprocessinf.h>
extern int GOPTION;
asmlinkage int sys_cprocessinf(struct prcdata *data, int option, int nicev){
	if(option == 1)
	{
		cli();
		GOPTION = 1;
		sti();
		return 0;
	}
	else if(option == 0)
	{
		cli();
		GOPTION = 0;
		sti();
		return 0;
	}
	else if(option==600){
		cli();
		struct prcdata k_data;
		int check = copy_from_user(&k_data,data,sizeof(struct prcdata));
		if(check==0){
			k_data.prio = 20 - current->nice;
			k_data.weight = k_data.prio + current->counter;
			k_data.rank = 2 * current->nice;
			k_data.uid = current->uid;
			k_data.gid = current->gid;
			k_data.pid = current->pid;
			k_data.pidparent = current->p_pptr->pid;
			k_data.processcount = atomic_read(&current->user->processes);
			k_data.gtickets = current -> gtickets;
			k_data.gtime = current -> gtime;
			k_data.available = current -> available;
			copy_to_user(data,&k_data,sizeof(struct prcdata));
			sti();
			return 0;
		}
		else {
			sti();
			return -1;
		}
	}
	else if(option==500){
		current->nice = nicev;
		return 0;
	}
	else{
		return -1;
	}
}
