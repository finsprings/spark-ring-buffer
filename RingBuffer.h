#include <stdlib.h>

class RingBuffer
{
public:
    RingBuffer(size_t size); //< The size, in bytes, of the buffer.
    ~RingBuffer();
    
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
    const size_t mSize;
    char *mBuffer;
    size_t mIndex;
};
