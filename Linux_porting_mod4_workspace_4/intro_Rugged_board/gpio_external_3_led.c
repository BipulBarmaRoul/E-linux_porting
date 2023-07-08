#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define GPIO_EN "/sys/class/gpio/export"
#define GPIO_DIR1 "/sys/class/gpio/PD21/direction"
#define GPIO_DIR2 "/sys/class/gpio/PD26/direction"
#define GPIO_DIR3 "/sys/class/gpio/PD28/direction"
#define GPIO_Val1 "/sys/class/gpio/PD21/value"
#define GPIO_Val2 "/sys/class/gpio/PD26/value"
#define GPIO_Val3 "/sys/class/gpio/PD28/value"

int main()
{
	int gpio_fd1;
        int gpio_fd2;
        int gpio_fd3;

	char gpio_buf1[30];
        char gpio_buf2[30];
        char gpio_buf3[30];

	int gpio_num1 = 117;
        int gpio_num2 = 122;
        int gpio_num3 = 124;
	int count1 = 2;
        int count2 = 2;
        int count3 = 2;

	gpio_fd1 = open(GPIO_EN,O_WRONLY);
	if(gpio_fd1 < 0)
	{
		printf("Unable to opne the file %s\n",GPIO_EN);
		exit(0);
	}
	//printf("Enable the GPIOD_21");
	sprintf(gpio_buf1,"%d",gpio_num1);
	write(gpio_fd1,gpio_buf1,strlen(gpio_buf1));
	close(gpio_fd1);


        gpio_fd2 = open(GPIO_EN,O_WRONLY);
	if(gpio_fd2 < 0)
	{
		printf("Unable to opne the file %s\n",GPIO_EN);
		exit(0);
	}
	//printf("Enable the GPIOD_26");
	sprintf(gpio_buf2,"%d",gpio_num2);
	write(gpio_fd2,gpio_buf2,strlen(gpio_buf2));
	close(gpio_fd2);
        

        gpio_fd3 = open(GPIO_EN,O_WRONLY);
	if(gpio_fd3 < 0)
	{
		printf("Unable to opne the file %s\n",GPIO_EN);
		exit(0);
	}
	//printf("Enable the GPIOD_28");
	sprintf(gpio_buf3,"%d",gpio_num3);
	write(gpio_fd3,gpio_buf3,strlen(gpio_buf3));
	close(gpio_fd3);



       

       
        //printf("Configuration of GPIOD_21 direction\n");
	gpio_fd1 = open(GPIO_DIR1,O_WRONLY);
        if(gpio_fd1 < 0)
        {       
                printf("Unable to opne the file %s\n",GPIO_DIR1);
                exit(0);
        }       
        write(gpio_fd1,"out",3);
        close(gpio_fd1);
      

        //printf("Configuration of GPIOD_26 direction\n");
	gpio_fd2 = open(GPIO_DIR2,O_WRONLY);
        if(gpio_fd2 < 0)
        {       
                printf("Unable to opne the file %s\n",GPIO_DIR2);
                exit(0);
        }       
        write(gpio_fd2,"out",3);
        close(gpio_fd2);
      
     
        //printf("Configuration of GPIOD_28 direction\n");
	gpio_fd3 = open(GPIO_DIR3,O_WRONLY);
        if(gpio_fd3 < 0)
        {       
                printf("Unable to opne the file %s\n",GPIO_DIR3);
                exit(0);
        }       
        write(gpio_fd3,"out",3);
        close(gpio_fd3);





        //printf("Set the value into GPIO_Val_21\n");
	gpio_fd1 = open(GPIO_Val1,O_WRONLY);
        if(gpio_fd1 < 0)
        {
                printf("Unable to opne the file %s\n",GPIO_Val1);
                exit(0);
        }
        printf("Toggling the GPIOD PIN21\n");
        while(count1--)
	{
		write(gpio_fd1,"1",1);
		sleep(1);
		write(gpio_fd1,"0",1);
                sleep(1);
	}

        //printf("Set the value into GPIO_Val_26\n");
	gpio_fd2 = open(GPIO_Val2,O_WRONLY);
        if(gpio_fd2 < 0)
        {
                printf("Unable to opne the file %s\n",GPIO_Val2);
                exit(0);
        }
        printf("Toggling the GPIOD PIN26\n");
        while(count2--)
	{
		write(gpio_fd2,"1",1);
		sleep(1);
		write(gpio_fd2,"0",1);
                sleep(1);
	}
        
        //printf("Set the value into GPIO_Val_28\n");
	gpio_fd3 = open(GPIO_Val3,O_WRONLY);
        if(gpio_fd3 < 0)
        {
                printf("Unable to opne the file %s\n",GPIO_Val3);
                exit(0);
        }
        printf("Toggling the GPIOD PIN28\n");
        while(count3--)
	{
		write(gpio_fd3,"1",1);
		sleep(1);
		write(gpio_fd3,"0",1);
                sleep(1);
	}
        
}


