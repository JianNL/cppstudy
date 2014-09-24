#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
Algorithms never change the size of the underlying container.
Algorithms may change the values of the elements stored in the container, and they
may move elements around within the container. They do not, however, ever add or
remove elements directly.
*/

/*
Note that we explicitly create a string as the third parameter.Passing the
empty string as a string literal would be a compile - time error :
// error: no + on const char*
string sum = accumulate(v.cbegin(), v.cend(), "");
*/

/*
Algorithms that write to a destination iterator assume the destination is
large enough to hold the number of elements being written.
*/


void elimDups(vector<string> &words)
{
	// sort words alphabetically so we can find the duplicates
	sort(words.begin(), words.end());
	// unique reorders the input range so that each word appears once in the
	// front portion of the range and returns an iterator one past the unique range
	auto end_unique = unique(words.begin(), words.end());
	// erase uses a vector operation to remove the nonunique elements
	words.erase(end_unique, words.end());
}

/*
lambda
The capture list is used for local nonstatic variables only; lambdas can
use local statics and variables declared outside the function directly.

we use the capture list only for (nonstatic)
variables defined in the surrounding function. A lambda can use names that are
defined outside the function in which the lambda appears. I
*/

/*
When we define a lambda, the compiler generates a new (unnamed) class type that
corresponds to that lambda. We¡¯ll see how these classes are generated in ¡ì 14.8.1
. For now, what¡¯s useful to understand is that when we pass a lambda to a
function, we are defining both a new type and an object of that type: The argument
is an unnamed object of this compiler-generated class type. Similarly, when we use
auto to define a variable initialized by a lambda, we are defining an object of the
type generated from that lambda.
By default, the class generated from a lambda contains a data member corre-
sponding to the variables captured by the lambda. Like the data members of any
class, the data members of a lambda are initialized when a lambda object is created.
*/

/*
Similar to parameter passing, we can capture variables by value or by reference.
*/

/*
Unlike parameters, the value of
a captured variable is copied when the lambda is created, not when it is called:
*/

/*
If we capture a variable by reference, we must be certain
that the referenced object exists at the time the lambda is executed. The variables
captured by a lambda are local variables. These variables cease to exist once the
function completes. If it is possible for a lambda to be executed after the function
finishes, the local variables to which the capture refers no longer exist.
*/

/*
If the function returns a lambda, then¡ªfor the same
reasons that a function must not return a reference to a local variable¡ªthat lambda
must not contain reference captures.
*/

/*
The & tells the compiler to capture by reference, and the = says
the values are captured by value
// sz implicitly captured by value
wc = find_if(words.begin(), words.end(),
[=](const string &s)
{ return s.size() >= sz; });
*/

/*
When we mix implicit and explicit captures, the first item in the capture list must
be an & or =. That symbol sets the default capture mode as by reference or by
value, respectively.
*/

/*
When we mix implicit and explicit captures, the explicitly captured variables
must use the alternate form. That is, if the implicit capture is by reference (using &),
then the explicitly named variables must be captured by value; hence their names
may not be preceded by an &. Alternatively, if the implicit capture is by value
(using =), then the explicitly named variables must be preceded by an & to indicate
that they are to be captured by reference.
*/

/*
By default, a lambda may not change the value of a variable that it copies by value.
If we want to be able to change the value of a captured variable, we must follow
the parameter list with the keyword mutable. Lambdas that are mutable may not
omit the parameter list
*/

/*
Whether a variable captured by reference can be changed (as usual) depends
only on whether that reference refers to a const or nonconst type
*/


/*
The transform function takes three iterators and a callable. The first two iterators
denote an input sequence and the third is a destination. The algorithm calls the
given callable on each element in the input sequence and writes the result to the
destination. As in this call, the destination iterator can be the same as the iterator
denoting the start of the input. When the input iterator and the destination iterator
are the same, transform replaces each element in the input range with the result
of calling the callable on that element.
*/


/*
The bind function can be thought of as a general-purpose function adaptor 
. It takes a callable object and generates a new callable that ¡°adapts¡± the
parameter list of the original object.
*/

/*
The _n names are defined in a namespace named placeholders. That name-
space is itself defined inside the std namespace . To use these names,
we must supply the names of both namespaces.
*/


/*
auto g = bind(f, a, b, _2, c, _1);
generates a new callable that takes two arguments, represented by the placeholders
_2 and _1. The new callable will pass its own arguments as the third and fifth
arguments to f. The first, second, and fourth arguments to f are bound to the
given values, a, b, and c, respectively.
The arguments to g are bound positionally to the placeholders. That is, the first
argument to g is bound to _1, and the second argument is bound to _2. Thus,
when we call g, the first argument to g will be passed as the last argument to f;
the second argument to g will be passed as f¡¯s third argument. In effect, this call
to bind maps
g(_1, _2)
to
f(a, b, _2, c, _1)
*/


/*
because bind copies its arguments and we cannot copy an ostream. If we want
to pass an object to bind without copying it, we must use the library ref function:
for_each(words.begin(), words.end(),
bind(print, ref(os), _1, ¡¯ ¡¯));

There is also a cref function that generates a class that holds a
reference to const
Like bind, the ref and cref functions are defined in the
functional header.
*/

void testOfInsertIterator()
{
	cout << "testOfInsertIterator" << endl;
	vector<int> vec;
	auto it = inserter(vec,vec.end());
	it = 1;
	for (auto e:vec)
	{
		cout << e << endl;
	}
}