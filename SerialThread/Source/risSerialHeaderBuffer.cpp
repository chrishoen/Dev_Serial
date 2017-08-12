/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "risSerialHeaderBuffer.h"

namespace Ris
{

//******************************************************************************
//******************************************************************************
//******************************************************************************

SerialHeaderBuffer::SerialHeaderBuffer()
{
   reset();
}

SerialHeaderBuffer::~SerialHeaderBuffer()
{
   finalize();
}

void SerialHeaderBuffer::reset()
{
   mArray = 0;
   mSize  = 0;
   mCount = 0;
   mIndex = 0;
   mK     = 0;
}

void SerialHeaderBuffer::initialize(int aSize)
{
   finalize();
   reset();
   mArray = new double[aSize];
   mSize  = aSize;
   mCount = 0;
   mIndex = mSize-1;
   mK = 0;
}

void SerialHeaderBuffer::reinitialize()
{
   mCount = 0;
   mIndex = mSize-1;
   mK = 0;
}

void SerialHeaderBuffer::finalize()
{
   if (mArray)
   {
      delete mArray;
      mArray = 0;
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void SerialHeaderBuffer::shiftRight(double aX)
{
   // Adjust index to the right
   mIndex = my_index_add(mIndex, 1, mSize);

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
//******************************************************************************
//******************************************************************************

void SerialHeaderBuffer::setLeft(double aX)
{
   // Set array left end value
   mArray[mIndex]=aX;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

double SerialHeaderBuffer::get(int aOffset)
{
   // Guard
   if (!mValid) return 0.0;

   // Get index
   int tGetIndex = my_index_sub(mIndex, aOffset, mSize);

   // Return array value at index
   return mArray[tGetIndex];
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

double SerialHeaderBuffer::getLeft()
{
   // Guard
   if (!mValid) return 0.0;

   // Return array value at index
   return mArray[mIndex];
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

double SerialHeaderBuffer::getRight()
{
   // Guard
   if (!mValid) return 0.0;

   // Get index of right end
   int tGetIndex = my_index_sub(mIndex, (mSize - 1), mSize);

   // Return array value at index
   return mArray[tGetIndex];
}


//******************************************************************************
//******************************************************************************
//******************************************************************************

void SerialHeaderBuffer::show()
{
   printf("SerialHeaderBuffer:                   %3d %8.3f $$",mIndex,mX);
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

