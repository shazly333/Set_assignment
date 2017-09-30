#include <bits/stdc++.h>


using namespace std;
vector<string>sett[1000];
string Universe[1000];
int no;
void Union()
{
    cout<<"Enter The Id Of The sets\n";
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
    for(int i=0; i<u; i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<"\n";
}
void Intersection()
{
 cout<<"Enter The Id Of The sets\n";
            int A,B;
            cin>>A>>B;
            while(A>no||B>no)
            {
                cout<<"Enter The Id Of The sets\n";
                int A,B;
                cin>>A>>B;

            }
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
            for(int i=0; i<u; i++)
            {
                cout<<output[i]<<" ";

            }
            cout<<"\n";

}
void Difference()
{
     cout<<"Enter The Id Of The sets\n";
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

            for(int i=0; i<u; i++)
            {
                if(output[i].second)
                    cout<<output[i].first<<" ";
            }
            cout<<"\n";

}
int main()
{
    cout<<"Please Enter The Number Of Elements Of Universe\n";
    int x;
    cin>>x;

    cout<<"Please Enter The Universe\n";
    for(int i=0; i<x; i++)
    cin>>Universe[i];
    cout<<"Please Enter The Number Of Sets\n";
    cin>>no;

    for(int i=0; i<no; i++)
    {
        int no_elements;
        cout<<"Please Enter The Number Of Elements\n";
        cin>>no_elements;
        cout<<"Please Enter The Elements\n";

        for(int j=0; j<no_elements; j++)
        {
            string word;
            cin>>word;
            sett[i+1].push_back(word);
        }
    }
    while(1)
    {
        cout<<"1-Union\n2-Intersection\n3-Difference\nEnter Your Choice\n";
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
           Difference();
        }

    }
}
