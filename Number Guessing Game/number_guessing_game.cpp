//number_guessing_game.cpp
//Baran Buğday
//07.12.2021
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;
const int min_value = 1023;
const int max_value = 9876;
int digit_check(int x)
{
    int digits [4];
    for (int i = 3; i >= 0; i--)
    {
        digits[i] = x % 10;
        x /= 10;
    }
    if (digits[0] != digits[1] && digits[0] != digits[2] && digits[0] != digits[3] && digits[1] != digits[2] && digits[1] != digits[3] && digits[2] != digits[3])
    {
    return 1;
    }
    else
    {
        return 0;
    }
}
int guess_check(int m)
{
    while(m < 1023 || m > 9876 || digit_check(m) != 1)
    {
        cout << "Please enter a valid number consisting of different digits within the boundaries. [1023, 9876] : ";
        cin >> m;
    }
    return m;
}
int comparison(int user_value, int system_value)
{
     int user_digits [4];
    for (int i = 3; i >= 0; i--)
    {
        user_digits[i] = user_value % 10;
        user_value /= 10;
    }
     int system_digits [4];
    for (int i = 3; i >= 0; i--)
    {
        system_digits[i] = system_value % 10;
        system_value /= 10;
    }
    int right_place = 0;
    int wrong_place = 0;
    for (int i=0; i<=3; i++)
    {
        for (int n=0; n<=3; n++)
        {
            if (i == n)
            {if (user_digits[i] == system_digits[n])
                {right_place++;}
                else
                {continue;}}
            else
            {if (user_digits[i] == system_digits[n])
                {wrong_place++;}
                else
                {continue;}}
        }
    } 
if (right_place != 0 && wrong_place != 0)
{
    cout << right_place << "+ " << wrong_place << "- " <<endl;
}
else if (right_place == 0 && wrong_place != 0)
{
    cout << wrong_place << "- " << endl; 
}
else if (right_place !=0  && wrong_place == 0)
{
    cout << right_place << "+ " << endl;
    if (right_place == 4)
    {
        return 1;
    }
}
else
{
    cout << "0" << endl;
}
return 0;
}
int main()
{
    int result = 0;
    int trials = 0;
    int digits[4] = {0};
    unsigned seed = time(0);
    srand(seed);
    int random_number = (rand() % (max_value - min_value + 1)) + min_value;
    while (digit_check(random_number) != 1)
    {
        random_number = (rand() % (max_value - min_value + 1)) + min_value;
    }
    cout << "Welcome to the number guessing game.\n";
    cout << "Please enter a number between the values [1023, 9876] : ";
    int guess;
    cin >> guess;
	guess_check(guess);
    while ( guess != random_number)
        {
            result = comparison(guess, random_number);
            if (result == 1)
            {
                break;
            }
            cout << "Enter a 4 digit number: ";
            cin >> guess;
            guess = guess_check(guess);
            trials++;
        }
        cout  <<" You have found the answer in " << trials+1 << " trials. Well done.\n";
    return 0;
}
