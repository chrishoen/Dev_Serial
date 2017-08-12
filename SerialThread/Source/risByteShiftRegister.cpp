/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "risByteShiftRegister.h"

namespace Ris
{

//******************************************************************************
//******************************************************************************
//******************************************************************************

ByteShiftRegister::ByteShiftRegister()
{
   reset();
}

//******************************************************************************

ByteShiftRegister::~ByteShiftRegister()
{
   finalize();
}

//******************************************************************************

void ByteShiftRegister::reset()
{
   mArray = 0;
   mSize  = 0;
   mCount = 0;
   mIndex = 0;
   mK     = 0;
}

//******************************************************************************

void ByteShiftRegister::initialize(int aSize)
{
   finalize();
   reset();
   mArray = new double[aSize];
   mSize  = aSize;
   mCount = 0;
   mIndex = mSize-1;
   mK = 0;
}

//******************************************************************************

void ByteShiftRegister::reinitialize()
{
   mCount = 0;
   mIndex = mSize-1;
   mK = 0;
}

//******************************************************************************

void ByteShiftRegister::finalize()
{
   if (mArray)
   {
      delete mArray;
      mArray = 0;
   }
}

//******************************************************************************

void ByteShiftRegister::shiftRight(double aX)
{
   // Adjust index to the right
   mIndex = dsp_index_add(mIndex, 1, mSize);

   // Add new value to array
   mX=aX;
   mArray[mIndex]=aX;

   // Calculate number of elements
   if (mCount==mSize)
   {
      mValid=true;
   }
   else
   {
      mCount++;
      mValid=false;
   }
   
   // Update
   mK++;
}

//******************************************************************************

void ByteShiftRegister::setLeft(double aX)
{
   // Set array left end value
   mArray[mIndex]=aX;
}

//******************************************************************************

double ByteShiftRegister::get(int aOffset)
{
   // Guard
   if (!mValid) return 0.0;

   // Get index
   int tGetIndex = dsp_index_sub(mIndex, aOffset, mSize);

   // Return array value at index
   return mArray[tGetIndex];
}

//******************************************************************************

double ByteShiftRegister::getLeft()
{
   // Guard
   if (!mValid) return 0.0;

   // Return array value at index
   return mArray[mIndex];
}

//******************************************************************************

double ByteShiftRegister::getRight()
{
   // Guard
   if (!mValid) return 0.0;

   // Get index of right end
   int tGetIndex = dsp_index_sub(mIndex, (mSize - 1), mSize);

   // Return array value at index
   return mArray[tGetIndex];
}


//******************************************************************************

void ByteShiftRegister::show()
{
   printf("ByteShiftRegister:                   %3d %8.3f $$",mIndex,mX);
   for (int j=0;j<mSize;j++)
   {
      printf("%8.3f ", get(j));
   }
   printf("\n");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace

