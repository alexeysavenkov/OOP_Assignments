#include "Sequence.h"
#include "assert.h"
#include <process.h>
#include <stdio.h>

int main() {
	Sequence<int> seq;
	seq.add(1);
	seq.add(2);
	assert(seq.size() == 2);
	assert(seq[0] == 1);
	assert(seq[1] == 2);
	seq.cut();
	assert(seq.size() == 1);
	assert(seq[0] == 2);
	puts("TEST SUCCESSFUL");
	system("pause");
	return 0;
}