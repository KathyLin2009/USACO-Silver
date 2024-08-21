#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    int N, Q, temp;
    vector<int> cow_breeds, breed1, breed2, breed3;
    ifstream file("prefix_sum/bcount.in");
    file >> N >> Q;
    file >> temp;
    cow_breeds.push_back(temp);
    
    if(cow_breeds[0] = 1)
    {
        breed1.push_back(1);
        breed2.push_back(0);
        breed3.push_back(0);
    }
    else if(cow_breeds[0] = 2)
    {
        breed1.push_back(0);
        breed2.push_back(1);
        breed3.push_back(0);
    }
    else 
    {
        breed1.push_back(0);
        breed2.push_back(0);
        breed3.push_back(1);
    }



    for(int i = 1; i <= N; i++)
    {
        file >> temp;
        cow_breeds.push_back(temp);
        if(cow_breeds[i] = 1)
        {
            breed1.push_back(1 + breed1[i - 1]);
            breed2.push_back(0 + breed2[i - 1]);
            breed3.push_back(0 + breed3[i - 1]);
        }
        else if(cow_breeds[i] = 2)
        {
            breed1.push_back(0 + breed1[i - 1]);
            breed2.push_back(1 + breed2[i - 1]);
            breed3.push_back(0 + breed3[i - 1]);
        }
        else 
        {
            breed1.push_back(0 + breed1[i - 1]);
            breed2.push_back(0 + breed2[i - 1]);
            breed3.push_back(1 + breed3[i - 1]);
        }

        for(int j = 0; j < breed1.size(); j++)
        {
            cout << breed1[j] << " ";
        }
        cout << endl;
        for(int x = 0; x < breed2.size(); x++)
        {
            cout << breed2[x] << " ";
        }
        cout << endl;
        for(int y = 0; y < breed3.size(); y++)
        {
            cout << breed3[y] << " ";
        }
    }


}