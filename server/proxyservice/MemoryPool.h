#pragma once

//�ڴ�ع�����Ҫ�ṩ��Ϣ�Ĵ����á�
//���������ڴ�Ĵ�С���ּ������Σ�������Ӧ���ڴ�Ͱ
//�ɲο���ֱ��ʹ�ÿ�Դ�⡣ https://github.com/emeryberger/Hoard
/*
*-------------------*
|					|
|					|        *----------*		 *----------*
|	  memorypool	|------->|memorypage|------->|memorypage|-------> ... + sizeof(int) = 4 byte
|					|		 |----------|		 |----------|
|					|		 |		    |		 |		    |
*-------------------*		 |		    |		 |		    |
							 | 8 - byte |		 | 12 - byte|
	*--------------*		 |		    |		 |		    |
	|			   |		 |		    |		 |		    |
	|     block	   |<------- |		    |		 |		    |
	|			   |		 |		    |		 |		    |
	*--------------*		 *----------*		 *----------*
*/
#define MEMORY_POLL_SIZE 4096

class MemoryPage;
class MemoryBlock;

typedef struct Pool_Info
{
	MemoryPage* _page;
	int _page_num;
	int _page_size;
}poll_info;

typedef struct Page_Info
{
	struct Page_Info* _next_page;
	MemoryBlock* _block;
	int _block_size;
}page_info;

typedef struct Block_Info
{
	struct Block_Info* _next_block;
	char* _data;
	bool used;
}block_info;

class MemoryPool
{
public:
	int init_memory_poll(int size);

	char* require(int size);

	void release(int size,char* block);

protected:
private:
	int _size;
	char* _head;
	char* _free;
	page_info* _page;
};

class MemoryPage
{

};

class MemoryBlock
{

};
