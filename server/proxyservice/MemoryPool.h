#pragma once

//�ڴ�ع�����Ҫ�ṩ��Ϣ�Ĵ����á�
//���������ڴ�Ĵ�С���ּ������Σ�������Ӧ���ڴ�Ͱ
//�ɲο���ֱ��ʹ�ÿ�Դ�⡣ https://github.com/emeryberger/Hoard

class MemoryPool
{
public:
	char* require(size_t size);
	void release(char* block);
protected:
private:

};