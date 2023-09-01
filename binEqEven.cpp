//Program to display first n decimal number with binary eqivalent containing even number of 1's
#include <iostream>
using namespace std;

int main()
{
    int n,rem,k=0;;
    cout << "Enter the n numbers:";
    cin >> n;
    for (int i = 0; i <n; i++)
    {
        
        while(true){
                int j=k;
                int count=0;
                rem=0;
                while(j!=0){
                        rem=j%2;
                        if(rem==1)
                                count++;
                        j=j/2;
                }
                k++;
                if(count%2==0){
                        cout<<k-1<<" ";
                        break;
                }
        }
    }
    return 0;
}

