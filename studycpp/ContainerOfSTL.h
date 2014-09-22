#include <iostream>

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
*/