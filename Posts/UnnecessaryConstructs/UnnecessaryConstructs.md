
##  1. A project shall not contain unreachable code. 
Example:
```cpp
int16_t with_unreach ( int16_t para )
int16_t local;
local = 0;
switch ( para )
{
local = para; // unreachable – Non-compliant
case 1:
{
break;
}
default:
{
break;
}
}
return para;
para++; // unreachable – Non-compliant
}
```
##  2. A project shall not contain infeasible paths.
```cpp
void infeas ( uint8_t para, uint8_t outp )
// The condition below will always be true hence the path
// for the false condition is infeasible. Non-compliant.
if ( para >= 0U )
outp = 1U;
{
}
// The following if statement combines with the if
// statement above to give four paths. One from
// the first condition is already infeasible and
// the condition below combined with assignment above
// makes the false branch infeasible. There is therefore
// only one feasible path through this code.
if ( outp == 1U )
{
outp = 0U;
}
}
enum ec { RED, BLUE, GREEN } col;
if ( col <= GREEN ) // Non-compliant – always true
{
// Will always get here
}
else
{
// Will never get here
}
// The following ifs exhibit similar behaviour.
// Note that u16a is a 16-bit unsigned integer
// and s8a is an 8-bit signed integer.
if ( u16a < 0U ) // Non-compliant – u16a is always >= 0
if ( u16a <= 0xffffU ) // Non-compliant – always true
if ( s8a < 130 )// Non-compliant – always true
if ( ( s8a < 10 ) && ( s8a > 20 ) )// Non-compliant – always false
if ( ( s8a < 10 ) || ( s8a > 5 ) ) // Non-compliant – always true
// Nested conditions can also cause problems
if ( s8a > 10 )
{// Non-compliant, unless s8a volatile
if ( s8a > 5 ) {
// Will always get here.
}

}
````
##  3. A project shall not contain unused variables.
```cpp
class C
{
extern void usefn ( int16_t a, int16_t b );
...
};
C c; // Non-compliant - unused
void withunusedvar ( void )
{
int16_t unusedvar; struct s_tag
// Non-compliant – unused
{
signed int a : 3;
signed int pad : 1; signed int b : 2;
} s_var;
s_var.a = 0;
s_var.b = 0;
usefn ( s_var.a, s_var.b );
// Non-compliant – should be unnamed
}
```
##  4. A project shall not contain non-volatile POD variables having only one use.
```cpp
const int16_t x = 19; const int16_t y = 21; void usedonlyonce ( void )
{
// Compliant
// Non-compliant
int16_t once_1 = 42; int16_t once_2;
once_2 = x ; // Non-compliant
// Non-compliant
}
```
##  5. A project shall not contain unused type declarations.
```cpp
int16_t unusedtype()
typedef int16_t local_Type; // Non-compliant
return 67;
}
```
##  6. A project shall not contain instances of non-volatile variables being given values that are never subsequently used.
```cpp
int16_t critical ( int16_t i, int16_t j ){
int16_t result = 0;
int16_t k = ( 3 * i ) + ( j * j );
// Should k be checked here?
if ( f2 ( ) )
{
// k will only be tested here if f2 returns true
// Initialization of k could be moved here
if ( k > 0 )
{
throw ( 42 );
}
}
// Non-compliant – value of k not used if f2 ( ) returns false
return ( result );
}
void unusedvalue ( int16_t arr[ 20 ] )
{
int16_t j;
j = 2;
{
for ( int16_t i = 1; i < 10; i++ )
arr[ i ] = arr[ j ];
j++; // Non-compliant – the value assigned to j
} // on the final loop is never used.
}
void nounusedvalue ( int16_t arr[ 20 ] )
{
for ( int16_t i = 1; i < 10; i++ )
{
arr[ i ] = arr[ i + 2 ];
}
}
```
##  7. The value returned by a function having a non-void return type that is not an overloaded operator shall always be used.
##  8. All functions with void return type shall have external side effect(s).
##  9. There shall be no dead code.
##  10. Every defined function shall be called at least once.
##  11. There shall be no unused parameters (named or unnamed) in non-virtual functions.
##  12. There shall be no unused parameters (named or unnamed) in the set of parameters for a virtual function and all the functions that override it.


