#include "MemoryPool.h"

template<typename T>
MemoryPool<T>* MemoryPool<T>::HEADER = nullptr;

template<typename T>
MemoryPool<T>::MemoryPool()
{
    Memblock = nullptr;
    next = nullptr;
}

template<typename T>
MemoryPool<T>::~MemoryPool()
{
    delete Memblock;
}

template<typename T>
void MemoryPool<T>::init(int qntd)
{
    destroy();

    HEADER = new MemoryPool<T>();
    MemoryPool<T>* atual = HEADER;
    atual->Memblock = new T();

    for (int i = 1; i < qntd; i++)
    {
        atual->next = new MemoryPool<T>();
        atual = atual->next;
        atual->Memblock = new T();
    }
    atual->next = nullptr;
}

template<typename T>
MemoryPool<T>* MemoryPool<T>::malloc()
{
    if (HEADER == nullptr)
        return nullptr;

    MemoryPool<T>* bloco = HEADER;
    HEADER = HEADER->next;
    bloco->next = nullptr; 
    return bloco;
}

template<typename T>
void MemoryPool<T>::mdelete(MemoryPool<T>* bloco)
{
    if (!bloco || !bloco->Memblock)
        return;

    
    *(bloco->Memblock) = T();

    bloco->next = HEADER;
    HEADER = bloco;
}

template<typename T>
void MemoryPool<T>::destroy()
{
    MemoryPool<T>* atual = HEADER;
    while (atual != nullptr)
    {
        MemoryPool<T>* temp = atual->next;
        delete atual->Memblock;
        delete atual;
        atual = temp;
    }
    HEADER = nullptr;
}

template class MemoryPool<int>;
