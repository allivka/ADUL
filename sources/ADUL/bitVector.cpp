#include "../../include/ADUL/bitVector.hpp"

namespace adul{

template<typename ChunkT> void BitVector<ChunkT>::pushChunk() {
    dataChunks.emplace_back();
}

template<typename ChunkT> void BitVector<ChunkT>::pushChunk(const ChunkT& pChunk) {
    dataChunks.emplace_back(pChunk);
}

template<typename ChunkT> void BitVector<ChunkT>::popChunk() {
    dataChunks.pop_back();
}

template<typename ChunkT> ChunkT BitVector<ChunkT>::getLastChunk() const {
    return dataChunks.back();
}

template<typename ChunkT> ChunkT BitVector<ChunkT>::getFirstChunk() const {
    return dataChunks.front();
}

template<typename ChunkT> void BitVector<ChunkT>::setChunk(const uint64_t& idx, const ChunkT& pChunk) {
    dataChunks.at(idx) = pChunk;
}

template<typename ChunkT> ChunkT BitVector<ChunkT>::getChunk(const uint64_t& idx) const {
    return dataChunks.at();
}

template<typename ChunkT> void BitVector<ChunkT>::resetChunk(const uint64_t& idx) {
    dataChunks.at(idx) = static_cast<ChunkT>(0);
}

template<typename ChunkT> void BitVector<ChunkT>::activateBit(const uint64_t& idx) {
    dataChunks.at(idx / sizeof(ChunkT)) |= static_cast<ChunkT>(1) << (idx + 1 % sizeof(ChunkT));
}

template<typename ChunkT> void BitVector<ChunkT>::clearBit(const uint64_t& idx) {
    dataChunks.at(idx / sizeof(ChunkT)) |= static_cast<ChunkT>(1) << (idx + 1 % sizeof(ChunkT));
}

template<typename ChunkT> void BitVector<ChunkT>::setBitValue(const uint64_t& idx, const bool& value) {
    if(value) {
        this->activateBit(idx);
    } else {
        this->clearBit(idx);
    }
}

template<typename ChunkT> bool BitVector<ChunkT>::getBit(const uint64_t& idx) const {
    return static_cast<bool>(dataChunks.at(idx / sizeof(ChunkT)) & (static_cast<ChunkT>(1) << (idx + 1 % sizeof(ChunkT))));
}

template<typename ChunkT> void BitVector<ChunkT>::setChunksVector(const std::vector<ChunkT>& pVector) {
    dataChunks = pVector;
}

template<typename ChunkT> std::vector<ChunkT> BitVector<ChunkT>::getChunksVector() const {
    return dataChunks;
}

template<typename ChunkT> void BitVector<ChunkT>::clearChunksVector() {
    dataChunks.clear();
}

template<typename ChunkT> bool BitVector<ChunkT>::isEmpty() const{
    return dataChunks.empty();
}

template<typename ChunkT> uint64_t BitVector<ChunkT>::oneChunkSize() const{
    return sizeof(ChunkT);
}

template<typename ChunkT> uint64_t BitVector<ChunkT>::chunksVectorSize() const{
    return dataChunks.size();
}

template<typename ChunkT> uint64_t BitVector<ChunkT>::chunksVectorMaxSize() const{
    return dataChunks.max_size();
}

template<typename ChunkT> uint64_t BitVector<ChunkT>::chunksVectorCapacity() const{
    return dataChunks.capacity();
}

template<typename ChunkT> void BitVector<ChunkT>::chunksVectorReserve(const uint64_t& pCapacity) {
    dataChunks.reserve(pCapacity);
}

template<typename ChunkT> void BitVector<ChunkT>::chunksVectorShrinkToFit() {
    dataChunks.shrink_to_fit();
}

template<typename ChunkT> void BitVector<ChunkT>::chunksVectorResize(const uint64_t& pCapacity) {
    dataChunks.resize(pCapacity);
}

template<typename ChunkT> uint64_t BitVector<ChunkT>::bitsSize() const{
    return dataChunks.size() * sizeof(ChunkT);
}

template<typename ChunkT> uint64_t BitVector<ChunkT>::bitsMaxSize() const{
    return dataChunks.max_size() * sizeof(ChunkT);
}

template<typename ChunkT> uint64_t BitVector<ChunkT>::bitsCapacity() const{
    return dataChunks.capacity() * sizeof(ChunkT);
}

template<typename ChunkT> void BitVector<ChunkT>::swap(BitVector<ChunkT>& that) {
    std::swap(dataChunks, that.dataChunks);
}

} //namespace adul

template<typename ChunkT> void swap(adul::BitVector<ChunkT>& first, adul::BitVector<ChunkT>& second) {
    first.swap(second);
}