#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <asm/current.h>
#include <linux/sched.h>
MODULE_LICENSE("GPL");
static int major = 0;
static int minor = 0;
const int count = 3;
#define DEVNAME "demo"
static struct cdev *demop = NULL;

//打开设备
static int demo_open(struct inode* inode, struct file* filp)
{
	//get command and pid
	printk(KERN_INFO "(%s:pid=%d), %s : %s : %d\n", current->comm, current->pid, __FILE__, __func__, __LINE__);
	printk(KERN_INFO "(major=%d, minor=%d), %s : %s : %d\n", imajor(inode), iminor(inode), __FILE__, __func__, __LINE__);
	return 0;
}

//关闭设备
static int demo_release(struct inode* inode, struct file* filp)
{
	//get command and pid
	printk(KERN_INFO "(%s:pid=%d), %s : %s : %d\n", current->comm, current->pid, __FILE__, __func__, __LINE__);
	printk(KERN_INFO "(major=%d, minor=%d), %s : %s : %d\n", imajor(inode), iminor(inode), __FILE__, __func__, __LINE__);
	return 0;
}

//读设备
static ssize_t demo_read(struct file* filp, char __user *buf, size_t size, loff_t* offset)
{
	struct inode *inode = filp->f_path.dentry->d_inode;

