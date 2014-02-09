# Spark Ring Buffer

Simple ring buffer class.

I find it handy for logging to when debugging Spark Core (http://spark.io) apps, but it could be used for other purposes too.

The sample Spark Core sketch below regists the ring buffer as a Spark variable called _log_. This variable can be accessed from Spark Cloud:

```bash
 curl "https://api.spark.io/v1/devices/DEVICE_ID/log?access_token=ACCESS_TOKEN"
```

The ring buffer will include a pipe character (_|_) at the end of the last message. The ring buffer will wrap back to the beginning of the buffer when it reaches the size it was created with, so you can continue to send it messages without worrying about how many previous messages you've given it: the last _size_ bytes will be kept.

## Sketch
```C++
#include "RingBuffer.h"

RingBuffer ringBuffer(32);

void setup()
{
    // We have to cast to void* here because Spark.variable() takes
    // a void* as its second parameter.
    Spark.variable("log", (void*) ringBuffer.buffer(), STRING);
    
    ringBuffer.log("Setup Complete.");
    // Buffer will contain: "Setup Complete.|"
}

void loop()
{
    ringBuffer.log("Something happened.");
    // First time we get here, buffer will contain: "ed.|p Complete.Something happen"
}
```
