#include <iostream>
#include "XuLy.h"
using namespace std;

int main()
{
	int arr1[4999];
	int arr2[4999];
	TaoMangRd(arr1, 1, 4999);
	TaoMangRd(arr2, 5001, 9999);
	DSLOP dsl;
	DSMH dsm;
	DSCH dsch;
	DSDT dsdt;
	MainProcess(dsl, dsm, dsch, dsdt, arr1, arr2);
	return 0;
}