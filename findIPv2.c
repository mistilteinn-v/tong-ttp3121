#include <stdio.h>
#include <string.h>

int main(){

FILE *fp;
char returnData[64];

fp = popen("/sbin/ifconfig eth0", "r");

while (fgets(returnData, 64, fp) != NULL)
{
    while ((splitText = strtok(returnData, " ")) != NULL) {
    	returnData = NULL;
    	printf(":%s:\n", splitText);
    }
}

pclose(fp);
return(0);
}