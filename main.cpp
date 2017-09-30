#include <bits/stdc++.h>


using namespace std;
vector<string>sett[1000];
string Universe[1000];
int no;
int Universe_size=0;
void Union()
{
    cout<<"Enter the ID of the sets\n";
    int A,B,u;
    cin>>A>>B;
    u=sett[A].size();
    string output[10000];
    for(int i=0; i<sett[A].size(); i++)
        output[i]=sett[A][i];
    for(int i=0; i<sett[B].size(); i++)
    {
        string word=sett[B][i];
        int flag=0;
        for(int j=0; j<u; j++)
        {
            if(output[j]==word)
            {
                flag=1;
                break;

            }
        }

        if(!flag)
        {

            output[u]=word;

            u++;
        }
    }
    cout << "answer : { ";
    for(int i=0; i<u; i++)
    {
        cout<<output[i];
        if(i!=u-1)  cout << ", ";
    }
    cout<<" }\n";
}
void Intersection()
{
    cout<<"Enter the ID of the Sets\n";
    int A,B;
    cin>>A>>B;
    string output[10000];
    int u=0;
    for(int i=0; i<sett[B].size(); i++)
    {
        string word=sett[B][i];
        for(int j=0; j<sett[A].size(); j++)
        {
            if(sett[A][j]==word)
            {
                output[u]=word;
                u++;
                break;
            }
        }
    }
        cout << "answer : { ";
    for(int i=0; i<u; i++)
    {
        cout<<output[i];
        if(i!=u-1)  cout << ", ";

    }
    cout<<" }\n";

}
/*void Difference()
{
    cout<<"Enter the ID of the Sets\n";
    int A,B;
    cin>>A>>B;
    pair< string,bool> output[10000];
    int u=sett[A].size();
    for(int i=0; i<sett[A].size(); i++)
        output[i]=make_pair(sett[A][i],1);
    for(int i=0; i<sett[B].size(); i++)
    {
        string word=sett[B][i];
        int flag=0;
        for(int j=0; j<u; j++)
        {
            if(output[j].first==word)
            {
                output[i]=make_pair(word,0);
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            output[u]=make_pair(word,1);
            u++;
        }

    }
    cout << "answer : { ";
    for(int i=0; i<u; i++)
    {
        if(output[i].second)
            cout<<output[i].first;
            if(i!=u-1)  cout << ", ";
    }
    cout<<" }\n";

}*/
void complement()
{

    cout<<"Enter the ID of the Sset\n";
    int A;
    cin>>A;
    string output[10000];
    int u=0;

    for(int i=0; i<Universe_size; i++)
    {

        string word=Universe[i];
        int flag=0;
        for(int z=0; z<sett[A].size(); z++)
        {
            if(sett[A][z]==word)
            {
                flag=1;
                break;

            }
        }

        if(!flag)
        {

            output[u]=word;

            u++;
        }

    }
        cout << "answer : { ";
    for(int i=0; i<u; i++)
    {
        cout<<output[i];
        if(i!=u-1)  cout << ", ";
    }
    cout<<" }\n";




}
int main()
{
    cout << ":: Set Operations Simulator ::\n\n";
    cout << "Please enter the number of elements of Universe\n";
    cin >> Universe_size;

    cout << "Please enter the Universe elements separated by a space ( elements are " << Universe_size << " )\n";
    for(int i=0; i<Universe_size; i++)
        cin >> Universe[i];
    cout<<"Please enter the number of sets\n";
    cin>>no;

    for(int i=0; i<no; i++)
    {
        int no_elements;
        cout<<"Please enter the number of elements of Set "<< i+1<<"\n";
        cin>>no_elements;
        cout<<"Please enter the elements of Set "<< i+1<<" separated by a space ( elements are " << no_elements << " )\n";

        for(int j=0; j<no_elements; j++)
        {
            string word;
            cin>>word;
            sett[i+1].push_back(word);
        }
    }
    while(1)
    {
        cout << "------------------------------\n"<< endl;
        cout<<"1- Union\n2- Intersection\n3- Complement\nEnter Your Choice\n";
        int choice;
        cin>>choice;
        if(choice==1)
        {
            Union();
        }
        else if(choice==2)
        {
            Intersection();
        }
        else if(choice==3)
        {
            complement();
        }
    }
}
