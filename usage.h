#define FPATH  "/home/gareth/usage_reporter/pr"
#define LOG_PATH "/home/gareth/usage_reporter/status.log"
#define CSV_PATH "/home/gareth/usage_reporter/data.csv"
#define CSIZE 		15
#define PA_SIZE 	15

typedef struct {
	pid_t id;
	time_t s_time;
	time_t e_time;
	char *name;


} pid_obj;

typedef struct {
	char *name;
	int time_alive;

} csv_obj;

typedef struct {
	csv_obj array[CSIZE];
	int c;

} data_array;

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



void append_obj(csv_obj d[], int curr, csv_obj o) {
	d[curr] = o;
	//memcpy((void *) &d[curr], (const void *) &o, sizeof(csv_obj));
	//printf("%s %d\n", d[curr].name, d[curr].time_alive);
	curr++;


}

csv_obj create_data_object(char *n, int t) {
	csv_obj s;
	s.name = malloc(strlen(n) * sizeof(char));
	strcpy(s.name, n);
	s.time_alive = t;
	return s;

}

void write_to_csv(csv_obj d) {
	//csv_obj r = create_data_object(d.name, d.e_time - d.s_time);
	FILE *data;
	data = fopen(CSV_PATH, "a+");
	fprintf(data, "%s,%d\n", d.name, d.time_alive);
	fclose(data);

}

void proc_exists(pid_obj *ar[], char *n, int count) {

	for(int i = 0; i < count; i++) {
		if(strcmp(ar[i]->name, n) == 0) {
			printf("Exists\n");
		}

		//printf("%s\n", ar[i].name);	

	}

}

void stop_obj(pid_obj pb, csv_obj d[], int co) {
	pb.e_time = time(NULL);
	// record time
	FILE *test;
	test = fopen(LOG_PATH, "a+");
	fprintf(test, "Process %d (%s) closed, ran for %d\n", pb.id, pb.name, pb.e_time - pb.s_time);
	fclose(test);
	csv_obj c = create_data_object(pb.name, pb.e_time - pb.s_time);
	write_to_csv(c);
	//append_obj(d, co, c);



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

