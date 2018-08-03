#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string.h>
using namespace std;
struct node
{
	char  sym;
	char datatype[10];
	int len;
	int addr;
};
int main()
{
	ifstream f;
	f.open("/root/f1.txt");
	char *token;
	//char *prev;
	char s1[100];
	char key[3][10]={"main","int","float"};
	struct node s;
	list<struct node>ll;
	list<node>::iterator it;
	int add=2000;
	int flag=0;
	while(f)
	{
		f.getline(s1,100);
		token=strtok(s1,")(;} {");
		while(token!=NULL)
		{
			flag=0;
			//cout<<token<<endl;
			for(int i=0;i<3;i++)
			{
				if(strcmp(key[i],token)==0)
				{
					flag=1;
					if(strcmp(token,"int")==0)
					{
						strcpy(s.datatype,token);
						s.len=2;
						s.addr=add;
					}
					
					if(strcmp(token,"float")==0)
					{
						strcpy(s.datatype,token);
						s.len=4;
						s.addr=add;
					}
				}	
			}
			cout<<flag<<endl;
			if(flag==0 && isalpha(token[0]))
			{
				s.sym=token[0];
				//cout<<"hi"<<s.sym<<endl;
			}
			add+=s.len;
			ll.push_back(s);
			token=strtok(NULL,")(;} {");
		}	
	}
	 for(it=ll.begin();it!=ll.end();it++)
	 {
            cout<<(*it).sym<<" "<<(*it).datatype<<" "<<(*it).len<<" "<<(*it).addr<<endl;}
}
