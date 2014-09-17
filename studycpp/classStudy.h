#include <iostream>

using namespace std;



/*
Objects that are const, and references or pointers to const objects,
may call only const member functions.
*/

/*
f the member was declared as a const member function, then the definition must also spec-
ify const after the parameter list.
*/


/*
The IO classes are types that cannot be copied
*/

/*
constructors may not be declared as const
When we create a const object of a class type, the object does not
assume its ¡°constness¡± until after the constructor completes the object¡¯s initial-
ization. Thus, constructors can write to const objects during their construction.
*/


/*
if our class does not explicitly define any constructors, the compiler will
implicitly define the default constructor for us

If we define any
constructors, the class will not have a default constructor unless we define that
constructor ourselves.

Remember that objects of
built-in or compound type (such as arrays and pointers) that are defined inside a
block have undefined value when they are default initialized
*/






