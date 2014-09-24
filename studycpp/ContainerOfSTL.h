#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/*
When we initialize a container as a copy of another container, the con-
tainer type and element type of both containers must be identical.
*/

/*
The constructors that take a size are valid only for sequential containers;
they are not supported for the associative containers
*/

/*
Just as the size of a built-in array is part of its type, the size of a library array is
part of its type. When we define an array, in addition to specifying the element
type, we also specify the container size:
*/

/*
When we use an object to initialize a container, or insert an object into a container, a
copy of that object¡¯s value is placed in the container, not the object itself. Just as when
we pass an object to a nonreference parameter, there is no relationship
between the element in the container and the object from which that value originated.
Subsequent changes to the element in the container have no effect on the original
object, and vice versa.
*/

/*
insert:element(s) are inserted before the position denoted by the iterator.
Returns an iterator to the first element inserted
*/

/*
c.erase(p)
Removes the element denoted by the iterator p and returns an iterator to
the element after the one deleted or the off-the-end iterator if p denotes
the last element. Undefined if p is the off-the-end iterator.

c.erase(b,e) 
Removes the range of elements denoted by the iterators b and e. Returns
an iterator to the element after the last one that was deleted, or an
off-the-end iterator if e is itself an off-the-end iterator.
*/

/*
Avoid Storing the Iterator Returned from end
Don¡¯t cache the iterator returned from end() in loops that insert or
delete elements in a deque, string, or vector.
*/

/*
A call to reserve changes the capacity of the vector only if the requested
space exceeds the current capacity.
If the requested size is less than or equal to the existing capacity, reserve does
nothing. In particular, calling reserve with a size smaller than capacity does
not cause the container to give back memory. Thus, after calling reserve, the
capacity will be greater than or equal to the argument passed to reserve.
*/

/*
Under the new library, we can call shrink_to_fit to ask a deque, vector,
or string to return unneeded memory. This function indicates that we no longer
need any excess capacity. However, the implementation is free to ignore this re-
quest. There is no guarantee that a call to shrink_to_fit will return memory.
*/

