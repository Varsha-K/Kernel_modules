#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

static int myint = 0;
static char *mystr;

module_param(myint, int, 0);
module_param(mystr, charp, 0);

MODULE_PARM_DESC(myint, "This int gives the number of time the greetings must be printed.");
MODULE_PARM_DESC(mystr, "This string is the name of the person to be greeted.");
// You get the picture.  Always use a MODULE_PARM_DESC() for each MODULE_PARM().

static int greet_init(void)
{
	int i;
	for(i=0; i<myint; i++){
		printk(KERN_ALERT "Hello %s\n", mystr);
	}
	return 0;
}

static void greet_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world \n");
}

module_init(greet_init);
module_exit(greet_exit);

