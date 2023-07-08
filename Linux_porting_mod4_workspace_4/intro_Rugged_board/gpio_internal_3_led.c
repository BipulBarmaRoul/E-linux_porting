#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define GPIO_EN "/sys/class/gpio/export"
#define GPIO_DIR1 "/sys/class/gpio/PC13/direction"
#define GPIO_DIR2 "/sys/class/gpio/PC17/direction"
#define GPIO_DIR3 "/sys/class/gpio/PC19/direction"
#define GPIO_Val1 "/sys/class/gpio/PC13/value"
#define GPIO_Val2 "/sys/class/gpio/PC17/value"
#define GPIO_Val3 "/sys/class/gpio/PC19/value"

int main()
{
	int gpio_fd1;
        int gpio_fd2;
        int gpio_fd3;

	char gpio_buf1[30];
        char gpio_buf2[30];
        char gpio_buf3[30];

	int gpio_num1 = 77;
        int gpio_num2 = 81;
        int gpio_num3 = 83;
	int count1 = 2;
        int count2 = 2;
        int count3 = 2;

	gpio_fd1 = open(GPIO_EN,O_WRONLY);
	if(gpio_fd1 < 0)
	{
		printf("Unable to opne the file %s\n",GPIO_EN);
		exit(0);
	}
	//printf("Enable the GPIO_13");
	sprintf(gpio_buf1,"%d",gpio_num1);
	write(gpio_fd1,gpio_buf1,strlen(gpio_buf1));
	close(gpio_fd1);


        gpio_fd2 = open(GPIO_EN,O_WRONLY);
	if(gpio_fd2 < 0)
	{
		printf("Unable to opne the file %s\n",GPIO_EN);
		exit(0);
	}
	//printf("Enable the GPIO_17");
	sprintf(gpio_buf2,"%d",gpio_num2);
	write(gpio_fd2,gpio_buf2,strlen(gpio_buf2));
	close(gpio_fd2);
        

        gpio_fd3 = open(GPIO_EN,O_WRONLY);
	if(gpio_fd3 < 0)
	{
		printf("Unable to opne the file %s\n",GPIO_EN);
		exit(0);
	}
	//printf("Enable the GPIO_19");
	sprintf(gpio_buf3,"%d",gpio_num3);
	write(gpio_fd3,gpio_buf3,strlen(gpio_buf3));
	close(gpio_fd3);



       

       
        //printf("Configuration of GPIO_13 direction\n");
	gpio_fd1 = open(GPIO_DIR1,O_WRONLY);
        if(gpio_fd1 < 0)
        {       
                printf("Unable to opne the file %s\n",GPIO_DIR1);
                exit(0);
        }       
        write(gpio_fd1,"out",3);
        close(gpio_fd1);
      

        //printf("Configuration of GPIO_17 direction\n");
	gpio_fd2 = open(GPIO_DIR2,O_WRONLY);
        if(gpio_fd2 < 0)
        {       
                printf("Unable to opne the file %s\n",GPIO_DIR2);
                exit(0);
        }       
        write(gpio_fd2,"out",3);
        close(gpio_fd2);
      
     
        //printf("Configuration of GPIO_19 direction\n");
	gpio_fd3 = open(GPIO_DIR3,O_WRONLY);
        if(gpio_fd3 < 0)
        {       
                printf("Unable to opne the file %s\n",GPIO_DIR3);
                exit(0);
        }       
        write(gpio_fd3,"out",3);
        close(gpio_fd3);





        //printf("Set the value into GPIO_Val_13\n");
	gpio_fd1 = open(GPIO_Val1,O_WRONLY);
        if(gpio_fd1 < 0)
        {
                printf("Unable to opne the file %s\n",GPIO_Val1);
                exit(0);
        }
        printf("Toggling the GPIO PIN13\n");
        while(count1--)
	{
		write(gpio_fd1,"0",1);
		sleep(1);
		write(gpio_fd1,"1",1);
                sleep(1);
	}

        //printf("Set the value into GPIO_Val_17\n");
	gpio_fd2 = open(GPIO_Val2,O_WRONLY);
        if(gpio_fd2 < 0)
        {
                printf("Unable to opne the file %s\n",GPIO_Val2);
                exit(0);
        }
        printf("Toggling the GPIO PIN17\n");
        while(count2--)
	{
		write(gpio_fd2,"0",1);
		sleep(1);
		write(gpio_fd2,"1",1);
                sleep(1);
	}
        
        //printf("Set the value into GPIO_Val_19\n");
	gpio_fd3 = open(GPIO_Val3,O_WRONLY);
        if(gpio_fd3 < 0)
        {
                printf("Unable to opne the file %s\n",GPIO_Val3);
                exit(0);
        }
        printf("Toggling the GPIO PIN19\n");
        while(count3--)
	{
		write(gpio_fd3,"0",1);
		sleep(1);
		write(gpio_fd3,"1",1);
                sleep(1);
	}
        
}


