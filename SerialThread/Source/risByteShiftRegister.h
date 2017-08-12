#pragma once
/*==============================================================================
Byte shifter register
=============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Ris
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Shift register of doubles, it shifts to the right, the left end element
// is the most recent and the right end element is the latest.

class ByteShiftRegister
{
public:
   //---------------------------------------------------------------------------
   //---------------------------------------------------------------------------
   //---------------------------------------------------------------------------
   // Members.

   double  mX;         // Input value
   int     mSize;      // Array size
   int     mIndex;     // Index of left end
   int     mCount;     // Number of occupied elements
   int     mK;         // Number of shifts
   bool    mValid;     // Valid
   double* mArray;     // Value array

   //---------------------------------------------------------------------------
   //---------------------------------------------------------------------------
   //---------------------------------------------------------------------------
   // Methods.

   // Constructors and initialization.
   ByteShiftRegister();
  ~ByteShiftRegister();
   void reset(); 

   // Allocate memory and initialize.
   void initialize(int aSize);
   // Initialize, but reuse memory.
   void reinitialize();
   // Deallocate memory.
   void finalize();
   // Show.
   void show();

   // Shift right and put input value at the left end.
   void shiftRight(double aX);

   // Set the left end value
   void setLeft(double aX);

   // Get value
   double get(int    aIndex);
   double getLeft();
   double getRight();

};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace

