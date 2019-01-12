#define _CRT_SECURE_NO_WARNINGS 1
#include"bitset.h"
void BSInit(BitSet *bs, size_t range)
{
	assert(bs);
	bs->_bits = (size_t*)malloc(sizeof(size_t)*(range / 32 + 1));
	assert(bs->_bits);
	memset(bs->_bits, 0, sizeof(size_t)*(range / 32 + 1));
	bs->_range = range;
}
void BSSet(BitSet *bs, size_t x)
{
	assert(bs);
	size_t index = x / 32;
	size_t num = x % 32;
	bs->_bits[index] |= (1 << num);

}
void BSReset(BitSet *bs, size_t x)
{
	assert(bs);
	size_t index = x / 32;
	size_t num = x % 32;
	bs->_bits[index] &= ~(1 << num);

}
void BSDestory(BitSet *bs)
{
	assert(bs);
	free(bs->_bits);
	bs->_bits = NULL;
	bs->_range = 0;
}
int BSTest(BitSet *bs, size_t x)
{
	assert(bs);
	size_t index = x / 32;
	size_t num = x % 32;
	return ((bs->_bits[index] & (1 << num)) == 0) ? 0 : 1;
}
int main()
{
	system("pause");
	return 0;
}
