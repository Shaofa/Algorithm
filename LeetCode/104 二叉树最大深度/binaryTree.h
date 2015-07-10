#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <iostream>
using namespace std;

#define DEBUG
#
#if defined(DEBUG)
#define LOG(format, ...)	\
							fprintf(stdout, "[%s %s]: "##format##"\t(%s Line %d)\n", \
							__DATE__,	\
							__TIME__,	\
							##__VA_ARGS__,	\
							__FILE__,	\
							__LINE__)
#else
#
#define LOG(format, ...)
#
#endif

typedef int data_t;

#endif //_BINARY_TREE_H_