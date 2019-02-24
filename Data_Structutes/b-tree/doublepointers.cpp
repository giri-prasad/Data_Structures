#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var;
   int  *ptr;
   int  **pptr;

   var = 3000;

   // take the address of var
   ptr = &var;

   // take the address of ptr using address of operator &
   pptr = &ptr;

   // take the value using pptr
   cout << "Value of var :" << var << endl;
   cout << "Value available at *ptr :" << *ptr << endl;
   cout << "Value available at **pptr :" << **pptr << endl;
   cout << "Value available at ptr :" << ptr << endl;
   cout << "Value available at *pptr :" << *pptr << endl;
   cout << "Value available at pptr :" << pptr << endl;
   return 0;
}
/*
#include <iostream>
using namespace std;
 
int main ()
{
   // an array with 5 elements.
   double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double *p;

   p = balance;
 
   // output each array element's value 
   cout << "Array values using pointer " << endl; 
   for ( int i = 0; i < 5; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }

   cout << "Array values using balance as address " << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "*(balance + " << i << ") : ";
       cout << *(balance + i) << endl;
   }
 
   return 0;
}
*/