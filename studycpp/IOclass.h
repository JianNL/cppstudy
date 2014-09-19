#include <iostream>

using namespace std;


/*
No Copy or Assign for IO Objects
*/

/*
Because we can¡¯t copy the IO types, we cannot have a parameter or return type
that is one of the stream types . Functions that do IO typically pass
and return the stream through references. Reading or writing an IO object changes
its state, so the reference must not be const.
*/

/*
An output stream might be tied to another stream. In this case, the output
stream is flushed whenever the stream to which it is tied is read or written.
By default, cin and cerr are both tied to cout. Hence, reading cin or
writing to cerr flushes the buffer in cout.
*/