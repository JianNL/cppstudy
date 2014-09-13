/*
In C++, an lvalue expression yields an
object or a function. However, some lvalues, such as const objects, may not be
the left-hand operand of an assignment. Moreover, some expressions yield objects
but return them as rvalues, not lvalues. Roughly speaking, when we use an object
as an rvalue, we use the object¡¯s value (its contents). When we use an object as an
lvalue, we use the object¡¯s identity (its location in memory).
*/