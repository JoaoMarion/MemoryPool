#ifndef MEMORY_POOL
#define MEMORY_POOL

#include <memory>
#include <cstring>

template<typename T>
class MemoryPool
{
private:
    //Atributo da classe
    static MemoryPool<T>* HEADER; // Cabeça da lista encadeada (blocos livres)

	//Atributos de cada bloco ( objeto )
    T* Memblock = nullptr;
    MemoryPool<T>* next = nullptr;

public:
    MemoryPool();
    ~MemoryPool();

    static void init(int qntd);                     // Inicializa a pool com qntd blocos
    static MemoryPool<T>* malloc();                 // Aloca um bloco da pool
    static void mdelete(MemoryPool<T>* bloco);      // Libera um bloco de volta para a pool
    static void destroy();                          // Libera toda a memória da pool


    T* get() const {
        return Memblock;
    }
};

#endif // !MEMORY_POOL
