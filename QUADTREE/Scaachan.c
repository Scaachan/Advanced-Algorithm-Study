#include <stdio.h>
#include <string.h>

#define endl '\n'

char s[1001];

int rcs(char *c) {
	char ch = *c;
	if (ch == 'b' || ch == 'w') return 1;

	char top[1001], bottom[1001];
	int t = 0, b = 0;

	t += rcs(c + 1);
	t += rcs(c + t + 1);
	b += rcs(c + t + 1);
	b += rcs(c + t + b + 1);
	
	strncpy(top, c+1, t * sizeof(char));
	strncpy(bottom, c+t+1, b * sizeof(char));
	strncpy(c+1, bottom, b * sizeof(char));
	strncpy(c+b+1, top, t * sizeof(char));

	return t + b + 1;
}

int main(void) {
	int TC; scanf("%d", &TC);
	while (TC--) {
		scanf("%s", s);
		rcs(s);
		puts(s);
	}
}
