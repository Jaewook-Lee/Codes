/*****************************************************************************
 * 이름 : 이재욱
 * 학번 : 20181670
 * 숙제 번호 : HW #2
 * 설명 : 이 프로그램은 과제 수행을 위해 작성됐습니다.
 *        이 프로그램은 목적은 데이터 파일을 읽어서 얻은 수식을 출력하고
 *        수식을 postfix형태로 변환해 그 수식을 출력한 후
 *        계산의 결과를 출력하는 것입니다.
 * 알고리즘 : 'infix-to-postfix algorithm' & 'postfix evaluation algorithm'을 사용합니다.
 *           'char3-Stack and Queue.pdf'의 7~9번 슬라이드에 적혀 있습니다.
 * 함수들 :
 *     main() : 데이터 한 줄 씩 읽어 출력한 후, postfix형태로 바뀐 수식을 출력하고
 *              계산 결과도 출력합니다.
 *     postfix() : 한 줄의 식을 인자로 받아 postfix 형태로 바꿉니다.
 *                 postfix 형태의 문자열을 반환합니다.
 *     eval() : postfix 형태의 식을 인자로 받아 식의 연산을 통해 결과를 얻어냅니다.
 *              이 함수는 결과 값을 반환합나다.
 * **************************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;

string postfix(string expression);
int eval(string pf_expression);

/**********************************************************************************
 * 함수 : main
 * 설명 : 수식들이 담긴 "echo.txt" 파일을 읽어 세 가지를 출력합니다.
 *     1. 원래 수식 (infix 형태)
 *     2. 변형된 수식 (postfix 형태)
 *     3. 수식의 연산 결과
 * 변수들 :
 *     reader : 파일의 식들을 읽기 위해 사용되는 변수
 *     buffer : reader를 통해 얻어온 식을 저장하기 위해 사용되는 변수
 *     expression : buffer의 내용을 바탕으로 만든 문자열이 저장되는 변수
 *                  처음은 원래의 식이 담겨 있고 나중에는 변형된 식이 담겨 있습니다.
 *     result : 식의 연산 결과를 저장하기 위해 사용되는 변수
 * ********************************************************************************/
int main()
{
    ifstream reader;
    reader.open("echo.txt"); // echo.txt 파일에 infix 식들이 있습니다.
    char buffer[80];
    while (reader.getline(buffer, 80))
    {
        cout << "1) Echo data (infix form) : " << buffer << endl;

        string expression(buffer);
        string pf_exp(postfix(expression));

        cout << "2) Conversion (postfix form) : " << pf_exp << endl;

        int result = eval(pf_exp);

        cout << "3) Result : " << result << endl;

        cout << "---------------------------------------------------" << endl;
    }
    reader.close();
}

/*****************************************************************************
 * 함수 : postfix
 * 설명 : infix 형태의 식 한 줄을 인자로 받아 postfix 형태의 식으로 변환합니다.
 *        문자열을 반환합니다.
 * 변수들 :
 * ***************************************************************************/
string postfix(const string exp)
{
    stack<char> operators;
    string postfix_expression;
    for (int i=0; i<exp.length(); i++)
    {
        if (48 <= (int)exp[i] && (int)exp[i] <= 57) // (int)'0' = 48, (int)'1' = 49, ...
        {
            postfix_expression += exp[i];
        }
        else if (exp[i] == '(')
        {
            operators.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            
        }
        else
        {
            if ()
            {

            }
            else
            {
                
            }
            
        }
        
    }

    return postfix_expression;
}

/*****************************************************************************
 * 함수 : eval
 * 설명 : postfix 형태의 식 한 줄을 인자로 받아 식의 연산을 통해 결과를 구합니다.
 *        결과 값을 반환합니다.
 * 변수들 :
 * ***************************************************************************/
int eval(string pf_exp)
{

}