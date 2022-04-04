#define FPATH  "/home/gareth/usage_reporter/pr"
#define LOG_PATH "/home/gareth/usage_reporter/status.log"

typedef struct {
	pid_t id;
	time_t s_time;
	time_t e_time;
	char *name;


} pid_obj;

pid_obj start_proc(char *n) {
	pid_obj pro;
	pid_t process = fork();
	pro.id = process;
	pro.s_time = time(NULL);
	pro.name = malloc(strlen(n) * sizeof(char));
	strcpy(pro.name, n);
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
	test = fopen(LOG_PATH, "a+");
	fprintf(test, "Process %d (%s) closed, ran for %d\n", pb.id, pb.name, pb.e_time - pb.s_time);
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

