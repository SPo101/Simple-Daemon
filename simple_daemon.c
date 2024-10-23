//we could interact with application via signalls
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void daemonize(){
	pid_t pid = fork();

	if( pid > 0){// parent process
		exit(0);
	}
	if( pid == 0){// child process
	}

	if(setsid() == -1){
		printf("error");
		exit(1);
	}

	//do it second time to be sure that process is in background mode: thus it cant connect to terminal
	pid = fork();
	if( pid > 0){// parent process
		exit(0);
	}
	if( pid == 0){// child process
	}
	chdir("/");
	
	//sysconf determine application limit of smth
	//sysconf(_SC_OPEN_MAX) gives number of maximum available file descriptors
	//to close them all, we should run threw each of them
	for(int fd = sysconf(_SC_OPEN_MAX); fd > 0; fd--)
		close(fd);
	
	fclose(stdin);
	fclose(stdout);
	fclose(stderr);

	stdin = fopen("/dev/null", "r");
	stdout = fopen("/dev/null", "w");
	stderr = fopen("/dev/null", "w");
}

int main(){
	daemonize();
}
