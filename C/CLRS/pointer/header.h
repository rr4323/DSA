#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#define RAII_VARIABLE(vartype,varname,initval,dtor) \
	void _dtor_ ## varname (vartype * v) { dtor(*v); } \
	vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)

