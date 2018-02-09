#include<iostream>
#include<cstring>
using namespace std;
class my_string
{
char *str;

public:	
	my_string()/*default constructor*/
	{
	}
	my_string(const char* arg)/*parameterised constructor*/
	{
	this->str=new char[strlen(arg)+1];
	strcpy(this->str,arg);
	}
	my_string(my_string &obj)/*copy constructor*/
	{
	this->str=new char[strlen(obj.str)+1];
	strcpy(this->str,obj.str);
	}
	void operator =(const char *arg)/*operator = overloading*/
	{
	this->str=new char[strlen(arg)+1];
	strcpy(this->str,arg);
	}
	my_string operator +(const my_string &obj)/*operator + overloading*/
	{
	my_string ret;
	ret.str=new char[strlen(this->str)+strlen(obj.str)+1];
	strcpy(ret.str,this->str);
	strcat(ret.str,obj.str);
	return ret;
	}
	bool operator <(my_string &obj)/*operator < overloading*/
	{
	if(strcmp(this->str,obj.str)<0)
	return true;
	else return false;
	}
	bool operator >(my_string &obj)/*operator > overloading*/
	{
	if(strcmp(this->str,obj.str)>0)
	return true;
	else return false;
	}
	bool operator <=(my_string &obj)/*operator <= overloading*/
	{
	if(strcmp(this->str,obj.str)<=0)
	return true;
	else return false;
	}
	bool operator >=(my_string &obj)/*operator >= overloading*/
	{
	if(strcmp(this->str,obj.str)>=0)
	return true;
	else return false;
	}
	bool operator ==(my_string &obj)/*operator == overloading*/
	{
	if(strcmp(this->str,obj.str)==0)
	return true;
	else return false;
	}
	
	bool operator !=(my_string &obj)/*operator != overloading*/
	{
	if(strcmp(this->str,obj.str)!=0)
	return true;
	else return false;
	}
	void operator ()(my_string &obj)/*operator () overloading*/
	{
	this->str=obj.str;
	}
	char operator[](const int &i)/*operator [] overloading*/
	{
	return this->str[i];
	}
friend istream & operator>>(istream &,my_string &);
friend ostream & operator<<(ostream &,my_string &);
};
istream &operator >>(istream &in,my_string &obj)/*operator >> overloading*/
{
obj.str=new char[1000];
in>>obj.str;
return in;
};
ostream &operator<<(ostream &out,my_string &obj)/*operator << overloading*/
{
out<<obj.str;
return out;
}

main()
{
my_string s1("ANOOP"),s2,s3;
s2="DINESHAN";
my_string s4(s1);
cout<<s4<<" "<<s2<<endl;
cout<<s1<<" "<<s2<<endl;
s3=s1+s2;
cout<<"s1="<<s1<<endl<<"s2="<<s2<<endl;
cout<<"s3="<<s3<<endl;
cout<<"s1<s2 "<<(s1<s2)<<endl;
cout<<"s1>s2 "<<(s1>s2)<<endl;
s3(s1);
cout<<"s3(s1)  "<<endl;
cout<<"s3="<<s3<<endl;
cout<<"s1="<<s1<<endl;
cout<<s1[0]<<endl;
}

