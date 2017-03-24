#include <iostream>


using namespace std;
void ReplaceBlank(char string[],int length);

int main()
{
    char str[100] = "We are happy.";
    ReplaceBlank(str,100);
    cout << str << endl;
    return 0;
}

void ReplaceBlank(char string[],int length)
{
    if(string == NULL||length <= 0)
        return;
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(string[i]!='\0')
    {
        ++originalLength;
        if(string[i] == ' ')
            ++numberOfBlank;
        ++i;
    }
    int newLength = originalLength + 2*numberOfBlank;
    if(newLength > length)
        return;
    int indexOfOriginal = originalLength;
    int indexOfnew = newLength;
    while(indexOfOriginal >= 0 && indexOfnew > indexOfOriginal)
    {
        if(string[indexOfOriginal] == ' ')
        {
            string[indexOfnew --] = '0';
            string[indexOfnew --] = '2';
            string[indexOfnew --] = '%';
        }
        else
            string[indexOfnew --] = string[indexOfOriginal];

        --indexOfOriginal;
    }
}
