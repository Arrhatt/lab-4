#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define _SIZE_ 99999


struct Details {
	char id [12];
	char* name;
	int count;
};





void InsertionSort(struct Details detail[], int n, int order, int id) {
	int temp, i = 0, j = 0;
	char tmp1[12], tmp2[12];
	if (id == 0) {
		for (i = 1; i < n; i++) {
			temp = detail[i].count;
			strcpy(tmp1, detail[i].name);
			strcpy(tmp2, detail[i].id );
			j = i - 1;
			while ((j >= 0)&& (order != (detail[j].count > temp))) {
				detail[j+1].count = detail[j].count;
				strcpy(detail[j+1].id , detail[j].id );
				strcpy(detail[j+1].name, detail[j].name);
				j = j - 1;
			}
			detail[j+1].count = temp;
			strcpy(detail[j+1].name, tmp1);
			strcpy(detail[j+1].id , tmp2);
		}
	} else if (id == 1) {
		if (!order) {
			for (i = 1; i < n; i++) {
				temp = detail[i].count;
				strcpy(tmp1, detail[i].name);
				strcpy(tmp2, detail[i].id );
				j = i - 1;
				while ((j >= 0) && (0 < strcmp(detail[j].name, tmp1))) {
					detail[j+1].count = detail[j].count;
					strcpy(detail[j+1].id , detail[j].id );
					strcpy(detail[j+1].name, detail[j].name);
					j = j - 1;
				}
				detail[j+1].count = temp;
				strcpy(detail[j+1].name, tmp1);
				strcpy(detail[j+1].id , tmp2);
			}
		} else {
			for (i = 1; i < n; i++) {
				temp = detail[i].count;
				strcpy(tmp1, detail[i].name);
				strcpy(tmp2, detail[i].id );
				j = i - 1;
				while ((j >= 0) && (0 > strcmp(detail[j].name, tmp1))) {
					detail[j+1].count = detail[j].count;
					strcpy(detail[j+1].id , detail[j].id );
					strcpy(detail[j+1].name, detail[j].name);
					j = j - 1;
				}
				detail[j+1].count = temp;
				strcpy(detail[j+1].name, tmp1);
				strcpy(detail[j+1].id , tmp2);
			}
		}
	} else {
		if (!order) {
			for (i = 1; i < n; i++) {
				temp = detail[i].count;
				strcpy(tmp1, detail[i].name);
				strcpy(tmp2, detail[i].id );
				j = i - 1;
				while ((j >= 0) && (0 < strcmp(detail[j].id , tmp2))) {
					detail[j+1].count = detail[j].count;
					strcpy(detail[j+1].id , detail[j].id );
					strcpy(detail[j+1].name, detail[j].name);
					j = j - 1;
				}
				detail[j+1].count = temp;
				strcpy(detail[j+1].name, tmp1);
				strcpy(detail[j+1].id , tmp2);
			}
		} else {
			for (i = 1; i < n; i++) {
				temp = detail[i].count;
				strcpy(tmp1, detail[i].name);
				strcpy(tmp2, detail[i].id );
				j = i - 1;
				while ((j >= 0) && (0 > strcmp(detail[j].id , tmp2))) {
					detail[j+1].count = detail[j].count;
					strcpy(detail[j+1].id , detail[j].id );
					strcpy(detail[j+1].name, detail[j].name);
					j = j - 1;
				}
				detail[j+1].count = temp;
				strcpy(detail[j+1].name, tmp1);
				strcpy(detail[j+1].id , tmp2);
			}
		}
	}

}

