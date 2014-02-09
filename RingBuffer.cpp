#include "RingBuffer.h"

#include <string.h>

RingBuffer::RingBuffer(size_t size)
: mSize(size),
  mBuffer(NULL),
  mIndex(0)
{
    // We don't add a trailing '\0' when
    // logging, so make sure the buffer is
    // already full of them.
    mBuffer = (char *) calloc(size, 1);
}


RingBuffer::~RingBuffer()
{
    free(mBuffer);
}

const char *RingBuffer::buffer()
{
    return mBuffer;
}

void RingBuffer::log(char c)
{
    if (mIndex > (mSize - 2)) {
        mIndex = 0;
    }
    
    mBuffer[mIndex] = c;

	if (mIndex < (mSize - 2)) {
	    mBuffer[mIndex + 1] = '|';
	}

	mIndex++;
}

void RingBuffer::log(const char *message)
{
    size_t messageLen = strlen(message);
    for (size_t i = 0; i < messageLen; i++) {
        this->log(message[i]);
    }
}
