#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
int step = 1;
void showStep(int disk,int barPosition){
    cout<<"Step "<<step<<": Disk "<<disk+1<<" goes to bar "<<barPosition + 1<<endl;
    step++;
}

int main()
{
    int bar, position;
    cout << "Enter the number of bars: ";
    cin >> bar;
    cout << "Enter the position of the bar where you want to place: ";
    cin >> position;
    position = position - 1;
    stack<int> S[bar];
    for (int i = bar-1; i >= 0; i--)
    {
        S[0].push(i);
    }
    //Start shuffling
    //The first disk will goes to the bar where we want to get the disks at the end
    S[0].pop();
    showStep(0,position);
    for (int i = 1; i < bar; i++)
    {
        if (i == position)
        {
            S[i].push(0);
            continue;
        }
        S[i].push(S[0].top());
        showStep(S[0].top(),i);
        S[0].pop();
    }

    //for creating the base where the last disk is on the choosen bar
    for (int i = 1; i < bar; i++)
    {
        if (S[i].top() == 1)
        {
            
            S[position].pop();
            S[i].push(0);
            showStep(0,i);
            S[position].push(S[0].top());
            showStep(S[0].top(),position);
            S[0].pop();
        }
    }


    while (true)
    {
        int rDisk;
        bool isFound = false;
        if (S[position].top() == 0)
        {
            break;
        }
        else
        {
            rDisk = S[position].top() - 1;  //next small disk after the last placed disk
        }

        //find the next small disk and place it above the last disk
        for (int i = 0; i < bar; i++)
        {
            if (!S[i].empty())
            {
                if (S[i].top() == rDisk)
                {
                    S[position].push(S[i].top());
                    showStep(S[i].top(),position);
                    S[i].pop();
                    isFound = true;
                    break;
                }
            }
        }
        //if there is no immidiate small disk then find the next small disk and place it in a empty bar
        if (!isFound)  //
        {
            rDisk--;
            int nextValPos = 0;
            for (int j = 0; j < bar; j++)  //Loop for finding the next small disk after immidiate small disk
            {
                if (!S[j].empty())
                {
                    if (S[j].top() == rDisk)
                    {
                        nextValPos = j;
                    }
                }
            }
            for (int j = 0; j < bar; j++)  //loop for finding a empty bar and place the founded disk from the above loop
            {
                if (S[j].empty())
                {
                    S[j].push(S[nextValPos].top());
                    showStep(S[nextValPos].top(),j);
                    S[nextValPos].pop();
                    break;
                }
            }
        }
    }
}
