#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char ch = ':';


int main() {
	FILE *fp;
	char buf[100000];
	fp = fopen("/proc/meminfo", "r");
	
	for(int i = 0; i <= 0; i++) {
		fgets(buf, 100000, fp);
	}

	char *p1 = strchr(buf, ch );

	//printf("%st%in", p1, strtoull(p1, NULL, 10));

	printf("String after |%c| is - |%s|\n", ch, p1);

	  


	return 0;
}
