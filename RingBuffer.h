#include <stdlib.h>

/**
 * Add a line like:
 * 
 * #define RING_BUFFER_FIXED_SIZE 1024
 * 
 * here if you want to use a static buffer
 * rather than one created on the heap.
 */

#define RING_BUFFER_FIXED_SIZE 1024

class RingBuffer
{
public:
#if defined(RING_BUFFER_FIXED_SIZE)
    RingBuffer();
#else
    RingBuffer(size_t size); //< The size, in bytes, of the buffer.
    ~RingBuffer();
#endif
    
    /// The bare buffer pointer. Useful so that you can
    /// register it as a Spark variable. Note that you will
    /// need to cast it to a void* to keep Spark.variable() happy:
    /// see the example at the top of this file.
    const char * buffer();
    
    /// Log a single character to the buffer.
    void log(char c);
    
    /// Log a null-terminated character sequence to the buffer.
    void log(const char *message);

private:
#if defined(RING_BUFFER_FIXED_SIZE)
    char mBuffer[RING_BUFFER_FIXED_SIZE];
#else
    char *mBuffer;
#endif
    const size_t mSize;
    size_t mIndex;
};
