#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<malloc.h>

typedef int KeyType;
typedef int ValueType;

typedef struct HashNode
{
	KeyType _key;
	ValueType _value;
	struct HashNode* _next;
}HashNode;

typedef struct HashTable
{ 
	HashNode** _tables;
	size_t _size;
	size_t _capacity;
}HashTable;

HashNode* BuyHashNode(KeyType key, ValueType value);
size_t HashFunc(KeyType key, size_t capacity);
size_t GetNextPrimeNum(size_t cur);
void HashTableInit(HashTable* ht, size_t capacity);
int HashTableInsert(HashTable* ht, KeyType key, ValueType value);
HashNode* HashTableFind(HashTable* ht, KeyType key);
int HashTableRemove(HashTable* ht, KeyType key);
void HashTableDestory(HashTable* ht);
void HTCheckcapacity(HashTable* ht);