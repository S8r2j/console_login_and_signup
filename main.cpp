#include <iostream>
#include <mysql.h>
#include <sstream>
#include <cstring>
#include <windows.h>

using namespace std;

class logindata{
private:
    string username;
    string password;
    string repassword;
    string phone;
    string email;
    stringstream ss;
public:
    void getdata(MYSQL* conn)
    {
    	int qstate=0;
        cout<<"\n\t\t\tEnter your full name:\t";
        getline(cin>>ws,username);
        cout<<"\n";
        cout<<"\t\t\tEnter password:\t";
        getline(cin>>ws,password);
        cout<<"\n";
        cout<<"\t\t\tRe-enter your password to confirm:\t";
        getline(cin>>ws,repassword);
        while(repassword!=password)
        {
            cout<<"\t\t\tPassword didn't match!\n";
            cout<<"\t\t\tRe-enter your password to confirm:\t";
            getline(cin>>ws,repassword);
            cout<<"\n";
        }
        cout<<"\n\t\t\tEnter your phone number:\t";
        getline(cin>>ws,phone);
        cout<<"\n\t\t\tEnter your email address:\t";
        getline(cin>>ws,email);
        int x=2;
        while (x!=1) {
            for (int i = 0; i < email.size(); i++) {
                if (email[i] == '@') {
                    x = 1;
                    break;
                }
                x = x + 1;
            }
            if (x != 1) {
                cout << "\t\t\tEnter a valid email address!\n";
                cout << "\t\t\tEnter your email address:\t";
                getline(cin >> ws, email);
            }
        }
        ss<<"INSERT INTO user_data(Username, Password, Phone, email) VALUES('"+username+"', '"+password+"', '"+phone+"', '"+email+"')";
        string query =ss.str();
        const char* q= query.c_str();
        qstate= mysql_query(conn,q);
        if(qstate==0)
        {
        	cout<<"\t\t\tYou are registered!!!\n";
		}
		else
		{
			cout<<"\t\t\tRegistration incomplete!!!\n";
		}
    }
    void logincheck(MYSQL* conn)
    {
    	MYSQL_RES* res;
    	MYSQL_ROW row;
        cout<<"\n\t\t\tEnter username:\t";
        getline(cin>>ws,username);
        cout<<"\n";
        cout<<"\t\t\tEnter password:\t";
        getline(cin>>ws,password);
        cout<<"\n";
        ss<<"SELECT* FROM user_data WHERE Username='"+username+"' AND Password='"+password+"'";
        string query =ss.str();
        const char* q= query.c_str();
       	mysql_query(conn,q);
       	res=mysql_store_result(conn);
       	int count= mysql_num_fields(res);
       	my_ulonglong x= mysql_num_rows(res);
        if(x>=1)
        {
        	cout<<"\t\t\tYou are logged in successfully\n";
		}
		else
		{
			cout<<"\t\t\tUsername or Password is incorrect!\n";
		}
    }
};

int main() {
	
	MYSQL* conn;
	conn=mysql_init(0);
	conn=mysql_real_connect(conn,"localhost","root","","login",3306,NULL,0);
	if(conn)
	{
		cout<<"connection successful"<<endl;
	}
	else{
		cout<<"Not connected"<<endl;
	}
	logindata ld;
	char choice;
	cout<<"\t\t\tDo you want to register or login?(r or l)\t";
	cin>>choice;
	if(choice=='r')
	{
		ld.getdata(conn);
	}
	else if(choice=='l')
	{
		ld.logincheck(conn);
	}
	else
	{
		cout<<"Selected option invalid\n";
	}
	return 0;
}
