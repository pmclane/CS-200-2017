#ifndef _QUESTION_HPP
#define _QUESTION_HPP

#include <string>
#include <iostream>
using namespace std;

class Question
{
    protected:
        string m_questionText;

    public:
        void Display();

        void SetQuestionText(string text);
        string SetCapitalization(string text);

};

class TrueFalseQuestion : public Question
{
    private:
        string m_correctAnswer;

    public:
        void Display();
        void SetCorrectAnswer(string correctAnswer);
        bool CheckAnswer(string userAnswer);


};

class MultipleChoiceQuestion : public Question
{
private:
    string m_answers[4];
    int m_correctAnswer;

public:
    void Display();
    void SetAnswerChoices( string a, string b, string c, string d);
    void SetCorrectAnswer( int correctAnswer);
    bool CheckAnswer( int userAnswer);

};

#endif
