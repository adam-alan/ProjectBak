#include <iostream>

#include <stack>

#include <string>

using namespace std;



int main(){

    string num("abcdefghij");

    string weight("SBQWSBQY");

    int input_num = 0;

    scanf("%d",&input_num);

    stack<int> stk;



    do {

        stk.push(input_num % 10);

        input_num /= 10;

    } while (input_num != 0);

    

    int i = stk.size() - 2;

    int number = 0;

    

    if (stk.size() == 1){

        printf("%c\n",num[stk.top()]);

        stk.pop();

        return 0;

    }

    

    

    while (!stk.empty()){

        //printf("%d",stk.top());

        number = stk.top();

        stk.pop();

        if ( number != 0){

            printf("%c",num[number]);

            printf("%c",weight[i]);

        } else {

            if (!stk.empty()){

                int n = stk.top();

                if (n != 0){

                    printf("%c",num[number]);

                }

            }

        }

        i -= 1;        

    }

    printf("\n");

    return 0;

}