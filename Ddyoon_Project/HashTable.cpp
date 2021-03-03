#include<stdio.h>
#include<string.h>
#include<memory.h>

#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096

typedef struct {
	char key[MAX_KEY + 1];
	char data[MAX_DATA + 1];
}Hash;

Hash table[MAX_TABLE];

unsigned long hash(const char* str) {
	unsigned long hash = 5381;
	int c;

	while (c = *str++) {

		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}
	
	return hash % MAX_TABLE;
}

int find(const char* key, char* data) {
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;

	while (table[h].key[0] != 0 && cnt--) {
		if (strcmp(table[h].key, key) == 0) {
			strcpy(data, table[h].data);
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

int add(const char* key, char* data) {
	unsigned long h = hash(key);

	while (table[h].key[0] != 0) {
		if (!strcmp(table[h].key, key)) return 0;
		h = (h + 1) % MAX_TABLE;
	}

	strcpy(table[h].key, key);
	strcpy(table[h].data, data);
}

int main() {

	int T, N, Q;

	return 0;
}