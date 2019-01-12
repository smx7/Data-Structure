#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<malloc.h>

typedef struct BitSet
{
	size_t *_bits;
	size_t _range;
}BitSet;
void BSInit(BitSet *bs, size_t range);
void BSSet(BitSet *bs, size_t x);
void BSReset(BitSet *bs, size_t x);
void BSDestory(BitSet *bs);
int BSTest(BitSet *bs, size_t x);
