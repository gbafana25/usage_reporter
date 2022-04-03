#define FPATH  "/home/gareth/usage_reporter/pr"

typedef struct {
	pid_t id;
	time_t s_time;
	time_t e_time;


} pid_obj;

pid_obj start_proc() {
	pid_obj pro;
	pid_t process = fork();
	pro.id = process;
	pro.s_time = time(NULL);
	return pro;

}

pid_obj track_existing(int p) {
	pid_obj pro;
	pro.id = p;
	pro.s_time = time(NULL);
	return pro;

}

void stop_obj(pid_obj pb) {
	pb.e_time = time(NULL);
	// record time
	FILE *test;
	test = fopen("/home/gareth/usage_reporter/status", "a+");
	fprintf(test, "Process %d closed, ran for %d\n", pb.id, pb.e_time - pb.s_time);
	fclose(test);



}


int strtoint(char *e) {
	int result;
	// strlen(e) - 1 prevents newlines from being added
	for(int i = 0; i < strlen(e) - 1; i++) {
		result *= 10;
		result += e[i] - 48;

	}
	return result;

}

