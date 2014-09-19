#include <iostream>

using namespace std;



/*
Objects that are const, and references or pointers to const objects,
may call only const member functions.
*/

/*
if the member was declared as a const member function, then the definition must also spec-
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

/*
When a member is omitted from the constructor initializer list, it is im-
plicitly initialized using the same process as is used by the synthesized default
constructor. In this case, those members are initialized by the in-class initializers.
*/

/*
It is usually best for a constructor to use an in-class initializer if one exists and
gives the member the correct value. On the other hand, if your compiler does not
yet support in-class initializers, then every constructor should explicitly initialize
every member of built-in type.
*/

/*
Constructors should not override in-class initializers except to use a
different initial value. If you can¡¯t use in-class initializers, each con-
structor should explicitly initialize every member of built-in type.
*/


/*
Constructors have no return type
*/


/*
Even though the constructor initializer list is empty, the members of this
object are still initialized before the constructor body is executed.
*/

/*
Members that do not appear in the constructor initializer list are initialized by
the corresponding in-class initializer (if there is one) or are default initialized.
*/



/*
the synthesized versions for copy, assignment, and destruction work
correctly for classes that have vector or string members. When we copy or
assign an object that has a vector member, the vector class takes care of copy-
ing or assigning the elements in that member. When the object is destroyed, the
vector member is destroyed, which in turn destroys the elements in the vector.
Similarly for strings.
*/

/*
in-class initializers must use either the = form of initialization
 or the direct form of initialization using curly braces .
*/
 
/*
It is important to understand that a friend declaration affects access but is not a
declaration in an ordinary sense.
*/

/*
Members are initialized in the order in which they appear in the class defini-
tion: The first member is initialized first, then the next, and so on. The order in
which initializers appear in the constructor initializer list does not change the or-
der of initialization.
*/

/*
It is a good idea to write constructor initializers in the same order as the
members are declared. Moreover, when possible, avoid using mem-
bers to initialize other members.
*/

/*
A constructor that supplies default arguments for all its parameters also
defines the default constructor.
*/

/*
delegate constructor
*/

/*
Only One Class-Type Conversion Is Allowed
*/

/*
We can prevent the use of a constructor in a context that requires an implicit con-
version by declaring the constructor as explicit
*/

/*
The explicit keyword is meaningful only on constructors that can be called
with a single argument.
*/

/*
Constructors that require more arguments are not used to
perform an implicit conversion, so there is no need to designate such constructors
as explicit. The explicit keyword is used only on the constructor declaration
inside the class. It is not repeated on a definition made outside the class body
*/

/*
explicit Constructors Can Be Used Only for Direct Initialization
*/

/*
One context in which implicit conversions happen is when we use the copy form
of initialization (with an =) . We cannot use an explicit constructor
with this form of initialization; we must use direct initialization.
*/

/*
When a constructor is declared explicit, it can be used only with the
direct form of initialization. Moroever, the compiler will
not use this constructor in an automatic conversion.

*/

/*
The string constructor that takes a single parameter of type const char*
 is not explicit.
 The vector constructor that takes a size is explicit.
*/

/*
Although constructors can¡¯t be const , constructors in a literal class
can be constexpr functions. Indeed, a literal class must provide
at least one constexpr constructor.
*/

/*
a static data member can have incomplete type .
In particular, a static data member can have the same type as the class type of
which it is a member. A nonstatic data member is restricted to being declared
as a pointer or a reference to an object of its class:
*/

/*
Another difference between static and ordinary members is that we can use a
static member as a default argument
*/