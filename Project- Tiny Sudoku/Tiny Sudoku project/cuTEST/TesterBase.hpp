#ifndef _TESTER_BASE_HPP
#define _TESTER_BASE_HPP

#include <string>
#include <list>
#include <vector>
#include <functional>
#include <fstream>
using namespace std;

struct TestListItem;

class TesterBase
{
	public:
	TesterBase();
	virtual ~TesterBase();

	void Start();
	void AddTest( const TestListItem& test );

	protected:
	void MainMenu();
	void TestAll();
	void DisplayPrerequisites( const vector<string>& prereqs );
	void ReportFailure( const string& test, const string& message, const string& expected, const string& actual );
	void ReportFailure( const string& test, const string& message, int expected, int actual );
	void ReportFailure( const string& test, const string& message, float expected, float actual );
	void ReportFailure( const string& test, const string& message );
	void ReportFailure( const string& message );
	void ReportPass();
	void DisplayTestHeader( const string& test );
	void DisplayTestHeader( const string& test,  const vector<string>& prereqs  );
	void DisplayScore( int totalPasses, int totalTests );
	void DisplayScore();

	list<TestListItem> m_tests;
	int m_totalTestCount;

    // Per test...:
	void InitTest( const string& name, const vector<string>& prereqs );
	void StartTest( const string& description );
	void AdditionalDescription( const string& description );
	void TestFail();
	void TestPass();
	int TestResult();

	int m_subtest_totalTests;
	int m_subtest_totalPasses;
	string m_subtest_name;

	ofstream m_output;
	ofstream m_testOutput;
};

struct TestListItem
{
	string name;
	bool testAggregate;
	function<int()> callFunction;


	TestListItem()
	{
        testAggregate = false;
	}

	TestListItem( const string name, function<int()> callFunction, bool testAggregate = false )
	{
		Setup( name, callFunction, testAggregate );
	}

	void Setup( const string& name, function<int()> callFunction, bool testAggregate = false )
	{
		this->name = name;
		this->callFunction = callFunction;
		this->testAggregate = testAggregate;
	}
};

#endif
