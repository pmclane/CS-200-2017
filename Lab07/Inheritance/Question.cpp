#include "Question.hpp"

///Normalize capitalization
///Side thought: I could include a library to do this, but I don't have a good sense of if it's better to rewrite a few functions (toupper and tolower) or use a library
///for that code.
string Question::SetCapitalization(string text)
{
    if ( text.empty() )
    {
        return text;
    }
    else
    {
        if ( text[0] >= 97 )
        {
            text[0] -= 32;
        }
        for (int i = 1; i < text.size(); i++)
        {
            if ( text[i] < 97 )
            {
                text[i] += 32;
            }
        }

        return text;
    }
}
///QUESTION FUNCTIONS

void Question::SetQuestionText(string text)
{
    m_questionText = text;
}

void Question::Display()
{
    cout << m_questionText << endl;
}

///TRUE FALSE QUESTION FUNCTIONS
void TrueFalseQuestion::Display()
{
    Question::Display();
    cout << "True or False? ";
}

void TrueFalseQuestion::SetCorrectAnswer(string correctAnswer)
{
    m_correctAnswer = SetCapitalization(correctAnswer);
}

bool TrueFalseQuestion::CheckAnswer(string userAnswer)
{
    userAnswer = SetCapitalization( userAnswer );

    return (userAnswer == m_correctAnswer);
}

///MULTIPLE CHOICE QUESTION FUNCTIONS
void MultipleChoiceQuestion::Display()
{
    Question::Display();

    for (int i = 0; i < 4; i++)
    {
        cout << i << ". " << m_answers[i] << endl;
    }
}

void MultipleChoiceQuestion::SetAnswerChoices( string a, string b, string c, string d)
{
    m_answers[0] = a;
    m_answers[1] = b;
    m_answers[2] = c;
    m_answers[3] = d;
}

void MultipleChoiceQuestion::SetCorrectAnswer( int correctAnswer)
{
    m_correctAnswer = correctAnswer;
}

bool MultipleChoiceQuestion::CheckAnswer( int userAnswer)
{
    return userAnswer == m_correctAnswer;
}
