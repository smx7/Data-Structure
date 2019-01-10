#define _CRT_SECURE_NO_WARNINGS 1
#include"Hash.h"
void HashTableInit(HashTable* ht, size_t capacity)
{
	assert(ht);
	ht->_tables = (HashNode**)malloc(sizeof(HashNode*)*capacity);
	assert(ht->_tables);
	ht->_capacity = capacity;
	ht->_size = 0;
	for (size_t i = 0; i < capacity; ++i)
	{
		ht->_tables[i] = NULL;
	}
}
int HashTableInsert(HashTable* ht, KeyType key, ValueType value)
{
	assert(ht);
	HTCheckcapacity(ht);
	size_t index = HashFunc(key, ht->_capacity);
	HashNode* cur = ht->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			return -1;
		}
		cur = cur->_next;
	}
	HashNode* node = BuyHashNode(key, value);
	//头插
	node->_next = ht->_tables[index];
	ht->_tables[index] = node;
	ht->_size++;
	return 0;
}
HashNode* BuyHashNode(KeyType key, ValueType value)
{
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	assert(node);
	node->_key = key;
	node->_value = value;
	node->_next = NULL;
	return node;
}
size_t HashFunc(KeyType key, size_t capacity)
{
	return key%capacity;
}
void HTCheckcapacity(HashTable* ht)
{
	assert(ht);
	if (ht->_size == ht->_capacity)
	{
		HashTable newht;
		HashTableInit(&newht, GetNextPrimeNum(ht->_capacity));
		for (size_t i = 0; i < ht->_capacity; ++i)
		{
			HashNode* cur = ht->_tables[i];
			while (cur)
			{
				HashNode* next = cur->_next;
				size_t index = HashFunc(cur->_key, newht._capacity);
				cur->_next = newht._tables[index];
				newht._tables[index] = cur;
				cur = next;
			}
			ht->_tables[i] = NULL;
		}
		size_t size = ht->_size;
		HashTableDestory(ht);
		ht->_tables = newht._tables;
		ht->_capacity = newht._capacity;
		ht->_size = size;
	}
}
void HashTableDestory(HashTable* ht)
{
	for (size_t i = 0; i < ht->_capacity; ++i)
	{
		HashNode* cur = ht->_tables[i];
		while (cur)
		{
			HashNode* next = cur->_next;
			free(cur);
			cur = next;
		}
	}
	free(ht->_tables);
	ht->_capacity = 0;
	ht->_size = 0;
	ht->_tables = NULL;
}
void HTTablePrint(HashTable* ht)
{
	assert(ht);
	for (size_t i = 0; i < ht->_capacity; ++i)
	{
		printf("table[%d]->", i);
		HashNode* cur = ht->_tables[i];
		while (cur)
		{
			printf("%d->", cur->_key);
			cur = cur->_next;
		}
		printf("\n");
	}
}
size_t GetNextPrimeNum(size_t cur)//质数表，给增容提供最佳选择容量大小
{
	const int _PrimeSize = 28;
	static const unsigned long _PrimeList[28] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	for (size_t i = 0; i < 28; ++i)
	{
		if (_PrimeList[i]>cur)
			return _PrimeList[i];
	}
}

HashNode* HashTableFind(HashTable* ht, KeyType key)
{
	assert(ht);
	size_t index = HashFunc(key,ht->_capacity);
	HashNode* cur = ht->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
int HashTableRemove(HashTable* ht, KeyType key)
{
	assert(ht);
	size_t index = HashFunc(key, ht->_capacity);
	HashNode* cur = ht->_tables[index];
	if (cur->_key == key)
	{
		ht->_tables[index] = cur->_next;
		free(cur);
		return 0;
	}
	HashNode* prev = cur;
	cur = cur->_next;
	while (cur)
	{
		if (cur->_key == key)
		{
			prev->_next = cur->_next;
			free(cur);
			return 0;
		}
		prev = cur;
		cur = cur->_next;
	}
	return -1;
}
int main()
{
	HashTable ht;
	HashTableInit(&ht,11);
	HashTableInsert(&ht, 11, 11);
	HashTableInsert(&ht, 68, 68);
	HashTableInsert(&ht, 57, 57);
	HashTableInsert(&ht, 25, 25);
	HashTableInsert(&ht, 14, 14);
	HashTableInsert(&ht, 36, 36);
	HashTableInsert(&ht, 37, 37);
	HashTableInsert(&ht, 49, 49);
	HTTablePrint(&ht);
	printf("\n\n");
	HashTableRemove(&ht, 11);
	HashTableRemove(&ht, 14);
	HTTablePrint(&ht);
	system("pause");
	return 0;
}
