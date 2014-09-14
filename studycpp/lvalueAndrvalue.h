/*
In C++, an lvalue expression yields an
object or a function. However, some lvalues, such as const objects, may not be
the left-hand operand of an assignment. Moreover, some expressions yield objects
but return them as rvalues, not lvalues. Roughly speaking, when we use an object
as an rvalue, we use the object¡¯s value (its contents). When we use an object as an
lvalue, we use the object¡¯s identity (its location in memory).
*/

/*
Assignment requires a (nonconst) lvalue as its left-hand operand and yields
its left-hand operand as an lvalue.
 The address-of operator  requires an lvalue operand and re-
turns a pointer to its operand as an rvalue.
 The built-in dereference and subscript operators  and the iterator dereference and string and vector subscript oper-
ators  all yield lvalues.
 The built-in and iterator increment and decrement operators  require lvalue operands and the prefix versions (which
are the ones we have used so far) also yield lvalues.
*/