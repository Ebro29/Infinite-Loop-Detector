//*********************************************************
//
// Includes and Defines
//
//*********************************************************
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <cstdlib>

using namespace std;


//*********************************************************
//
// Signal Handler Functions
//
//*********************************************************
void handle_cc( int signo )
{
  cout << "Ctrl-C Detected" << endl;
  cout.flush();
}

void handle_alarm( int siggno )
{
  cout << "Alarm!!!!" << endl;
  cout.flush();
}


//*********************************************************
//
// Main Function
//
//*********************************************************
int main( int argc, char *argv[] )
{


  // initialize signal handlers
  signal( SIGINT, SIG_IGN );
  signal( SIGINT, handle_cc );
  signal( SIGALRM, SIG_IGN );
  signal( SIGALRM, handle_alarm );
he   alarm( 5 );

  // main (infinite) loop
  while( true );

  // return to calling environment
  return( 0 );
}
