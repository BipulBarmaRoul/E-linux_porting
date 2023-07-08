#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define GPIO_EN "/sys/class/gpio/export"
#define GPIO_DIR "/sys/class/gpio/PC13/direction"
#define GPIO_Val "/sys/class/gpio/PC13/value"

int main()
{
	int gpio_fd,fd;
        int cnt=0;
	char gpio_buf[30];
        char value;
	int gpio_num = 77;
	int count = 10;
	gpio_fd = open(GPIO_EN,O_WRONLY);
	if(gpio_fd < 0)
	{
		printf("Unable to open the file %s\n",GPIO_EN);
		exit(0);
	}
	//printf("Enable the GPIO_LED");
	sprintf(gpio_buf,"%d",gpio_num);
	write(gpio_fd,gpio_buf,strlen(gpio_buf));
	close(gpio_fd);

	//printf("Configuration of GPIO_LED direction\n");
	gpio_fd = open(GPIO_DIR,O_WRONLY);
        if(gpio_fd < 0)
        {       
                printf("Unable to open the file %s\n",GPIO_DIR);
                exit(0);
        }       
        write(gpio_fd,"out",3);
        close(gpio_fd);

        //printf("Set the value into GPIO_LED_Val\n");
	gpio_fd = open(GPIO_Val,O_WRONLY);
        if(gpio_fd < 0)
        {
                printf("Unable to open the file %s\n",GPIO_Val);
                exit(0);
        }

        //printf("switch operation\n");
        fd = open("/sys/class/gpio/export",O_WRONLY);
	if(fd < 0)
	{
		printf("Unable to export the file PC12\n");
		exit(0);
	}
        write(fd,"76",2);
        close(fd);
         
        fd = open("/sys/class/gpio/PC12/direction",O_WRONLY);
	if(fd < 0)
	{
		printf("Unable to open the direction of file PC12\n");
		exit(0);
	}
        write(fd,"in",2);
        close(fd);

        while(1)
        {
                fd = open("/sys/class/gpio/PC12/value",O_RDONLY);
                if(fd < 0)
	        {
		        printf("Unable to open the file\n");
		        exit(0);
	        }
                read(fd,&value,1);
                if(value == '0')
                {
                        cnt++;
                        if((cnt%2)!=0)
                        {
                                write(gpio_fd,"0",1);
                                printf("LED ON\n");
                        }
                        else
                        {
                                write(gpio_fd,"1",1);
                                printf("LED OFF\n");
                        }
		}
                //else
                //{
		        //write(gpio_fd,"1",1);
                        //printf("LED OFF\n");
                //}
                close(fd);
        }
        close(gpio_fd);
}