void GnomeSort(struct Details detail[], int n, int order, int id) {
	int i = 1, j = 2;
	if (id == 0) {
		while (i < n) {
			if (order == (detail[i-1].count > detail[i].count)) {
				i = j;
				j++;
			} else {
				int temp = detail[i].count;
				detail[i].count = detail[i-1].count;
				detail[i-1].count = temp;
				char tmp[12];
				strcpy(tmp, detail[i].id );
				strcpy(detail[i].id , detail[i-1].id );
				strcpy(detail[i-1].id , tmp);
				strcpy(tmp, detail[i].name);
				strcpy(detail[i].name, detail[i-1].name);
				strcpy(detail[i-1].name, tmp);
				i--;
				if (i==0) {
					i=j;
					j++;
				}
			}
		}
	} else if (id == 1) {
		while (i < n) {
			if (!order?(strcmp(detail[i].name, detail[i-1].name)>0):(strcmp(detail[i].name, detail[i-1].name)<0)) {
				i = j;
				j++;
			} else {
				int temp = detail[i].count;
				detail[i].count = detail[i-1].count;
				detail[i-1].count = temp;
				char tmp[12];
				strcpy(tmp, detail[i].id );
				strcpy(detail[i].id , detail[i-1].id );
				strcpy(detail[i-1].id , tmp);
				strcpy(tmp, detail[i].name);
				strcpy(detail[i].name, detail[i-1].name);
				strcpy(detail[i-1].name, tmp);
				i--;
				if (i==0) {
					i=j;
					j++;
				}
			}
		}
	} else {
		while (i < n) {
			if (!order?(strcmp(detail[i].id , detail[i-1].id )>0):(strcmp(detail[i].id , detail[i-1].id )<0)) {
				i = j;
				j++;
			} else {
				int temp = detail[i].count;
				detail[i].count = detail[i-1].count;
				detail[i-1].count = temp;
				char tmp[12];
				strcpy(tmp, detail[i].id );
				strcpy(detail[i].id , detail[i-1].id );
				strcpy(detail[i-1].id , tmp);
				strcpy(tmp, detail[i].name);
				strcpy(detail[i].name, detail[i-1].name);
				strcpy(detail[i-1].name, tmp);
				i--;
				if (i==0) {
					i=j;
					j++;
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int i;
	struct Details detail[_SIZE_];
	int a, option;

	FILE *f = NULL, *f2 = NULL;

	printf("\nNumbers:\n");
	i = 1;
	while (i < argc) {
		f = fopen(argv[i], "r");
		i++;
		if (f == NULL) {
		} else {
			break;
		}
	}
	if (f == NULL) {
		printf("Error Reading File\n");
		exit(0);
	}

	while (i < argc) {
		f2 = fopen(argv[i], "w");
		i++;
		if (f == NULL) {
		} else {
			break;
		}
	}
	if (f2 == NULL) {
		printf("Error Reading File\n");
		exit(0);
	}

	i = 0;
	while (((detail[i].name = (char*)malloc(256)) > 0) & (fscanf(f, "\n%s", detail[i].id ) == 1) & (fscanf(f, "%s", detail[i].name) == 1) & (fscanf(f, "%d", &detail[i].count) == 1)) {
		printf("%s  %s  %d\n", detail[i].id , detail[i].name, detail[i].count);
		if (strlen(detail[i].id ) != 8) {
			printf("Wrong Type Format\n");
			exit(0);
		}
		i++;
	}
	printf("\n");
	int field = 0, order = 0, sort = 0;
	while ((option = getopt(argc, argv, "ad123gi")) != -1) {
		printf("!\n");
		switch (option) {
			case 'd':
				order = 1;
				break;
			case '1':
				field = 2;
				break;
			case '2':
				field = 1;
				break;
			case '3':
				field = 0;
				break;
			case 'g':
				sort = 1;
				break;
			case 'i':
				sort = 2;
				break;
			case 'q':
				sort = 3;
				break;
			default:
				field = 0;
				order = 0;
				sort = 0;
		}
	}
	switch (sort) {
		case 1:
			printf("Gnome sort done:\n");
			GnomeSort(detail, i, order, field);
			break;
		case 2:
			printf("Insert sort done:\n");
			InsertionSort(detail, i, order, field);
			break;
	}
	for (a = 0; a < i; a++) {
		printf("%s  %s  %d\n", detail[a].id , detail[a].name, detail[a].count);
		fprintf(f2, "%s  %s  %d\n", detail[a].id , detail[a].name, detail[a].count);
	}
	fclose(f);
	fclose(f2);


	system("pause");
	return 0;
}
