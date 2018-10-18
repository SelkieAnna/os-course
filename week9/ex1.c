#include <stdio.h>
#include <stdlib.h>

struct Frame {
	int number;
	int age;
	int referenced;
};

void paging_system_simulation(int page_frames) {
	struct Frame frames[page_frames];
	int i;
	for (i = 0; i < page_frames; i++) {
		frames[i].number = 0;
		frames[i].age = 0;
		frames[i].referenced = 0;
	}
	int page;
	int hits = 0;
	int misses = 0;
	int hit = 0;
	FILE *file;
	file = fopen("input.txt", "r");
	while (!feof(file)) {
		// read
		if (fscanf(file, "%d", &page) == 1) {
			// hit/miss?
			for (i = 0; i < page_frames; i++) {
				if (page == frames[i].number) {
					hit = 1;
					break;
				}
			}
			if (hit == 1) {
				hits++;
				int hit_index = i;
				frames[hit_index].referenced = 1;
				frames[hit_index].age = (frames[hit_index].age >> 1) + 128;
				for (i = 0; i < page_frames; i++) {
				        if (i != hit_index) {
						frames[i].referenced = 0;
						frames[i].age = frames[i].age >> 1;
					}
                        	}
			} else {
				misses++;
				int min_age = frames[0].age;
				int min_age_index = 0;
				for (i = 0; i < page_frames; i++) {
					if (min_age > frames[i].age || ((frames[min_age_index].number != 0) && (frames[i].number == 0))) {
						min_age = frames[i].age;
						min_age_index = i;
					}
				}
				frames[min_age_index].number = page;
				frames[min_age_index].age = 128;
				frames[min_age_index].referenced = 1;
				for (i = 0; i < page_frames; i++) {
                                	if (i != min_age_index) {
                                        	frames[i].referenced = 0;
						frames[i].age = frames[i].age >> 1;
                                	}
                        	}
                	}
		}
		hit = 0;
	}
	printf("Hit/Miss ratio is %d/%d\n", hits, misses);
}

int main() {
	int n;	// number of page frames
	printf("Enter a number of page frames:\n");
	scanf("%d", &n);
	paging_system_simulation(n);
	return 0;
}
