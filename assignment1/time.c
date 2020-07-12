#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[]){
	int pid = fork();
	if(pid > 0){
		int begin = uptime();
		printf(1,"start time is %d\n",begin);//this is an debug log print
		pid = wait();
		//parent will wait child to finish and count time.
		int end = uptime();
		printf(1,"end time is %d\n",end);//this is an debug log print
		int difference = end - begin;
		printf(1,"the difference is %d\n",difference);
		exit();
	}
	else{
		//child will execute the command 
		printf(1,"child start\n");//this is an debug log print
		char* command = argv[1];
		printf(1,"command is %s\n",command);//this is an debug log print
		exec(command, &argv[1]);
		exit();
	}
}
