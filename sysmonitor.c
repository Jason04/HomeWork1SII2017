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
	



	
	//////////////////////////////////////////////////////////////////////////////////////////////////// 




	return 0;
}
