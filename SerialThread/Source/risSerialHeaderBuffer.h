#pragma once
/*==============================================================================
Serial header buffer
=============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Ris
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class encalsulates a buffer of bytes that is used to detect serial 
// communications message headers. It is a shift register of bytes, it shifts
// up. The top element is the oldest and the bottom element is the most recent.

class SerialHeaderBuffer
{
public:
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   double  mX;         // Input value
   int     mSize;      // Array size
   int     mIndex;     // Index of left end
   int     mCount;     // Number of occupied elements
   int     mK;         // Number of shifts
   bool    mValid;     // Valid
   double* mArray;     // Value array

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Infrastucture.

   // Constructors.
   SerialHeaderBuffer();
  ~SerialHeaderBuffer();
   void reset(); 

   // Allocate memory and initialize.
   void initialize(int aSize);
   // Initialize, but reuse memory.
   void reinitialize();
   // Deallocate memory.
   void finalize();
   // Show.
   void show();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

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

