#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	//////////////////////////////////////////////Get used memory////////////////////////////////////
	const char ch = ':';
	FILE *fp;
	char buf[100000];
	char *p1;

	fp = fopen("/proc/meminfo", "r");
	
	for(int i = 0; i <= 2; i++) {

		fgets(buf, 100000, fp);

		p1 = strchr(buf, ch);

		if(i==0){

			printf("%s%s","MemTotal",p1);
		}
		if(i==2){

			printf("%s%s","MemAvalible ",p1);
		}
		else{
			//Nothing
		}		
	}
	printf("%s%s\n","MemUsed: ","MemTotal - MemAvalible");
	//printf("%s%s%llu", "MemTotal",p1, strtoull(p1, NULL, 10));
	//printf("String after |%c| is - |%s|\n", ch, p1);
	////////////////////////////////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////Get CPU used/////////////////////////////////////////
	
	long double a[7], b[4], loadavg;
    FILE *fp2;
    char dump[50];

    for(;;)
    {
        fp2 = fopen("/proc/stat","r");
        fscanf(fp2,"%*s %Lf %Lf %Lf %Lf %Lf %Lf %Lf",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
        fclose(fp2);       

        //loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3]));
        //printf("The current CPU utilization is : %Lf\n",loadavg);

        printf("%Lf\n",100-(a[3]*100)/(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]));

        
        return 0;

    }





	//////////////////////////////////////////////////////////////////////////////////////////////////// 

	return 0;
}
