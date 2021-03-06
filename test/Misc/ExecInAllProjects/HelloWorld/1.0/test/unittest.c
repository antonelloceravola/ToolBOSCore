/*
 *  Unittest
 *
 *  Copyright (C)
 *  Honda Research Institute Europe GmbH
 *  Carl-Legien-Str. 30
 *  63073 Offenbach/Main
 *  Germany
 *
 *  UNPUBLISHED PROPRIETARY MATERIAL.
 *  ALL RIGHTS RESERVED.
 *
 */


/*--------------------------------------------------------------------------*/
/* Includes                                                                 */
/*--------------------------------------------------------------------------*/


#include <stdlib.h>
#include <Any.h>
#include <HelloWorld.h>
#include <CuTest.h>


/*--------------------------------------------------------------------------*/
/* HowTo                                                                    */
/*--------------------------------------------------------------------------*/
//
//  1.  Write testcase functions
//      (see examples below)
//
//  2.  List each testcase in main() function
//
//  3.  Compile package and run test program like:
//      $ RunFromSourceTree.sh ./test/\${MAKEFILE_PLATFORM}/unittest
//
//
//----------------------------------------------------------------------------
//
//
//  Assertions provided by CuTest:
//
//      CuFail( testcase, msg );
//      CuAssert( testcase, msg, cond );
//      CuAssertTrue( testcase, cond );
//
//      CuAssertStrEquals( testcase, expected, actual );
//      CuAssertStrEquals_Msg( testcase, msg, expected, actual );
//      CuAssertIntEquals( testcase, expected, actual );
//      CuAssertIntEquals_Msg( testcase, msg, expected, actual );
//      CuAssertDblEquals( testcase, expected, actual, maxDelta );
//      CuAssertDblEquals_Msg( testcase, msg, expected, actual, maxDelta );
//      CuAssertPtrEquals( testcase, expected, actual );
//      CuAssertPtrEquals_Msg( testcase, msg, expected, actual );
//
//      CuAssertPtrNotNull( testcase, ptr );
//      CuAssertPtrNotNullMsg( testcase, msg, ptr );


/*--------------------------------------------------------------------------*/
/* Testcases                                                                */
/*--------------------------------------------------------------------------*/


void Unittest_lifecycle( CuTest *testcase )
{
    HelloWorld *data = (HelloWorld*)NULL;

    data = HelloWorld_new();
    CuAssertTrue( testcase, data != (HelloWorld*)NULL );

    /* PLEASE ADAPT:

    HelloWorld_init( data, 123 );
    CuAssertIntEquals( testcase, 123, HelloWorld_getXY( data ) );

    HelloWorld_clear( data );

    CuAssertIntEquals( testcase, 0, HelloWorld_getLength( data ) );
    CuAssertPtrEquals( testcase, 0, data->buffer );
    */

    HelloWorld_delete( data );
}


void Unittest_toString( CuTest *testcase )
{
    /* EXAMPLE FUNCTION, PLEASE ADAPT */
    ANY_LOG( 0, "Hello, World!", ANY_LOG_INFO );
}


void Unittest_getXY( CuTest *testcase )
{
    /* EXAMPLE FUNCTION, PLEASE ADAPT */
    ANY_LOG( 0, "Hello, World!", ANY_LOG_INFO );
}


/*--------------------------------------------------------------------------*/
/* Boilerplate main function                                                */
/*--------------------------------------------------------------------------*/


int main( int argc, char* argv[] )
{
    CuSuite  *suite  = CuSuiteNew();
    CuString *output = CuStringNew();

    /* TODO: list each testcase here */
    SUITE_ADD_TEST( suite, Unittest_lifecycle );
    SUITE_ADD_TEST( suite, Unittest_toString );
    SUITE_ADD_TEST( suite, Unittest_getXY );

    CuSuiteRun( suite );
    CuSuiteSummary( suite, output );
    CuSuiteDetails( suite, output );
    fprintf( stderr, "%s\n", output->buffer );

    return EXIT_SUCCESS;
}


/* EOF */
