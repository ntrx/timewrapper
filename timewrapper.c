#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>


int main(int argc, char ** argv) {
	SetConsoleTitle("Time Wrap for Steam Games");
	FILE *fp;
	
	int m = 0,
		s = 0,
		h = 0;
	int pause = 0;
	char cur_dir[200];
	time_t now;
	struct tm * timeinfo;
	time(&now);
	
	char *appname;
	appname = strrchr(argv[0], '\\');
	appname = ++appname;
	_getcwd(cur_dir, sizeof(cur_dir));
	fp = fopen(appname,"w");
	
	while (h<100) {
		time(&now);
		timeinfo = localtime(&now);
		
		printf ("Game   : %s\n", appname ? appname : argv[0]);
		printf ("uptime : %02d:%02d:%02d\n",h,m,s);
		printf ("curtime: %s\n",asctime(timeinfo));
		Sleep(1000);
		system("cls");
		s++;
		if (s == 60) {
			s = 0;
			m++;
		}
		if (m == 60) {
			s = 0;
			m = 0;
			h++;
		}
		
	}
	fclose(fp);
	return 0;
}
