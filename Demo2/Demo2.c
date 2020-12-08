//for all kernel module
#include<linux/kernel.h>
//used for module functionality
#include<linux/module.h>
#include<linux/moduleparam.h>
#include<linux/stat.h>

#define AUTHOR "PARTH BASOLE"
#define DESC "Demo kernel module of Wowbagger"
//LICENSING
MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESC);
int no=11;
//module_param(no,int,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

//MODULE_PARM_DESC(no,"Integer Variable");
//Gets called when module gets loaded 
int strt(void)
{//FUNCTION TO PRINT IN KERNAL LOG FILE
printk(KERN_INFO "P Kernel module loaded : %d \n",no);

return 0;
}
//Gets called when module gets unloaded 
void end(void)
{
printk(KERN_INFO "P Kernel module unloaded \n");
}
//Callback re assignment
module_init(strt);
module_exit(end);
