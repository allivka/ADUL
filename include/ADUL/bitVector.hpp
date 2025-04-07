#ifndef ADUL_BITVECTOR
#define ADUL_BITVECTOR

#include <cstdint>
#include <vector>

namespace adul { namespace atm {


/**
 * @brief Vector of chunks, where in which chunk you can edit every bit
 * @details It's in fact just a basic wrapper for std::vector<ChunkT> with additional functions for bits manipulation \n
 * elements always must be unsigned integers \n 
 * Every Chunk is just an element of source vector "dataChunks" \n 
 * 
 * @tparam ChunkT represents the type of every vector element type
 * @details ChunkT must be unsigned integer type \n 
 * it defines the size of every Chunk
 */
template<typename ChunkT = int8_t> class BitVector{
private:
    std::vector<ChunkT> dataChunks;
    
public:
    void pushChunk();
    
    void pushChunk(const ChunkT& pChunk);
    
    void popChunk();
    
    ChunkT getLastChunk() const;
    
    ChunkT getFirstChunk() const;
    
    void setChunk(const uint64_t& idx, const ChunkT& pChunk);
    
    ChunkT getChunk(const uint64_t& idx) const;
    
    void resetChunk(const uint64_t& idx);
    
    void activateBit(const uint64_t& idx);
    
    void clearBit(const uint64_t& idx);
    
    void setBitValue(const uint64_t& idx, const bool& value);
    
    bool getBit(const uint64_t& idx) const;
    
    void setChunksVector(const std::vector<ChunkT>& pVector);
    
    std::vector<ChunkT> getChunksVector() const;
    
    void clearChunksVector();
    
    bool isEmpty() const;
    
    uint64_t oneChunkSize() const;
    
    uint64_t chunksVectorSize() const;
    
    uint64_t chunksVectorMaxSize() const;
    
    uint64_t chunksVectorCapacity() const;
    
    void chunksVectorReserve(const uint64_t& pCapacity);
    
    void chunksVectorShrinkToFit();
    
    void chunksVectorResize(const uint64_t& pCapacity);
    
    uint64_t bitsSize() const;
    
    uint64_t bitsMaxSize() const;
    
    uint64_t bitsCapacity() const;
    
    void swap(BitVector<ChunkT>& that) noexcept;
    
    bool isEqualTo(const adul::atm::BitVector<ChunkT>& that) const;
    
};

}}

template<typename ChunkT> void swap(adul::atm::BitVector<ChunkT>& first, adul::atm::BitVector<ChunkT>& second) noexcept;

#endif
