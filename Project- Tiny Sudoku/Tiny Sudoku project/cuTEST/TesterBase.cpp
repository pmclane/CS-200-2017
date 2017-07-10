#include "TesterBase.hpp"
#include "Menu.hpp"
#include "StringUtil.hpp"

TesterBase::TesterBase()
{
	m_totalTestCount = 0;
	m_output.open( "test_result.txt" );
}

TesterBase::~TesterBase()
{
    m_output.close();
}

void TesterBase::Start()
{
//	MainMenu();
    TestAll();
}

void TesterBase::MainMenu()
{
	vector<string> options;
	vector<TestListItem*> ptrTests;
    for ( list<TestListItem>::iterator it = m_tests.begin(); it != m_tests.end(); it++ )
    {
        options.push_back( it->name );
        ptrTests.push_back( &(*it) );
    }
	options.push_back( "Exit" );

    int exitOption = options.size();


	bool done = false;
	while ( !done )
	{
		Menu::ClearScreen();
		Menu::DisplayHeader( "cuTEST Main Menu" );
		Menu::DisplayNumericMenu( options );

		// 1. Test all (test 0)
		// 2. Test1 (test 1)
		// 3. Quit

		int choice = Menu::GetNumberChoice( 1, exitOption );

		if ( choice == exitOption )
		{
            // Quit
			done = true;
		}
		else
		{
            // Run test
            int adjustedIndex = choice - 1;
            ptrTests[adjustedIndex]->callFunction();
            Menu::Pause();
		}
	}
}

void TesterBase::TestAll()
{
    m_output << endl << "RUN ALL TESTS" << endl;

    for ( list<TestListItem>::iterator it = m_tests.begin(); it != m_tests.end(); it++ )
    {
        if ( it->testAggregate == false )
        {
            it->callFunction();
        }
    }
}

void TesterBase::DisplayPrerequisites( const vector<string>& prereqs )
{
    m_output << "PREREQUISITE FUNCTIONS: ";
    m_testOutput << "PREREQUISITE FUNCTIONS: ";
    for ( unsigned int i = 0; i < prereqs.size(); i++ )
    {
        if ( i != 0 ) { m_output << ", "; }
        m_output << prereqs[i];
        m_testOutput << prereqs[i];
    }
    m_output << endl;
    m_testOutput << endl;
}

void TesterBase::AddTest( const TestListItem& test )
{
	m_tests.push_back( test );
	m_totalTestCount++;
}

void TesterBase::ReportFailure(const string& test, const string& message, const string& expected, const string& actual)
{
	m_output << endl << "TEST FAILED: " << test << endl
		<< message << endl
		<< "\t EXPECTED OUTPUT: " << expected << endl
		<< "\t ACTUAL OUTPUT:   " << actual << endl << endl;

	m_testOutput << endl << "TEST FAILED: " << test << endl
		<< message << endl
		<< "\t EXPECTED OUTPUT: " << expected << endl
		<< "\t ACTUAL OUTPUT:   " << actual << endl << endl;
}

void TesterBase::ReportFailure( const string& test, const string& message, int expected, int actual )
{
    ReportFailure( test, message, StringUtil::ToString( expected ), StringUtil::ToString( actual ) );
}

void TesterBase::ReportFailure( const string& test, const string& message, float expected, float actual )
{
    ReportFailure( test, message, StringUtil::ToString( expected ), StringUtil::ToString( actual ) );
}

void TesterBase::ReportFailure( const string& test, const string& message )
{
    m_output << endl << "(Test " << m_subtest_totalTests << " FAILED) \t" << test << "\n"
        << message << endl << endl;

    m_testOutput << endl << "(Test " << m_subtest_totalTests << " FAILED) \t" << test << "\n"
        << message << endl << endl;
}

void TesterBase::ReportFailure( const string& message )
{
    ReportFailure( m_subtest_name, message );
}

void TesterBase::ReportPass()
{
    m_output << endl << "(Test " << m_subtest_totalTests << " PASSED)" << endl << endl;

    m_testOutput << endl << "(Test " << m_subtest_totalTests << " PASSED)" << endl << endl;
}

void TesterBase::DisplayTestHeader( const string& test )
{
    Menu::ClearScreen();

    m_output << endl;
    m_testOutput << endl;

    Menu::DisplayHeader( m_output, test );
    m_subtest_name = test;
}

void TesterBase::DisplayTestHeader( const string& test,  const vector<string>& prereqs  )
{
    Menu::ClearScreen();
    Menu::DisplayHorizontalRule( m_output, 80, '*' );
    Menu::DisplayHorizontalRule( m_testOutput, 80, '*' );

    m_output << "TEST SET: " << test << endl;
    m_testOutput << "TEST SET: " << test << endl;

    DisplayPrerequisites( prereqs );
    Menu::DisplayHorizontalRule( m_output, 80, '*' );
    Menu::DisplayHorizontalRule( m_testOutput, 80, '*' );
    m_subtest_name = test;
}

void TesterBase::DisplayScore( int totalPasses, int totalTests )
{
    m_output << endl;
    m_testOutput << endl;

    if ( totalPasses == totalTests )
    {
        m_output << "(PASS) ";
        m_testOutput << "(PASS) ";
    }
    else
    {
        m_output << "(FAIL) ";
        m_testOutput << "(FAIL) ";
    }

    m_output << totalPasses << " passed out of " << totalTests << " tests" << endl;
    m_testOutput << totalPasses << " passed out of " << totalTests << " tests" << endl;
}

void TesterBase::DisplayScore()
{
    DisplayScore( m_subtest_totalPasses, m_subtest_totalTests );
}

void TesterBase::InitTest( const string& name, const vector<string>& prereqs )
{
    if ( m_testOutput.is_open() )
    {
        m_testOutput.close();
    }

    m_testOutput.open( "TEST_RESULTS/" + name + ".txt" );

    m_output << endl << endl;
    m_testOutput << endl << endl;

    DisplayTestHeader( name, prereqs );
    m_subtest_totalTests = 0;
    m_subtest_totalPasses = 0;
}

void TesterBase::StartTest( const string& description )
{
    m_subtest_totalTests++;
    // Outputting this just clutters stuff up.
    m_output << endl;
    m_testOutput << endl;

    Menu::DisplayHorizontalRule( m_output, 80, '-' );
    Menu::DisplayHorizontalRule( m_testOutput, 80, '-' );

    m_output << "Test " << m_subtest_totalTests << ": \t" << description << endl;
    m_testOutput << "Test " << m_subtest_totalTests << ": \t" << description << endl;

    Menu::DisplayHorizontalRule( m_output, 80, '-' );
    Menu::DisplayHorizontalRule( m_testOutput, 80, '-' );
}

void TesterBase::AdditionalDescription( const string& description )
{
    m_output << "\t" << description << endl;
    m_testOutput << "\t" << description << endl;
}

void TesterBase::TestFail()
{
}

void TesterBase::TestPass()
{
    m_subtest_totalPasses++;
}

int TesterBase::TestResult()
{
    return ( m_subtest_totalPasses == m_subtest_totalTests );
}
