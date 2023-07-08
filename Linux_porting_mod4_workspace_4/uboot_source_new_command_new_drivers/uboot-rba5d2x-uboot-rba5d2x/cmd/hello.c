/*
 * misc functions
 */

#include<common.h>
#include<command.h>
#include<console.h>
#include<linux/delay.h>

static int do_hello(struct cmd_tbl_t *cmdtp, int flag, int argc,char *const argv[])
{
        printf("hello iam from hello cmd\n");
        return 0;
}

U_BOOT_CMD(
        hello,1,0,do_hello,
        "hello cmd introduction",
        "start - Reset the hello.\n"
        "print hello cmd ."
);
