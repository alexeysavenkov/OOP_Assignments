#include "Array.h"
#include <assert.h>
#include <process.h>
#include <stdio.h>

int main() {

	Array<10, int> a;

	for(int i = 0; i < 10; i++) {
		a[i] = i;
	}
	for(int i = 0; i < 10; i++) {
		assert(a[i] == i);
	}

	try {
		int elem = a[-1];
		puts("TEST FAILED");
	} catch(Array<10, int>::IndexOutOfBoundsException e) { }

	try {
		int elem = a[10];
		puts("TEST FAILED");
	} catch(Array<10, int>::IndexOutOfBoundsException e) { }



	Array<5, bool> b;
	
	for(int i = 0; i < 5; i++) {
		b[i] = i & 1;
	}
	for(int i = 0; i < 5; i++) {
		assert(b[i] == (i & 1));
	}

	try {
		int elem = b[-1];
		puts("TEST FAILED");
	} catch(Array<5, bool>::IndexOutOfBoundsException e) { }

	try {
		int elem = b[10];
		puts("TEST FAILED");
	} catch(Array<5, bool>::IndexOutOfBoundsException e) { }


	puts("ALL TESTS PASSED");

	system("pause");

	return 0;
}