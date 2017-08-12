#include "stdafx.h"

#include "someSerialRxThread.h"
#include "someSerialTxThread.h"

#include "MainInit.h"
#include "risCmdLineConsole.h"
#include "CmdLineExec.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

int main(int argc,char** argv)
{
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize the program.

   main_initialize(argc,argv);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Launch threads.

   Some::gSerialRxThread = new Some::SerialRxThread();
   Some::gSerialRxThread->configure(5,"38400,N,8,1",4000);
   Some::gSerialRxThread->launchThread();

   Some::gSerialTxThread = new Some::SerialTxThread();
   Some::gSerialTxThread->configure(6,"38400,N,8,1",0);
   Some::gSerialTxThread->launchThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Run the user command line executive, it returns when the user exits.

   CmdLineExec* tExec = new CmdLineExec;
   Ris::gCmdLineConsole.execute(tExec);
   delete tExec;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Shutdown threads.

   Some::gSerialTxThread->shutdownThread();
   Some::gSerialRxThread->shutdownThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Finalize the program.

   main_finalize();
   return 0;
}