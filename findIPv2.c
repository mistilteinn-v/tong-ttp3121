#include <stdio.h>
#include <string.h>

int main(){

FILE *fp;
char returnData[64];
char splitText[64], *s = returnData, *token;


fp = popen("/sbin/ifconfig eth0", "r");

while (fgets(returnData, 64, fp) != NULL)
{
	printf("String :%s\n", returnData);
	s = returnData;
	while ((token = strtok(s, " ")) != NULL) {
        s = NULL;
    	printf("Token:%s\n", token);
    }
}


pclose(fp);
return(0);
}
