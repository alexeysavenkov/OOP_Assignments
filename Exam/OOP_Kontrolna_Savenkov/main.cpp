#include <iostream>
#include "BoundedSet.h"
#include "UnboundedSet.h"
#include "SetOnListInherit.h"
#include "SetOnListComposit.h"
#include <assert.h>
#include <process.h>

using namespace std;

void testBoundedSet();
void testUnboundedSet();
void testSetOnListInherit();
void testSetOnListComposit();

int main() {

	testBoundedSet();
	testUnboundedSet();
	testSetOnListInherit();
	testSetOnListComposit();

	system("pause");

	return 0;
}

void testBoundedSet() {
	BoundedSet<int, 5> boundedSet;

	assert(boundedSet.empty());

	boundedSet.add(1);
	boundedSet.add(2);
	assert(!boundedSet.empty());
	assert(boundedSet.size() == 2);
	assert(boundedSet.in(1) && boundedSet.in(2));
	assert(!boundedSet.in(3) && !boundedSet.in(4));

	boundedSet.show();

	BoundedSet<int, 5> boundedSet2(boundedSet);
	assert(boundedSet2.del(2));
	assert(boundedSet2.size() == 1);
	assert(boundedSet2.in(1));

	boundedSet2.add(3);
	boundedSet2.add(4);
	boundedSet2.add(5);
	assert(boundedSet2.size() == 4);
	
	BoundedSet<int, 5> unionSet = boundedSet + boundedSet2;
	assert(unionSet.size() == 5);

	try {
		unionSet.add(10);
		assert(false);
	} catch (LimitOverflowException e) {

	}
	
	BoundedSet<int, 5> intersectSet = boundedSet * boundedSet2;
	assert(intersectSet.size() == 1);
	assert(intersectSet.in(1));

	intersectSet.addAll(unionSet);
	assert(intersectSet.size() == 5);

	std::cout << "BoundedSet test successful" << std::endl;
}

void testUnboundedSet() {
	UnboundedSet<int> boundedSet;

	assert(boundedSet.empty());

	boundedSet.add(1);
	boundedSet.add(2);
	assert(!boundedSet.empty());
	assert(boundedSet.size() == 2);
	assert(boundedSet.in(1) && boundedSet.in(2));
	assert(!boundedSet.in(3) && !boundedSet.in(4));

	boundedSet.show();

	UnboundedSet<int> boundedSet2(boundedSet);
	assert(boundedSet2.del(2));
	assert(boundedSet2.size() == 1);
	assert(boundedSet2.in(1));

	boundedSet2.add(3);
	boundedSet2.add(4);
	boundedSet2.add(5);
	assert(boundedSet2.size() == 4);
	
	UnboundedSet<int> unionSet = boundedSet + boundedSet2;
	assert(unionSet.size() == 5);
	
	UnboundedSet<int> intersectSet = boundedSet * boundedSet2;
	assert(intersectSet.size() == 1);
	assert(intersectSet.in(1));

	intersectSet.addAll(unionSet);
	assert(intersectSet.size() == 5);

	std::cout << "UnboundedSet test successful" << std::endl;
}

void testSetOnListInherit() {
	SetOnListInherit<int> boundedSet;

	assert(boundedSet.empty());

	boundedSet.add(1);
	boundedSet.add(2);
	assert(!boundedSet.empty());
	assert(boundedSet.size() == 2);
	assert(boundedSet.in(1) && boundedSet.in(2));
	assert(!boundedSet.in(3) && !boundedSet.in(4));

	boundedSet.show();

	SetOnListInherit<int> boundedSet2(boundedSet);
	assert(boundedSet2.del(2));
	assert(boundedSet2.size() == 1);
	assert(boundedSet2.in(1));

	boundedSet2.add(3);
	boundedSet2.add(4);
	boundedSet2.add(5);
	assert(boundedSet2.size() == 4);
	
	SetOnListInherit<int> unionSet = boundedSet + boundedSet2;
	assert(unionSet.size() == 5);
	
	SetOnListInherit<int> intersectSet = boundedSet * boundedSet2;
	assert(intersectSet.size() == 1);
	assert(intersectSet.in(1));

	intersectSet.addAll(unionSet);
	assert(intersectSet.size() == 5);

	std::cout << "SetOnListInherit test successful" << std::endl;
}

void testSetOnListComposit() {
	SetOnListComposit<int> boundedSet;

	assert(boundedSet.empty());

	boundedSet.add(1);
	boundedSet.add(2);
	assert(!boundedSet.empty());
	assert(boundedSet.size() == 2);
	assert(boundedSet.in(1) && boundedSet.in(2));
	assert(!boundedSet.in(3) && !boundedSet.in(4));

	boundedSet.show();

	SetOnListComposit<int> boundedSet2(boundedSet);
	assert(boundedSet2.del(2));
	assert(boundedSet2.size() == 1);
	assert(boundedSet2.in(1));

	boundedSet2.add(3);
	boundedSet2.add(4);
	boundedSet2.add(5);
	assert(boundedSet2.size() == 4);
	
	SetOnListComposit<int> unionSet = boundedSet + boundedSet2;
	assert(unionSet.size() == 5);
	
	SetOnListComposit<int> intersectSet = boundedSet * boundedSet2;
	assert(intersectSet.size() == 1);
	assert(intersectSet.in(1));

	intersectSet.addAll(unionSet);
	assert(intersectSet.size() == 5);

	std::cout << "SetOnListComposit test successful" << std::endl;
}