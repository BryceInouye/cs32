#include "arrayFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {

  int a[]={3,14,15,92,65,35,89};
  int sizeA = 7;

  cout << "arrayToString(a,sizeA)=" << arrayToString(a,sizeA) << endl;

  ASSERT_EQUALS( "{3,14,15,92,65,35,89}", arrayToString(a,sizeA));
  ASSERT_EQUALS( 0, indexOfMin(a,sizeA));
  ASSERT_EQUALS( 3, indexOfMax(a,sizeA));
  swap(a,0,1);
  assertEquals("{14,3,15,92,65,35,89}",
		arrayToString(a,sizeA),
		"arrayToString(a,sizeA); after swap(a,0,1)");

  swap(a,0,2);
  assertEquals("{15,3,14,92,65,35,89}",
		arrayToString(a,sizeA),
		"arrayToString(a,sizeA); after swap(a,0,2)");

  int b[]={79,32,38,46};
  int sizeB = 4;

  cout << "arrayToString(b,sizeB)=" << arrayToString(b,sizeB) << endl;
  ASSERT_EQUALS( "{79,32,38,46}", arrayToString(b,sizeB));
  ASSERT_EQUALS( 1, indexOfMin(b,sizeB));
  ASSERT_EQUALS( 0, indexOfMax(b,sizeB));
  swap(b,1,3);
  assertEquals("{79,46,38,32}",
		arrayToString(b,sizeB),
		"arrayToString(b,sizeB); after swap(b,1,3)");

  swap(b,0,2);
  assertEquals("{38,46,79,32}",
		arrayToString(b,sizeB),
		"arrayToString(b,sizeB); after swap(b,0,2)");

  int c[]={40,30,20,10};
  int sizeC = 4;

  cout << "arrayToString(c,sizeC)=" << arrayToString(c,sizeC) << endl;
  ASSERT_EQUALS( "{40,30,20,10}", arrayToString(c,sizeC));
  ASSERT_EQUALS( 3, indexOfMin(c,sizeC));
  ASSERT_EQUALS( 0, indexOfMax(c,sizeC));

  int d[]={11,21,22,23};
  int sizeD = 4;

  cout << "arrayToString(d,sizeD)=" << arrayToString(d,sizeD) << endl;
  ASSERT_EQUALS( "{11,21,22,23}", arrayToString(d,sizeD));
  ASSERT_EQUALS( 0, indexOfMin(d,sizeD));
  ASSERT_EQUALS( 3, indexOfMax(d,sizeD));

  int e[]={79,32,32,38,46};
  int sizeE = 5;

  cout << "arrayToString(e,sizeE)=" << arrayToString(e,sizeE) << endl;
  ASSERT_EQUALS( "{79,32,32,38,46}", arrayToString(e,sizeE));
  ASSERT_EQUALS( 1, indexOfMin(e,sizeE));
  ASSERT_EQUALS( 0, indexOfMax(e,sizeE));

  int f[]={5,32,32,31,6,4,4};
  int sizeF = 7;

  cout << "arrayToString(f,sizeF)=" << arrayToString(f,sizeF) << endl;
  ASSERT_EQUALS( "{5,32,32,31,6,4,4}", arrayToString(f,sizeF));
  ASSERT_EQUALS( 5, indexOfMin(f,sizeF));
  ASSERT_EQUALS( 1, indexOfMax(f,sizeF));


  int g[]={32,32,38,46,46,4,4};
  int sizeG = 7;

  cout << "arrayToString(g,sizeG)=" << arrayToString(g,sizeG) << endl;
  ASSERT_EQUALS( "{32,32,38,46,46,4,4}", arrayToString(g,sizeG));
  ASSERT_EQUALS( 5, indexOfMin(g,sizeG));
  ASSERT_EQUALS( 3, indexOfMax(g,sizeG));

  return 0;
}
