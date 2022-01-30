#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string encryption(string a,int b)
{
    int i,x=0 ;
    string enc="";
    for (i=0;i<a.length() ; i++)
    {
        char c = a.at(i);
        x= int(c);
        enc = enc + char(x+b);
    }
    return enc;
}
string decryption(string a ,int b)
{
      int i,x=0 ;
    string dec="";
    for (i=0;i<a.length() ; i++)
    {
        char c = a.at(i);
        x= int(c);
        dec = dec + char(x-b);
    }
    return dec;
}
int main()
{
    string input,code,c;
    int diff;
    cout<<"enter your message "<<endl;
    getline (cin,input);//mssg to be send 
    cout<<"enter the difference"<<endl;
    cin>>diff;
    string enc =  encryption(input,diff);//encryption of the mssg takes place
    input="";
    cout<<"enter code that the reciever has to enter"<<endl;
    cin>>code;
    //at the recievers phone
    cout<<"enter the password to access the message"<<endl;
    
    int count=0;//for counting number of wrong answers
    for(int f=1;f<3;f++)
    {
        cin>>c;
         if(c==code)
        {
            cout<<"the message is "<<decryption(enc,diff)<<endl;
            break;
        }
        else
        {
            cout<<"renter your passcode"<<endl;
            count++;
        }
    }
    if (count == 2)
    {
        enc="";
        cout<<"the message has been deleted permenantly"<<endl;
        
    }
}